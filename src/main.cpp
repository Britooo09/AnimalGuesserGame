#include <iostream>
#include "../include/node.h"
#include "../include/gameLogic.h" 

using namespace std;

int main()
{
	cout << "--- THIS IS A TEST. IT WILL BE REMOVED LATER ---" << endl << endl;

	GameLogic game;
	game.play();

	cout << "The root of this tree is: " << game.getRoot()->text << endl;

	return 0;
}
