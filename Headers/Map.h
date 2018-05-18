#include <fstream>
#include <iostream>
#include <string>
#ifndef HEADERS_MAP_H_
#define HEADERS_MAP_H_
#include "Values.h"
using namespace std;
class Map {
public:
	Map(void);
	Map(string filename);
	void loadFromFile(string filename);

	enum fieldType{
		NONE,ROAD,GRASS,ROAD1,ROAD2,INFO,MOVING_ROAD,COUNT};
	struct Tile
	{
		fieldType type;
	};
	const static int width = WINDOW_WIDTH/LANE_WIDTH;
	const static int height = WINDOW_HEIGHT/LANE_WIDTH;
	const static int tile_width = LANE_WIDTH;
	const static int tile_height = LANE_WIDTH;
	Tile level[height][width];
	virtual ~Map();
};

#endif /* HEADERS_MAP_H_ */
