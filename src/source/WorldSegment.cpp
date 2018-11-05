#include "World.h"
#include <cstdlib>
#include <vector>
#include "Utilities.h"
using namespace World;
using namespace std;
using namespace Utilities;
WorldSegment::WorldSegment(std::string b, int w, int h) {
	biome = b;
	width = w; height = h;
	if (biome.compare("cave") == 0) {
		generateCave();
	}
}
WorldSegment::WorldSegment() {

}
WorldSegment::~WorldSegment() {

}
string WorldSegment::getBiome() {
	return biome;
}
vector<vector<Tile>> WorldSegment::getTileMap() {
	return tileMap;
}
void WorldSegment::generateCave() {
	vector<vector<int>> temp = vector<vector<int>>();
	for (int y = 0; y < height; y++) {
		temp.push_back(vector<int>());
		for (int x = 0; x < width; x++) {
			temp.at(y).push_back(rand() % 2);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (findLikeNeighbours(x, y, temp) < 4) {
					temp.at(y).at(x) = temp.at(y).at(x) == 0 ? 1 : 0;
				}
			}
		}
	}
	for (int y = 0; y < height; y++) {
		tileMap.push_back(vector<Tile>());
		for (int x = 0; x < width; x++) {
			if (temp.at(y).at(x) == 0) {
				tileMap.at(y).push_back(Tile("cave", "caveWall"));
			}
			else {
				tileMap.at(y).push_back(Tile("cave", "caveWall"));
			}
			
		}
	}
}