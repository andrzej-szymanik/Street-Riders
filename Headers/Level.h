#ifndef _LEVEL_H
#define _LEVEL_H
#include <SFML/Graphics.hpp>
#include "Background.h"
using namespace sf;

class Level {
public:
	Level(RenderWindow &window);
	virtual ~Level();
	void runGame(RenderWindow &window);
private:
	Background texture1;

};

#endif
