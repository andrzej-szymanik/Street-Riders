/*
 * Points.h
 *
 *  Created on: 1 sty 2018
 *      Author: andrzej
 */

#ifndef HEADERS_POINTS_H_
#define HEADERS_POINTS_H_
#include <SFML/Graphics.hpp>
using namespace sf;

class Points :public Drawable {
public:
	enum Type
		{
			Circle,
			Triangle,
		};
	Points();
	Texture texture2;
	virtual ~Points();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Type type;

};

#endif /* HEADERS_POINTS_H_ */
