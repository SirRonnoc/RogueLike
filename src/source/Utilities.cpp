#include <vector>
#include "Utilities.h"
using namespace std;

int Utilities::findLikeNeighbours(int x, int y, vector<vector<int>> v) {
	int ctr = 0;
	int findLike = v.at(y).at(x);
	for (int i = -1; i < 2; i++) {
		for (int g = -1; g < 2; g++) {
			if (y + i > 0 && y + i < v.size() && x + g > 0 && x + g < v.at(0).size()) {
				if (v.at(y + i).at(x + g) == findLike) {
					ctr++;
				}
			}
		}
	}
	return ctr;
}
