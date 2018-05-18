#include "../Headers/Car.h"

Car::Car()
{
	lane = 3;
	if(!texture1.loadFromFile("Graphics/car.png"))
		return;

}
Car::~Car() {

}

void Car::draw(RenderTarget &target, RenderStates states)const
{
states.transform *= getTransform();
target.draw(car);

}
void Car::moveLeft()
{
	if(lane>1)
	{
		car.move(-120,0);
		lane--;
	}

}
void Car::moveRight(int difficulty)
{
	if(difficulty == 1 || difficulty ==2)
		numberOfLanes = 4;
	else
		numberOfLanes = 3;
	if(lane<numberOfLanes)
	{
		car.move(120,0);
		lane++;
	}

}
void Car::create(Color color,int x,int y)
{
car.setTexture(texture1);
car.setTextureRect(IntRect(0,0,60,100));
car.setOrigin(32,32);
car.setPosition(x,y);
car.setColor(color);

}
Vector2f Car::getPosition()
{
	return car.getPosition();
}
FloatRect Car::getGlobalBounds() const
{
	return car.getGlobalBounds();
}

