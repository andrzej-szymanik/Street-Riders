/*
 * Tree.h
 *
 *  Created on: 14 sty 2018
 *      Author: andrzej
 */
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef HEADERS_TREE_H_
#define HEADERS_TREE_H_

class Tree : public Drawable{
public:
	Tree();
	virtual ~Tree();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void create(float x, float y);
	void move(float x,float y);

private:
	Texture treeTexture;
	Sprite tree;
};

#endif /* HEADERS_TREE_H_ */
