#include "TicTac.h"

using namespace std;

int main() {
	int size = 3;
	Game* TheGame = new Game(size,3);
	cout << "Wybrano pole " << size << " x " << size << endl;
	TheGame->setBoard();
	TheGame->printBoard();
	//while (TheGame->isEmpty())
	//{
	//	TheGame->playerTurn(O_MAN);
	//	TheGame->printBoard();
	//	if (TheGame->isWin(O_MAN))
	//		break;
	//}
	while(TheGame->isEmpty() )
	{

		TheGame->playerTurn(O_MAN);
		TheGame->printBoard();
		TheGame->getWminmax() = false;
		if (TheGame->isWin(O_MAN))
			break;
		TheGame->Minmax(0, X_MAN, 3,22222,-22222);
		TheGame->printBoard();
		TheGame->getWminmax() = false;
		if (TheGame->isWin(X_MAN))
			break;
	}
	delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}