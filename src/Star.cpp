/*
 * Star.cpp
 *
 *  Created on: 4 sty 2018
 *      Author: andrzej
 */

#include "../Headers/Star.h"

Star::Star() {
	if (!texture2.loadFromFile("Graphics/star.png"))
	{
		return;
	}
	sprite2.setTexture(texture2);
	sprite2.setTextureRect(IntRect(0,0,60,60));
	sprite2.setOrigin(32,32);
	sprite2.setPosition(1800,700);
}

Star::~Star() {
	// TODO Auto-generated destructor stub
}

void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite2);
}
void Star::setPosition(float x,float y)
{
	sprite2.setPosition(x,y);
}
void Star::move(float x,float y)
{
			sprite2.move(x,y);

}
Vector2f Star::getPosition()
{
	return sprite2.getPosition();
}
FloatRect Star::getGlobalBounds() const
{
	return sprite2.getGlobalBounds();
}
void Star::randomize(int dif)
{
	int posX = sprite2.getPosition().x;
	int posY = sprite2.getPosition().y;
	srand(time(NULL));
	int RandIndex = rand() % 9;
	if(dif == 1)
	{
	const int arrNum[4]={1250,1370,1130,1010};
	sprite2.setPosition(arrNum[RandIndex%4],-250);
	}
	if(dif ==2)
	{
		int arrNum[8]={780,900,1020,1140,1380,1500,1620,1740};
		for(int i=0; i<8;i++)
		{
			if(posX == arrNum[i] && i!=7)
			sprite2.setPosition(arrNum[i+1],0);
			if (posX == arrNum[i] && i==7)
			sprite2.setPosition(arrNum[0],0);
		}
	}
	if(dif ==3)
	{
		int arrNum[9] = {650,770,890,1120,1240,1360,1600,1720,1840};
		for(int i=0; i<9;i++)
				{
					if(posX == arrNum[i] && i!=8)
					sprite2.setPosition(arrNum[i+1],0);
					if (posX == arrNum[i] && i==8)
					sprite2.setPosition(arrNum[0],0);
				}
	}

}
void Star::check (int dif)
{
	int posX = sprite2.getPosition().x;
	int posY = sprite2.getPosition().y;
	srand(time(0));
	int RandIndex = rand() % 8;
	if(dif ==1)
	{
		int arrNum[4]={1250,1370,1130,1010};
		if(sprite2.getPosition().y>=1080)
		{
			int i = RandIndex++;
			sprite2.setPosition(arrNum[i%4],0);
		}

	}
	if(dif ==2)
	{
		int arrNum[8]={780,900,1020,1140,1380,1500,1620,1740};

				for(int i=0; i<8;i++)
				{
					if(posY >=1080 &&posX == arrNum[i] && i!=7)
						sprite2.setPosition(arrNum[i+1],0);
					if (posY>=1080 && posX == arrNum[i] && i==7)
						sprite2.setPosition(arrNum[0],0);
				}
	}
	if(dif == 3)
	{
		int arrNum[9] = {650,770,890,1120,1240,1360,1600,1720,1840};
		for(int i=0; i<9;i++)
						{
							if(posY >=1080 &&posX == arrNum[i] && i!=8)
								sprite2.setPosition(arrNum[i+1],0);
							if (posY>=1080 && posX == arrNum[i] && i==8)
								sprite2.setPosition(arrNum[0],0);
						}
	}
}
