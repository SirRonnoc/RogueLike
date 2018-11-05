#include "World.h"
#include <cstring>
using namespace World;
using namespace std;
Tile::Tile(std::string b, std::string t) {
	biome = b;
	type = t;
	
}
Tile::~Tile() {

}
string Tile::getType() {
	return type;
}