/*
 * Engine.cpp
 *
 *  Created on: 29 gru 2017
 *      Author: andrzej
 */

#include "../Headers/Engine.h"

Engine::Engine(RenderWindow &window,int difficulty) :
	score(0)
	{
	reset();
	next = 0;
	is_playing = true;
	if (!font1.loadFromFile("Fonts/DejaVuSerif.ttf"))
		{
			return;
		}
	for(int i=1;i<Map::COUNT; i++)
	{
		textura[i].loadFromFile("Graphics/tileset.png",IntRect((i-1)*mapa.tile_width,0,mapa.tile_width,mapa.tile_height));
	}
	float treePosX[5] = {100,100,350,700,1500};
	float treePosY[5] = {200,600,100,400,400};
	switch(difficulty)
	{
	case 1: 	mapa.loadFromFile("easy.map");
				for(int i=0;i<5;i++)
					drzewo[i].create(treePosX[i],treePosY[i]);

				break;
	case 2: 	mapa.loadFromFile("medium.map");
				for(int i=0;i<3;i++)
					drzewo[i].create(treePosX[i],treePosY[i]);

				break;
	case 3:     mapa.loadFromFile("hard.map");
				for(int i=0;i<3;i++)
					drzewo[i].create(treePosX[i],treePosY[i]);
				break;
	default: break;
	}

		for(int i=0;i<mapa.height;i++)
			for(int j=0; j<mapa.width; j++)
			{
					sprite[i][j].setTexture(textura[mapa.level[i][j].type]);
					sprite[i][j].setPosition(j*mapa.tile_width,i*mapa.tile_height);
			}
	runEngine(window,difficulty);
}

Engine::~Engine() {

}

void Engine::runEngine(RenderWindow &win,int difficulty)
{
		 info.setFont(font1);
		 info.setFillColor(Color::White);
		 info.setCharacterSize(30);
	     info.setString("Punkty : " + std::to_string(score));
	     info.setPosition((300 - info.getLocalBounds().width)/2.f,(60-info.getLocalBounds().height/2.f));
	switch (difficulty)
			{
			case 1 :
				car[0].create(Color::Red,EASY1_WIDTH,HEIGHT);

				speed = 2;
				numberOfTraps = 4;
				break;
			case 2 :
				car[0].create(Color::Red,MEDIUM1_WIDTH,HEIGHT);
				car[1].create(Color::Green,MEDIUM2_WIDTH,HEIGHT);
				speed = 3;
				numberOfTraps = 8;
				break;
			case 3:
				car[0].create(Color::Red,HARD1_WIDTH,HEIGHT);
				car[1].create(Color::Green,HARD2_WIDTH,HEIGHT);
				car[2].create(Color::Blue,HARD3_WIDTH,HEIGHT);
				speed = 4;
				numberOfTraps = 9;
				break;
			default: break;

			}

	bool menu = false;
	obstacles(win,difficulty);
	Event event;
	while(!menu)
		{
			win.clear();

			for(int i=0;i<mapa.height;i++)
				for(int j=0;j<mapa.width;j++)
						win.draw(sprite[i][j]);

			while (win.pollEvent(event))
							{
							if(event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
							menu = true;
							if(event.type == Event::KeyReleased && event.key.code == Keyboard::Left)
							car[0].moveLeft();
							if(event.type == Event::KeyReleased && event.key.code == Keyboard::Right)
							car[0].moveRight(difficulty);
						    if(event.type == Event::KeyReleased && event.key.code == Keyboard::A)
							car[1].moveLeft();
							if(event.type == Event::KeyReleased && event.key.code == Keyboard::S)
							car[1].moveRight(difficulty);
							if(event.type == Event::KeyReleased && event.key.code == Keyboard::D)
							car[2].moveLeft();
							if(event.type == Event::KeyReleased && event.key.code == Keyboard::F)
							car[2].moveRight(difficulty);

							}
				{
			if(timer.getElapsedTime().asMilliseconds()%speed==0)
						{
				int i,j;
				FloatRect carPos[difficulty],trapPos[numberOfTraps],starPos[difficulty];
				for(j=0; j<numberOfTraps; j++)
							{
										i = difficulty - 1;
										trapPos[j]=trap[j].getGlobalBounds();
										trap[j].move(0,1);
										trap[j].check(difficulty);


										for(int i=0; i<difficulty; i++)
										{
										starPos[i]=star[i].getGlobalBounds();
										carPos[i]=car[i].getGlobalBounds();
										if(trapPos[j].intersects(carPos[i]))
										{
												next = 1;
												menu = true;

										}
										if (starPos[i].intersects(trapPos[j]))
										{
											star[i].randomize(difficulty);
										}
										}
							}
							for( i=0;i<difficulty; i++)
							{
										j=i%difficulty;
										star[i].move(0,1);
										star[i].check(difficulty);
										starPos[i]=star[i].getGlobalBounds();
										if ((starPos[i].intersects(carPos[0]) || (starPos[i].intersects(carPos[1])) || (starPos[i].intersects(carPos[2]))))
										{
											score++;
											info.setString("Punkty : " + std::to_string(score));
											star[i].randomize(difficulty);
										}
							}

						}

				}
			for(int i=0;i<difficulty;i++)
				win.draw(car[i]);
			for(int i=0; i<numberOfTraps; i++)
				win.draw(trap[i]);
			for(int i=0; i<difficulty; i++)
				win.draw(star[i]);
			for(int i=0; i<5; i++)
				win.draw(drzewo[i]);
			win.draw(info);
			win.display();

}
}
void Engine::obstacles(RenderWindow &win,int dif)
{
switch(dif)
{
case 1:
	star[0].setPosition(EASY1_WIDTH,-800);
	for(int i=0; i<3; i++)
	trap[i].setPosition((EASY1_WIDTH-240) + i%4 * 120,i*220);
	break;
case 2:
{
	int positions[6]={780,900,1020,1380,1500,1620};
	for (int j=0; j<numberOfTraps; j++)
	{
		trap[j].setPosition(positions[j],j * 140);
	}
	star[0].setPosition(positions[0],-150);
	star[1].setPosition(positions[5],-300);
}
	break;
case 3:
{
	int arrNum[6] = {650,770,1240,1360,1600,1840};
	int arrNum2[3]={HARD1_WIDTH,HARD2_WIDTH,HARD3_WIDTH};

	for(int j=0; j<6; j++)
		trap[j].setPosition(arrNum[j],(j%3)*200);
	for(int i=0; i<3; i++)
		star[i].setPosition(arrNum2[i],-(i*150));

}
	break;
default: break;
}
}
void Engine::reset()
{
	score = 0;
}


