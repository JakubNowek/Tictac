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

    //Poziomo
    int counter;
    for (int i = 0; i < size; ++i)
    {
        counter = 0;
        for (int j = 0; j < size - 1; ++j)
        {
            if (Board[i][j] == Board[i][j + 1] && Board[i][j + 1] == player)
            {
                counter++;
                if (counter == winNumber - 1) // czy tutaj serio -1?
                    return true;
            }
            else
                counter = 0;
        }
    }

    //Pionowo
    for (int j = 0; j < size; ++j)
    {
        counter = 0;
        for (int i = 0; i < size - 1; ++i)
        {
            if (Board[i][j] == Board[i + 1][j] && Board[i + 1][j] == player)
            {
                counter++;
                if (counter == winNumber - 1) // czy tutaj serio -1?
                    return true;
            }
            else
                counter = 0;
        }
    }

    // Przek¹tne
        //00<->nn
    counter = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        if (Board[i][i] == Board[i + 1][i + 1] && Board[i + 1][i + 1] == player)
        {
            counter++;
            if (counter == winNumber - 1)// czy tutaj serio -1?
                return true;
        }
        else
            counter = 0;
    }
        //n0<->0n 
    for (int i = 0; i < size - 1; ++i)
    {
        if (Board[i][size - 1 - i] == Board[i + 1][size - 1 - (i + 1)] && Board[i + 1][size - 1 - (i + 1)] == player)
        {
            counter++;
            if (counter == winNumber - 1) // czy tutaj serio -1?
                return true;
        }
        else
            counter = 0;
    }

    // Pozostale przekatne
    if (winNumber < size)
    {
        // Powyzej 00<->nn
        for (int i = 1; i <= size - winNumber; i++)
        {
            for (int j = 0; j < size - i - 1; ++j)
            {
                if (Board[i + j][j] == Board[i + j + 1][j + 1] && Board[i + j + 1][j + 1] == player)
                {
                    counter++;
                    if (counter == winNumber - 1) // czy tutaj serio -1?
                        return true;
                }
                else
                    counter = 0;
            }
        }

        // Ponizej 00<->nn
        for (int i = 1; i <= size - winNumber; i++)
        {
            for (int j = 0; j < size - i - 1; ++j)
            {
                if (Board[j][j + i] == Board[j + 1][j + 1 + i] && Board[j + 1][i + j + 1] == player)
                {
                    counter++;
                    if (counter == winNumber - 1) // czy tutaj serio -1?
                        return true;
                }
                else
                    counter = 0;
            }
        }

        // Powyzej n0<->0n
        for (int i = 1; i < size - 1; ++i)
        {
            for (int j = 0; j <= size - winNumber - i; ++j)
            {
                if (Board[size - (i + j) - 1][size - (size - j)] == Board[size - (i + j) - 1 - 1][size - (size - j) + 1] && Board[size - (i + j) - 1 - 1][size - (size - j) + 1] == player)
                {
                    counter++;
                    if (counter == winNumber - 1) // czy tutaj serio -1?
                        return true;
                }
                else
                    counter = 0;
            }
        }

        // Ponizej n0<->0n
        for (int i = 1; i <= size - winNumber; ++i)
        {
            for (int j = size - i - 1; j >= 1; --j)
            {
                if (Board[i + j][size - 1 - j] == Board[i + j - 1][size - j] && Board[i + j - 1][size - j] == player)
                {
                    counter++;
                    if (counter == winNumber - 1) // czy tutaj serio -1?
                        return true;
                }
                else
                    counter = 0;
            }
        }
    }
    return false;
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
            cout << "Nie ma tekiego pola :( \n";
        }
        else if (isFree(Tab[0],Tab[1]) == false)
        {
            cout << "Pole zajete :( \n";
        }
        else
        {
            Board[Tab[0]][Tab[1]] = player;
            done = true;
        }
    }         while (!done);
}

///////////////////////////////////////////////////////////////to do/////////////////////////////////////////////////////////
int Game::Minmax(int node, char player, int depth)
{
    int counter = 0;
    int row = NULL, column=NULL;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (Board[i][j] == ' ')
            {
                Board[i][j] = player;
                column = j;
                row = i;
                counter++;
                bool test = isWin(player);
                Board[i][j] = ' ';
                if (test)
                {
                    if (!node)
                        Board[i][j] = player;
                    return player == 'X' ? -1 : 1;
                }
            }
        }
    }
   // Czy X i O zremisowali
    if (counter == 1)
    {
        if (!node)
            Board[row][column] = player;
        return 0;
    }
    // Wybór ruchu
    int V, VMax;
    VMax = (player == 'X' ? size - 1 : -size + 1);
    for (int i = 0; i < depth; ++i)
    {
        for (int j = 0; j < depth; ++j)
        {
            if (Board[i][j] == ' ')
            {
                Board[i][j] = player;
                V = Minmax(node + 1, (player == 'X' ? 'O' : 'X'), depth);
                Board[i][j] = ' ';
                if (((player == 'X') && (V < VMax)) || ((player == 'O') && V > VMax))
                {
                    row = i;
                    column = j;
                    VMax = V;
                }
            }
        }
    }
    if (!node)
        Board[row][column] = player;
    cout << "Counter: " << counter << endl;
    return VMax;
}