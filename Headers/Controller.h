#include <SFML/Graphics.hpp>
#include "../Headers/Audio.h"
#include "../Headers/Background.h"
using namespace sf;


#ifndef HEADERS_CONTROLLER_H_
#define HEADERS_CONTROLLER_H_

class Controller {
public:
	Controller();
	virtual ~Controller();
	RenderWindow window;
	Audio audio;
	const int choices = 4;
	int index;
	enum GameState{MENU,EASY,MEDIUM,HARD,END,GAME_OVER};
	GameState state;
	Font font;
	Background background;
	int speed;
	int numberOfTraps;


};

#endif /* HEADERS_CONTROLLER_H_ */
