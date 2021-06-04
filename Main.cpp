#include "TicTac.h"

using namespace std;

int main() {
	int size = 3;
	Game* TheGame = new Game(size,3);
	TheGame->setBoard();
	TheGame->printBoard();
	while (TheGame->isWin(X_MAN) == false && TheGame->isWin(O_MAN) == false)
	{

		TheGame->playerTurn(X_MAN);
		TheGame->printBoard();
		TheGame->Minmax(0, O_MAN, size);
		TheGame->printBoard();
		if (TheGame->isWin(X_MAN) == true)
		{
			cout << "gratuluje wygranej panie X" << endl;
		}
		if (TheGame->isWin(O_MAN) == true)
		{
			cout << "gratuluje wygranej panie O" << endl;
		}
	}
	delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}