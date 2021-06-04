#include "TicTac.h"

using namespace std;

Game::Game() 
{
    size = 3;
    Board = new  char* [3];

    //tworzenie planszy
    for (int i = 0; i < 3; ++i)
    {
        Board[i] = new char[3];
    }
    //wypelnianie planszy pustymi znakami
    for (int j = 0; j < 3; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            Board[j][k] = ' ';
        }
    }
}

Game::Game(int inSize, int inWinNumber)
{
    size = inSize;
    winNumber = inWinNumber;
    Board = new  char* [size];

    //tworzenie planszy
    for (int i = 0; i < size; ++i)
    {
        Board[i] = new char[3];
    }
    //wypelnianie planszy pustymi znakami
    for (int j = 0; j < size; ++j)
        for (int k = 0; k < size; ++k)
        {
            Board[j][k] = ' ';
        }
}


void Game::setBoard()
{
    //wypelnianie planszy pustymi znakami
    for (int j = 0; j < size; ++j)
        for (int k = 0; k < size; ++k)
        {
            Board[j][k] = ' ';
        }
}


void Game::printBoard()
{
    cout << "Wybrano pole " << size << " x " << size << endl;
    cout << " " << " ";
    for (int i = 0; i < size; i++)
        cout << " "<<"|"<<" " << i;
    cout <<" |"<< endl;

    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size+1; i++)
            cout <<"_"<< "_"<<"_" << "|";
        cout << endl<<" ";
        cout  << j<<" "<<"|";
        for (int k = 0; k < size; ++k)
        {
            cout <<" " << Board[j][k]<<" "<<"|";
        }
        cout << endl;

    }
    for (int i = 0; i < size+1; i++)
        cout << "   " << "|" ;
    cout << endl << endl;
}


bool Game::isWin(char player)
{
    return true;
}

bool Game::isFree(int i, int j)
{
    if (Board[i][j] == ' ')
        return true;
    return false;
}

bool Game::isEmpty()
{
    for (int k = 0; k < size; ++k)
    {
        for (int l = 0; l < size; ++l)
        {
            if (Board[k][l] == ' ')
                return true;
        }
    }
    return false;
}


void Game::playerTurn(char player)
{
    int Tab[2];
    bool done = false;
    do
    {
        cout << "Podaj wiersz i kolumne:\n";
        cin >> Tab[0]>>Tab[1];
        //cout << "Podaj kolumne:\n";
        ////cin >> Tab[1];
        if (Tab[0]<0 || Tab[0]>size - 1 || Tab[1]<0 || Tab[1]>size - 1)
        {
            cout << "Wspolrzedne poza tablica\n";
        }
        else if (isFree(Tab[0],Tab[1]) == false)
        {
            cout << "Ta komorka jest zajeta\n";
        }
        else
        {
            Board[Tab[0]][Tab[1]] = player;
            done = true;
        }
    }         while (!done);
}


void Game::Minmax(int node, char player, int depth)
{

}