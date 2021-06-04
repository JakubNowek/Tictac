#include "TicTac.h"

using namespace std;

int main() {
	//Game* TheGame = new Game(3,3);
	//TheGame->setBoard();
	//TheGame->printBoard();
	int tab[3];
	for (int i = 0; i < 3; i++)
		tab[i] = getchar() - 48;

		cout << tab[0]<<endl;
		cout << tab[2] << endl;

	//delete TheGame; //kasowanie tablicy dyniamicznej?
	return 0;
}