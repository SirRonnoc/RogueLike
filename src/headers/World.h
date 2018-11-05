#pragma once
#include <vector>
#include <cstring>
#include <map>
namespace World {
	class Tile {
	public:
		Tile(std::string b, std::string t);
		~Tile();
		std::string getType();
	private:
		std::string biome;
		std::string type;

	};
	class WorldSegment {
	public:
		WorldSegment(std::string b,int w, int h);
		WorldSegment();
		~WorldSegment();
		std::vector<std::vector<Tile>> getTileMap();
		std::string getBiome();
	private:
		std::string biome;
		std::vector<std::vector<Tile>> tileMap;
		void generateCave();
		int width;
		int height;
	};
}
