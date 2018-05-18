/*
 * Star.h
 *
 *  Created on: 4 sty 2018
 *      Author: andrzej
 */

#ifndef HEADERS_STAR_H_
#define HEADERS_STAR_H_
#include <SFML/Graphics.hpp>
using namespace sf;

class Star : public Drawable,Transformable{
public:
	Star();
	virtual ~Star();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setPosition(float x, float y);
	void move(float x,float y);
	Vector2f getPosition();
	FloatRect getGlobalBounds() const;
	void randomize(int dif);
	void check(int dif);
private:
	Texture texture2;
	Sprite sprite2;
};

#endif /* HEADERS_STAR_H_ */
