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
            Board[j][k] = 'Z';
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


bool Game::isFree()
{
    return true;
}


void Game::playerTurn(char player)
{

}


void Game::Minmax(int node, char player, int depth)
{

}