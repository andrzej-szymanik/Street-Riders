/*
 * Tree.cpp
 *
 *  Created on: 14 sty 2018
 *      Author: andrzej
 */

#include "../Headers/Tree.h"

Tree::Tree() {
	if (!treeTexture.loadFromFile("Graphics/tree.png"))
				{
					return;
				}

}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}
void Tree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(tree);
}
void Tree::create(float x, float y)
{

			tree.setTexture(treeTexture);
			tree.setTextureRect(IntRect(0,0,300,324));
			tree.setOrigin(32,32);
			tree.setPosition(x,y);
}
void Tree::move(float x,float y)
{
			tree.move(x,y);

}
