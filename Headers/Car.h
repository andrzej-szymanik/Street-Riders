#ifndef _CAR_H
#define _CAR_H
#include <SFML/Graphics.hpp>
#include "../Headers/Values.h"
using namespace sf;

class Car : public Drawable,Transformable{
public:
	 Car();
	 ~Car();
	 void draw(RenderTarget &target, RenderStates states)const;
	 void moveLeft();
	 void moveRight(int difficulty);
	 void create(Color color,int x,int y);
	 FloatRect getGlobalBounds() const;
	 int lane ;
	 int numberOfLanes;
   	 Vector2f getPosition();

private:
	Texture texture1;
	Sprite car;


};

#endif
