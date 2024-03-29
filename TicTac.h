#pragma once
#include <iostream>
#define X_MAN 'X'
#define O_MAN 'O'
class Game {
    char** Board; //tablica dwuwymiarowa - plansza
    int size; // zmienna odpowiadaj�ca za rozmiar planszy size x size
    int winNumber; //zmienna okre�laj�ca ile musi by� ksza�t�w w linii, �eby wygra�
    bool wminmax;
public:
    Game(); // kontruktor domy�lny tworzy plansze do gry
    Game(int inSize, int inWinNumber); //konstruktor, je�li podamy rozmiar planszy

    /**
     * @brief resetowanie planszy
    */
    void setBoard();

    /**
     * @brief wypisywanie planszy
    */
    void printBoard();

    /**
     * @brief Sprawdza czy gracz player wygra�
     * @param player - gracz - komputer lub cz�owiek
     * @return zwraca True je�li gracz player wygra�
    */
    bool isWin(char player);

    /**
     * @brief Sprawdza, czy na planszy jest wolne pole
     * @return 
    */
    bool isEmpty();

    /**
     * @brief sprawdza czy dane pole tablicy jest wolne
     * @param i - zmienna oznaczaj�ca numer rz�du tablicy
     * @param j - zmienna oznacz�ca numer kolumy tablicy
     * @return  - zwraca true je�li dana kom�rka Board[i][j] jest wolna
    */
    bool isFree(int i, int j);

    /**
     * @brief Wykonywanie ruchu gracza
     * @param player - gracz, ktry wykonuje ruch 
    */
    void playerTurn(char player);

    /**
     * @brief Realizuje algorytm minmax oraz ruch komputera, je�li player = PC
     * @param node - poziom drzewa gry
     * @param player - gracz wykonuj�cy ruch na danym poziomie
     * @param depth - g��boko�� rekurenncji
    */
    int Minmax(int node,char player,int depth, int aplha, int beta);


    bool &getWminmax() { return wminmax; }
};
