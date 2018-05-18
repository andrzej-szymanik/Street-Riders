
#include "../Headers/Game.h"
Game::Game() {
	state = MENU;

	if (!font.loadFromFile("Fonts/DejaVuSerif.ttf"))
	{
		return;
	}
	audio.loadMusic();
	audio.playMusic();
	run();

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::render()
{
	window.create(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Street Riders",Style::Fullscreen);
	window.setMouseCursorVisible(false);
}
void Game::run()
{
	window.setFramerateLimit(60);
	render();
	while(state != END)
	{
		switch(state)
		{
		case GameState::MENU :
		{
			menu();
			break;
		}
		case GameState::END :
			break;
		case GameState::EASY :
		{
			int difficulty = 1;
			Engine easy(window,difficulty);
			int points = easy.score;
			if (easy.next == 1 || easy.next ==0)
			gameOver(points,difficulty);
			easy.reset();

			break;
		}
		case GameState::MEDIUM :
		{
			int difficulty = 2;
			Engine medium(window,difficulty);
			int points = medium.score;
			if (medium.next == 1 || medium.next ==0)
			gameOver(points,difficulty);
			medium.reset();

							break;
		}
		case GameState::HARD :
		{
			int difficulty = 3;
			Engine hard(window,difficulty);
			int points = hard.score;
			if (hard.next == 1 || hard.next ==0)
			gameOver(points,difficulty);
			hard.reset();

							break;
		}
		case GameState::GAME_OVER :
			break;
		}
	}
}
void Game::menu()
{
	Text title("Street Riders",font,75);
	Event event;
	title.setStyle(Text::Bold);
	title.setFillColor(Color::Blue);
	title.setPosition(WINDOW_WIDTH / 2 - title.getGlobalBounds().width / 2, 15);
	Text text[choices];
	string str[] = {"Easy Game","Normal Game","Hard Game","Close"};
	for (int i=0; i<choices; i++)
	{
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setCharacterSize(45);
		text[i].setString(str[i]);
		text[i].setPosition(WINDOW_WIDTH / 2 - text[i].getGlobalBounds().width / 2, 200 + i * 120);
	}
	while(state == MENU)
	{
		while(window.pollEvent(event))
		{
			switch (event.type)
			{
							case sf::Event::KeyReleased:
								switch (event.key.code)
								{
								case Keyboard::Up:
									if(index - 1 >= 0)
									{
										text[index].setFillColor(Color::White);
										index--;
										text[index].setFillColor(Color::Red);

									}
									break;
								case Keyboard::Down:
									if(index + 1 < choices)
									{
										text[index].setFillColor(Color::White);
										index++;
										text[index].setFillColor(Color::Red);

									}
									break;

								case Keyboard::Escape:
									state=END;
									break;
								case Keyboard::Return:
									if(index == 0)
									{
										state = EASY;
										break;
									}
									if(index == 1)
									{
										state = MEDIUM;
										break;
									}
									if(index == 2)
									{
										state = HARD;
										break;
									}
									if(index == 3)
									{
										state = END;
										break;
									}
									break;
								default: break;

							}
								break;
								default:break;
							}
		}
		window.clear();
		window.draw(background);
		window.draw(title);
		for(int j=0; j<choices; j++)
		{
			window.draw(text[j]);
		}
		window.display();
	}



}
void Game::gameOver(int points,int difficulty)
{
	window.clear();
	Background background = Background(1);
	bool menu = false;
	Event event;
	const int n = 3;
	Text info[n];
	string str[] = {"Punkty : " + std::to_string(points),"SPACJA - JESZCZE RAZ","ESC - ABY WYJSC"};
	for (int i=0 ; i<n; i++)
	{
		info[i].setFont(font);
		info[i].setCharacterSize(50);
		info[i].setFillColor(Color::White);
		if (i ==0)
		{
			info[i].setCharacterSize(80);
		}
		info[i].setString(str[i]);
	}
	info[0].setPosition(1920/2 - info[0].getGlobalBounds().width /2,100);
	info[1].setPosition(1920/2 - info[1].getGlobalBounds().width /2,300);
	info[2].setPosition(1920/2 - info[2].getGlobalBounds().width /2,500);
	while(!menu)
	{
		while (window.pollEvent(event))
				{
					if (event.type == Event::Closed || (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape))
						{menu = true;
						state = MENU;
						}
					if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space)
					{
						switch(difficulty)
						{
						case 1:
						{
							menu = true;
							Engine easy(window,difficulty);
							int points = easy.score;
							if (easy.next == 1 || easy.next ==0)
							gameOver(points,difficulty);
							easy.reset();
							break;
						}
						case 2:
						{
							menu = true;
							Engine medium(window,difficulty);
							int points = medium.score;
							if (medium.next == 1 || medium.next ==0)
							gameOver(points,difficulty);
							medium.reset();
							break;
						}
						case 3:
						{
							menu = true;
							Engine hard(window,difficulty);
							int points = hard.score;
							if (hard.next == 1 || hard.next ==0)
							gameOver(points,difficulty);
							hard.reset();
														break;
						}
						default : break;
						}

					}

				}
				 str[0] = {"Punkty : " + std::to_string(points)};

					window.clear();
					window.draw(background);
					for (int j = 0; j < n; j++)
						window.draw(info[j]);
					window.display();
			}
			state = MENU;

}

