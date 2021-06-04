#pragma once
#include <iostream>

class Game {
    char** Board; //tablica dwuwymiarowa - plansza
    int size; // zmienna odpowiadaj�ca za rozmiar planszy size x size
    int winNumber; //zmienna okre�laj�ca ile musi by� ksza�t�w w linii, �eby wygra�
public:
    Game(); // kontruktor domy�lny
    Game(int size); //konstruktor, je�li podamy rozmiar planszy

    /**
     * @brief tworzenie
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
     * @brief Sprawdza, czy dane pole planszy jest wolne
     * @return 
    */
    bool isFree();

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
    void Minmax(int node,char player,int depth);

};
