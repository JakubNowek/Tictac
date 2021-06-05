#include "TicTac.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
	int size,win;

	cout << "Witaj sprawdz, czy uda ci sie nieprzegrac!" << endl;
	cout << "Podaj rozmiar pola oraz po spacji ile O (lub X) nalezy ulozyc, zeby wygrac:" << endl;
	cin >> size >>win;
	Game* TheGame = new Game(size,win);
	cout << "Wybrano pole " << size << " x " << size << endl;
	TheGame->setBoard();
	TheGame->printBoard();
	while(TheGame->isEmpty() )
	{

		TheGame->playerTurn(O_MAN);
		TheGame->printBoard();
		TheGame->getWminmax() = false;
		if (TheGame->isWin(O_MAN))
			break;
		if (!TheGame->isEmpty())
			break;
		cout << "Ruch komputera." << endl;
		TheGame->Minmax(0, X_MAN, size,-22222,22222);
		TheGame->printBoard();
		TheGame->getWminmax() = false;
		if (TheGame->isWin(X_MAN))
			break;
	}
	TheGame->getWminmax() = true;
	if (!TheGame->isWin(O_MAN) && !TheGame->isWin(X_MAN))
		cout << "Czeski remis." << endl;
	delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}