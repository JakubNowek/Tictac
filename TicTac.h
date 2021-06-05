#pragma once
#include <iostream>
#define X_MAN 'X'
#define O_MAN 'O'
class Game {
    char** Board; //tablica dwuwymiarowa - plansza
    int size; // zmienna odpowiadaj¹ca za rozmiar planszy size x size
    int winNumber; //zmienna okreœlaj¹ca ile musi byæ ksza³tów w linii, ¿eby wygraæ
public:
    Game(); // kontruktor domyœlny tworzy plansze do gry
    Game(int inSize, int inWinNumber); //konstruktor, jeœli podamy rozmiar planszy

    /**
     * @brief resetowanie planszy
    */
    void setBoard();

    /**
     * @brief wypisywanie planszy
    */
    void printBoard();

    /**
     * @brief Sprawdza czy gracz player wygra³
     * @param player - gracz - komputer lub cz³owiek
     * @return zwraca True jeœli gracz player wygra³
    */
    bool isWin(char player);

    /**
     * @brief Sprawdza, czy na planszy jest wolne pole
     * @return 
    */
    bool isEmpty();

    /**
     * @brief sprawdza czy dane pole tablicy jest wolne
     * @param i - zmienna oznaczaj¹ca numer rzêdu tablicy
     * @param j - zmienna oznacz¹ca numer kolumy tablicy
     * @return  - zwraca true jeœli dana komórka Board[i][j] jest wolna
    */
    bool isFree(int i, int j);

    /**
     * @brief Wykonywanie ruchu gracza
     * @param player - gracz, ktry wykonuje ruch 
    */
    void playerTurn(char player);

    /**
     * @brief Realizuje algorytm minmax oraz ruch komputera, jeœli player = PC
     * @param node - poziom drzewa gry
     * @param player - gracz wykonuj¹cy ruch na danym poziomie
     * @param depth - g³êbokoœæ rekurenncji
    */
    int Minmax(int node,char player,int depth, int aplha, int beta);
};
