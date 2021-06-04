#include "TicTac.h"

using namespace std;

int main() {
	Game* TheGame = new Game(5,3);
	TheGame->setBoard();
	TheGame->printBoard();
	while (TheGame->isWin(X_MAN) == false)
	{

		TheGame->playerTurn(X_MAN);
		TheGame->printBoard();
		if (TheGame->isWin(X_MAN) == true)
		{
			cout << "gratuluje wygranej panie tracz" << endl;
		}
	}
	delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}