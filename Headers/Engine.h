#include <SFML/Graphics.hpp>
//#include "../Headers/Game.h"
#include "../Headers/Car.h"
#include "../Headers/Controller.h"
#include "../Headers/Map.h"
#include "../Headers/Values.h"
#include "../Headers/Star.h"
#include "../Headers/Trap.h"
#include "../Headers/Tree.h"
#include <string>
#include <iostream>
using namespace sf;
#ifndef HEADERS_ENGINE_H_
#define HEADERS_ENGINE_H_

class Engine :public Controller{
public:
	Engine(RenderWindow &win,int difficulty);
	~Engine();
	void runEngine(RenderWindow &window,int dif);
	void load_map(string map);
	void obstacles(RenderWindow &win,int dif);
	void reset();
	int next;
	int score;

private:
	Car car[3];
	Trap trap[9];
	Clock timer;
	Star star[3];
	bool is_playing;
	Map mapa;
	Text info;
	Texture textura[Map::COUNT];
	Sprite sprite[Map::height][Map::width];
	Font font1;
	Tree drzewo[5];
};

#endif  /*HEADERS_ENGINE_H_*/
