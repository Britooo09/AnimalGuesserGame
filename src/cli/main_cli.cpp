#include <iostream>
#include "node.h"
#include "programLogic.h"
#include "gameLogic.h"

using namespace std;

int main() {
	cout << "--- THIS IS A TEST. IT WILL BE REMOVED LATER ---" << endl << endl;

	GameLogic game;
	game.play();
  
	// Free all dynamic memory before exiting (by explicitly passing the root)
	cleanMemory(game.getRoot());
  
	return 0;
}