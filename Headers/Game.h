#ifndef _GAME_H
#define _GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "../Headers/Engine.h"
#include "../Headers/Background.h"
#include "../Headers/Values.h"
#include "../Headers/Controller.h"
using namespace sf;
using namespace std;

class Game : public Controller{
public:
	Game();
	virtual ~Game();
	void run();
	void render();
	void menu();
	void gameOver(int points,int difficulty);
private :
	int diff;


};

#endif
