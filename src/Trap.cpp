/*
 * Trap.cpp
 *
 *  Created on: 2 sty 2018
 *      Author: andrzej
 */

#include "../Headers/Trap.h"
#include <iostream>

Trap::Trap() {
	if (!texture3.loadFromFile("Graphics/police.png"))
	{
		return;
	}
	i=0;
	trap.setTexture(texture3);
	trap.setTextureRect(IntRect(0,0,60,100));
	trap.setOrigin(32,32);
	trap.setPosition(-200,-200);
}

Trap::~Trap() {
	// TODO Auto-generated destructor stub
}
void Trap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(trap);
}
void Trap::setPosition(float x,float y)
{
	trap.setPosition(x,y);
}
void Trap::move(float x,float y)
{

			trap.move(x,y);



}
Vector2f Trap::getPosition()
{
	return trap.getPosition();
}
FloatRect Trap::getGlobalBounds() const
{
	return trap.getGlobalBounds();
}
void Trap::check (int dif)
{
	int posX = trap.getPosition().x;
	int posY = trap.getPosition().y;
	if(dif ==1)
	{
		int arrNum[4]={1250,1370,1130,1010};
		for(int i=0; i<4;i++)
				{
					if(posY >=1080 &&posX == arrNum[i] && i!=3)
						trap.setPosition(arrNum[i+1],0);
					if (posY>=1080 && posX == arrNum[i] && i==3)
						trap.setPosition(arrNum[0],0);
				}
	}
	if(dif ==2)
	{

		int arrNum[8]={780,900,1020,1140,1380,1500,1620,1740};

		for(int i=0; i<8;i++)
		{
			if(posY >=1080 &&posX == arrNum[i] && i!=7)
				trap.setPosition(arrNum[i+1],0);
			if (posY>=1080 && posX == arrNum[i] && i==7)
				trap.setPosition(arrNum[0],0);
		}

	}
	if(dif ==3)
		{

			int arrNum[9]={650,770,890,1120,1240,1360,1600,1720,1840};
			for(int i=0; i<8;i++)
					{
						if(posY >=1080 &&posX == arrNum[i] && i!=8)
							trap.setPosition(arrNum[i+1],0);
						if (posY>=1080 && posX == arrNum[i] && i==8)
							trap.setPosition(arrNum[0],0);
					}
		}

}
