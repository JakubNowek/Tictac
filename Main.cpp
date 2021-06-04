#include "TicTac.h"

using namespace std;

int main() {
	Game* TheGame = new Game(3,3);
	TheGame->setBoard();
	TheGame->printBoard();
	TheGame->playerTurn(X_MAN);
	TheGame->printBoard();
	TheGame->playerTurn(X_MAN);
	TheGame->printBoard();
	TheGame->playerTurn(X_MAN);
	TheGame->printBoard();
	delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}