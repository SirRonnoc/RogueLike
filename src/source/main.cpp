#include <iostream>
#include "Engine.h" 
using namespace std;
Engine engine;
int main(int argc, char *argv[]) {

	engine = Engine("RogueLike",800,600,false);
	while (engine.running()) {
		cout << "running" << endl;
		engine.render();
		engine.handleEvents();
	}
	return 0;
}