#include "TicTac.h"

int main() {
	Game* TheGame = new Game(3,3);
	TheGame->setBoard();
	TheGame->printBoard();


	delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}