#include "../Headers/Level.h"

Level::Level(RenderWindow &window) {
	runGame(window);

}

Level::~Level() {
	// TODO Auto-generated destructor stub
}

void Level::runGame(RenderWindow &window)
{
	bool menu = false;
while(!menu)
{
Event event;
while (window.pollEvent(event))
{
	if(event.type == Event::Closed || (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape))
	{
		return;
	}
}
window.clear();
window.draw(texture1);
window.display();
}


}
