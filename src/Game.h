#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Background.h"
#include <string>
using namespace sf;
using namespace std;

class Game {
public:
	Game();
	RenderWindow window;
	const int choices = 4;
	int index;
	virtual ~Game();
	void runGame();
	void render();
	void menu();
protected:
		enum GameState{MENU,EASY,MEDIUM,HARD,GAME_OVER,END};
		GameState state;
private:
	Font font;
	Background background;

};

