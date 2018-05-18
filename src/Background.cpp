#include "../Headers/Background.h"

Background::Background(int state ) {
	if (state == 0)
	{
texture.loadFromFile("Graphics/background.jpg");
	}
	else if (state ==1)
	{
	texture.loadFromFile("Graphics/gameover.jpg");
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

Background::~Background() {
	// TODO Auto-generated destructor stub
}

void Background::draw(RenderTarget &target, RenderStates states)const
{
	target.draw(sprite);
}

