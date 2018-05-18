/*
 * Trap.h
 *
 *  Created on: 2 sty 2018
 *      Author: andrzej
 */

#ifndef HEADERS_TRAP_H_
#define HEADERS_TRAP_H_
#include <SFML/Graphics.hpp>
using namespace sf;

class Trap :public Drawable{
public:
	Trap();
	virtual ~Trap();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setPosition(float x, float y);
	void move(float x,float y);
	Vector2f getPosition();
	FloatRect getGlobalBounds() const;
	void check(int dif);
	int i;
private:
	Texture texture3;
	Sprite trap;

};

#endif /* HEADERS_TRAP_H_ */
