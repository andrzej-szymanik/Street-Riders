/*
 * Map.cpp
 *
 *  Created on: 30 gru 2017
 *      Author: andrzej
 */

#include "../Headers/Map.h"

Map::Map(void) {
	// TODO Auto-generated constructor stub

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}
Map::Map(string filename)
{
	loadFromFile(filename);
}
void Map::loadFromFile(string filename)
{
	fstream file;
	file.open("Graphics/maps/"+filename,ios::in);
	if(!file.is_open())
	{
		cout<<"Error"<<endl;
		//return;
	}

	else
	{
		for (int y=0; y<height; y++)
			for(int x=0; x<width; x++)
			{
				char tmp;
				file >> tmp;
				switch (tmp)
				{
				case '1' : level[y][x].type = ROAD;
						break;
				case '2': level[y][x].type = GRASS;
						  break;
				case '3': level[y][x].type = ROAD1;
						  break;
				case '4': level[y][x].type = ROAD2;
						  break;
				case '5' :level[y][x].type = MOVING_ROAD;
						  break;
				default:  level[y][x].type = INFO;
							break;
				}

			}
		}
	file.close();
}
