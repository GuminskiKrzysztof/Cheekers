// Program, kt�ry umo�liwia rozgrywk� miedzy 2 graczami w warcaby klasyczne plus  
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

const int wielkosc_planszy = 8;

// Utworzenie planszy o wymiarach wielko�ci planszy - standardowo 8x8
int plansza[wielkosc_planszy][wielkosc_planszy];

// Funkcja, kt�ra zapisuje pocz�tkowy uk�ad planszy
void konwersjaPlanszyNaTablice(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    // wyja�nienie oznacze� pionk�w i figur na planszy gry
    // 0 - puste pole
    // 1 - bia�y pionek
    // 11 - bia�a dama
    // 2 - czerwony pionek
    // 22 - czerwona dama

    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (((j + j) % 2) == 0)
            {
                tab[i][j] = 0;
            }
        }
    }
    // ustawienie bia�ych figur na planszy
    const int bdamy = 11;
    const int bpionki = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            // warunek spe�niony dla ustawianych dam
            if (((i + j) % 2 == 0) && (i == 0))
            {
                tab[i][j] = bdamy;
            }
            // warunek spe�niony dla ustawianych pionkow
            else if (((i + j) % 2 == 0))
            {
                tab[i][j] = bpionki;
            }
        }
    }
    // ustawienie czerwonych figur na planszy
    const int czdamy = 22;
    const int czpionki = 2;
    for (int i = 5; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            // warunek spe�niony dla ustawianych dam
            if (((i + j) % 2 == 0) && (i == rozmiar - 1))
            {
                tab[i][j] = czdamy;
            }
            // warunek spe�niony dla ustawianych pionkow
            else if (((i + j) % 2 == 0))
            {
                tab[i][j] = czpionki;
            }
        }
    }
}
// Funkcja, kt�ra pokazuje aktualny uk�ad planszy
void pokazaniePlanszy(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    int pomoc = 65;
    cout.width(12);
    for (int i = 0; i < 8; i++)
    {
        cout << char(pomoc + i);
        cout.width(6);
    }
    cout << endl;
    cout << endl;
    int kolumny = 1;
    cout.width(6);
    for (int i = 0; i < rozmiar; i++)
    {
        cout << kolumny;
        cout.width(6);
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] > 0)
            {
                cout << tab[i][j];
            }
            else
            {
                cout << "_";
            }

            cout.width(6);
        }
        cout << endl;
        cout << endl;
        kolumny++;
    }
    cout << endl;
}

// funkcja, kt�ra sprawdza czy mo�liwe jest zbicie bia�� dama
bool bicieBialaDama(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    // deklaracja zmiennych, kt�re przechowuj� aktualne warto�ci indeks�w
    int k;
    int g;
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] == 11)
            {
                if ((i + 2) < rozmiar && (j + 2) < rozmiar)
                {
                    if ((tab[i + 1][j + 1] == 2 || tab[i + 1][j + 1] == 22) && tab[i + 2][j + 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i + 2) < rozmiar && (j - 2) >= 0)
                {
                    if ((tab[i + 1][j - 1] == 2 || tab[i + 1][j - 1] == 22) && tab[i + 2][j - 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i - 2) >= 0 && (j + 2) < rozmiar)
                {
                    if ((tab[i - 1][j + 1] == 2 || tab[i - 1][j + 1] == 22) && tab[i - 2][j + 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i - 2) >= 0 && (j - 2) >= 0)
                {
                    if ((tab[i - 1][j - 1] == 2 || tab[i - 1][j - 1] == 22) && tab[i - 2][j - 2] == 0)
                    {
                        return true;
                    }
                }
                k = i;
                g = j;
                int a;
                int b;
                bool czyDamamoze = true;
                while (k < rozmiar && g < rozmiar)
                {
                    k++;
                    g++;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 2 || tab[k][g] == 22)
                        {
                            if (tab[k + 1][g + 1] == 0)
                            {
                                a = i + 1;
                                b = j + 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a++;
                                    b++;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                k = i;
                g = j;
                while (k < rozmiar && g >= 0)
                {
                    k++;
                    g--;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 2 || tab[k][g] == 22)
                        {
                            if (tab[k + 1][g - 1] == 0)
                            {
                                a = i + 1;
                                b = j - 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a++;
                                    b--;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                k = i;
                g = j;
                while (k >= 0 && g < rozmiar)
                {
                    k--;
                    g++;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 2 || tab[k][g] == 22)
                        {
                            if (tab[k - 1][g + 1] == 0)
                            {
                                a = i - 1;
                                b = j + 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a--;
                                    b++;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                k = i;
                g = j;
                while (k >= 0 && g >= 0)
                {
                    k--;
                    g--;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 2 || tab[k][g] == 22)
                        {
                            if (tab[k - 1][g - 1] == 0)
                            {
                                a = i - 1;
                                b = j - 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a--;
                                    b--;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
// funkcja, kt�ra sprawdza czy mo�liwe jest zbicie czerwon� dama
bool bicieCzerwonaDama(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    // deklaracja zmiennych, kt�re przechowuj� aktualne wartosci indeksow
    int k;
    int g;
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] == 22)
            {
                if ((i + 2) < rozmiar && (j + 2) < rozmiar)
                {
                    if ((tab[i + 1][j + 1] == 1 || tab[i + 1][j + 1] == 11) && tab[i + 2][j + 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i + 2) < rozmiar && (j - 2) >= 0)
                {
                    if ((tab[i + 1][j - 1] == 1 || tab[i + 1][j - 1] == 11) && tab[i + 2][j - 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i - 2) >= 0 && (j + 2) < rozmiar)
                {
                    if ((tab[i - 1][j + 1] == 1 || tab[i - 1][j + 1] == 11) && tab[i - 2][j + 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i - 2) >= 0 && (j - 2) >= 0)
                {
                    if ((tab[i - 1][j - 1] == 1 || tab[i - 1][j - 1] == 11) && tab[i - 2][j - 2] == 0)
                    {
                        return true;
                    }
                }
                k = i;
                g = j;
                int a;
                int b;
                bool czyDamamoze = true;
                while (k < rozmiar && g < rozmiar)
                {
                    k++;
                    g++;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 1 || tab[k][g] == 11)
                        {
                            if (tab[k + 1][g + 1] == 0)
                            {
                                a = i + 1;
                                b = j + 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a++;
                                    b++;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                k = i;
                g = j;
                while (k < rozmiar && g >= 0)
                {
                    k++;
                    g--;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 1 || tab[k][g] == 11)
                        {
                            if (tab[k + 1][g - 1] == 0)
                            {
                                a = i + 1;
                                b = j - 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a++;
                                    b--;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                k = i;
                g = j;
                while (k >= 0 && g < rozmiar)
                {
                    k--;
                    g++;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 1 || tab[k][g] == 11)
                        {
                            if (tab[k - 1][g + 1] == 0)
                            {
                                a = i - 1;
                                b = j + 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a--;
                                    b++;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                k = i;
                g = j;
                while (k >= 0 && g >= 0)
                {
                    k--;
                    g--;
                    if (((k - 1) >= 0) && ((g - 1) >= 0) && ((k + 1) < rozmiar) && ((g + 1) < rozmiar))
                    {
                        if (tab[k][g] == 1 || tab[k][g] == 11)
                        {
                            if (tab[k - 1][g - 1] == 0)
                            {
                                a = i - 1;
                                b = j - 1;
                                while (a != k && b != g)
                                {
                                    if (tab[a][b] != 0)
                                    {
                                        czyDamamoze = false;
                                    }
                                    a--;
                                    b--;
                                }
                                if (czyDamamoze == true)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
// funkcja, kt�ra sprawdza czy mo�liwe jest zbicie bia�ym pionkiem
bool bicieBialymPionkiem(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] == 1)
            {
                // warunek ,ktory spowoduje ,ze nie wykroczymy poza tablic�
                if ((i + 2) < rozmiar && (j + 2) < rozmiar)
                {
                    if ((tab[i + 1][j + 1] == 2 || tab[i + 1][j + 1] == 22) && tab[i + 2][j + 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i + 2) < rozmiar && (j - 2) >= 0)
                {
                    if ((tab[i + 1][j - 1] == 2 || tab[i + 1][j - 1] == 22) && tab[i + 2][j - 2] == 0)
                    {
                        return true;
                    }
                }

            }
        }
    }

    return false;
}
// funkcja, kt�ra sprawdza czy mo�liwe jest zbicie czerwonym pionkiem
bool bicieCzerwonymPionkiem(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] == 2)
            {
                // warunek, ktory sprawdza czy nie wykroczymy poza plansz�
                if ((i - 2) >= 0 && (j + 2) < rozmiar)
                {
                    if ((tab[i - 1][j + 1] == 1 || tab[i - 1][j + 1] == 11) && tab[i - 2][j + 2] == 0)
                    {
                        return true;
                    }
                }
                if ((i - 2) >= 0 && (j - 2) >= 0)
                {
                    if ((tab[i - 1][j - 1] == 1 || tab[i - 1][j - 1] == 11) && tab[i - 2][j - 2] == 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
// funkcja, kt�ra sprawdza czy dany ruch figur� lub pionkiem jest dozwolony 
bool dozwolonyRuch(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar, int wspP1, int wspP2, int wspK1, int wspK2, bool zbicieBP, bool zbicieBD, bool zbicieCZP, bool zbicieCZD, int ruchyDamamiBezZmiany)
{
    // Je�eli gracz wybierze pole docelowe, ktore nie jest puste to funkcja zwroci fa�sz
    if (tab[wspK1][wspK2] != 0)
    {
        return false;
    }
    // Jesli gracz wybierze pole docelowe, ktore nie jest na przekatnej to funkcja zwroci fa�sz
    if (abs(wspK1 - wspP1) != abs(wspK2 - wspP2))
    {
        return false;
    }
    if (tab[wspP1][wspP2] == 1)
    {
        if (zbicieBP == true)
        {
            // warunek wynika z tego, �e piony mog� bi� zarowno do przodu, jak i do ty�u
            if (abs(wspK1 - wspP1) == 2 && abs(wspK2 - wspP2) == 2)
            {
                if (wspK2 > wspP2 && wspK1 > wspP1)
                {
                    if (tab[wspP1 + 1][wspP2 + 1] == 2)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 + 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 + 1][wspP2 + 1] == 22)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 + 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (wspK2 < wspP2 && wspK1 > wspP1)
                {
                    if (tab[wspP1 + 1][wspP2 - 1] == 2)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 + 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 + 1][wspP2 - 1] == 22)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 + 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (wspK2 > wspP2 && wspK1 < wspP1)
                {
                    if (tab[wspP1 - 1][wspP2 + 1] == 2)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 - 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 - 1][wspP2 + 1] == 22)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 - 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (wspK2 < wspP2 && wspK1 < wspP1)
                {
                    if (tab[wspP1 - 1][wspP2 - 1] == 2)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 - 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 - 1][wspP2 - 1] == 22)
                    {
                        tab[wspK1][wspK2] = 1;
                        tab[wspP1 - 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }


            }
            else
            {
                return false;
            }

        }
        if (zbicieBP == false && zbicieBD == true)
        {
            cout << "Musisz dokona� obowi�zkowego zbicia " << endl;
            cout << endl;
            pokazaniePlanszy(plansza, wielkosc_planszy);
            return false;
        }
        if (zbicieBP == false && zbicieBD == false)
        {
            if ((wspK1 - wspP1) == 1 && abs(wspK2 - wspP2) == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    // deklaracja zmiennych, kt�re b�d� przechowywaly aktualne warto�ci indeks�w
    int k;
    int g;
    int a;
    int b;
    if (tab[wspP1][wspP2] == 11)
    {
        if (zbicieBD == true)
        {
            if (wspK1 > wspP1 && wspK2 > wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 2 && tab[a][b] != 22) && a != wspK1)
                {
                    a++;
                    b++;
                    if (tab[a][b] == 1 || tab[a][b] == 11)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a++;
                b++;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a++;
                    b++;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (wspK1 > wspP1 && wspK2 < wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 2 && tab[a][b] != 22) && a != wspK1)
                {
                    a++;
                    b--;
                    if (tab[a][b] == 1 || tab[a][b] == 11)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a++;
                b--;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a++;
                    b--;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (wspK1 < wspP1 && wspK2 > wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 2 && tab[a][b] != 22) && a != wspK1)
                {
                    a--;
                    b++;
                    if (tab[a][b] == 1 || tab[a][b] == 11)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a--;
                b++;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a--;
                    b++;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (wspK1 < wspP1 && wspK2 < wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 2 && tab[a][b] != 22) && a != wspK1)
                {
                    a--;
                    b--;
                    if (tab[a][b] == 1 || tab[a][b] == 11)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a--;
                b--;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a--;
                    b--;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        if (zbicieBP == true && zbicieBD == false)
        {
            cout << "Musisz dokona� obowi�zkowego zbicia" << endl;
            cout << endl;
            pokazaniePlanszy(plansza, wielkosc_planszy);
            return false;
        }
        if (zbicieBP == false && zbicieBD == false)
        {
            if (wspK1 > wspP1 && wspK2 > wspP2)
            {
                a = wspP1 + 1;
                b = wspP2 + 1;
                k = wspK1 - 1;
                g = wspK2 - 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a++;
                    b++;
                }
                return true;
            }
            if (wspK1 > wspP1 && wspK2 < wspP2)
            {
                a = wspP1 + 1;
                b = wspP2 - 1;
                k = wspK1 - 1;
                g = wspK2 + 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a++;
                    b--;
                }
                return true;
            }
            if (wspK1 < wspP1 && wspK2 > wspP2)
            {
                a = wspP1 - 1;
                b = wspP2 + 1;
                k = wspK1 + 1;
                g = wspK2 - 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a--;
                    b++;
                }
                return true;
            }
            if (wspK1 < wspP1 && wspK2 < wspP2)
            {
                a = wspP1 - 1;
                b = wspP2 - 1;
                k = wspK1 + 1;
                g = wspK2 + 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a--;
                    b--;
                }
                return true;
            }
        }
    }
    if (tab[wspP1][wspP2] == 2)
    {
        if (zbicieCZP == true)
        {
            if (abs(wspK1 - wspP1) == 2 && abs(wspK2 - wspP2) == 2)
            {
                if (wspK2 > wspP2 && wspK1 > wspP1)
                {
                    if (tab[wspP1 + 1][wspP2 + 1] == 1)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 + 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 + 1][wspP2 + 1] == 11)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 + 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (wspK2 < wspP2 && wspK1 > wspP1)
                {
                    if (tab[wspP1 + 1][wspP2 - 1] == 1)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 + 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 + 1][wspP2 - 1] == 11)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 + 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (wspK2 > wspP2 && wspK1 < wspP1)
                {
                    if (tab[wspP1 - 1][wspP2 + 1] == 1)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 - 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 - 1][wspP2 + 1] == 11)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 - 1][wspP2 + 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (wspK2 < wspP2 && wspK1 < wspP1)
                {
                    if (tab[wspP1 - 1][wspP2 - 1] == 1)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 - 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else if (tab[wspP1 - 1][wspP2 - 1] == 11)
                    {
                        tab[wspK1][wspK2] = 2;
                        tab[wspP1 - 1][wspP2 - 1] = 0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            else
            {
                return false;
            }

        }
        if (zbicieCZP == false && zbicieCZD == true)
        {
            cout << "Musisz dokona� obowi�zkowego zbicia" << endl;
            cout << endl;
            pokazaniePlanszy(plansza, wielkosc_planszy);
            return false;
        }
        if (zbicieCZP == false && zbicieCZD == false)
        {
            if ((wspK1 - wspP1) == -1 && abs(wspK2 - wspP2) == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (tab[wspP1][wspP2] == 22)
    {
        if (zbicieCZD == true)
        {
            if (wspK1 > wspP1 && wspK2 > wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 1 && tab[a][b] != 11) && a != wspK1)
                {
                    a++;
                    b++;
                    if (tab[a][b] == 2 || tab[a][b] == 22)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a++;
                b++;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a++;
                    b++;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (wspK1 > wspP1 && wspK2 < wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 1 && tab[a][b] != 11) && a != wspK1)
                {
                    a++;
                    b--;
                    if (tab[a][b] == 2 || tab[a][b] == 22)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a++;
                b--;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a++;
                    b--;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (wspK1 < wspP1 && wspK2 > wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 1 && tab[a][b] != 11) && a != wspK1)
                {
                    a--;
                    b++;
                    if (tab[a][b] == 2 || tab[a][b] == 22)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a--;
                b++;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a--;
                    b++;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (wspK1 < wspP1 && wspK2 < wspP2)
            {
                a = wspP1;
                b = wspP2;
                while ((tab[a][b] != 1 && tab[a][b] != 11) && a != wspK1)
                {
                    a--;
                    b--;
                    if (tab[a][b] == 2 || tab[a][b] == 22)
                    {
                        return false;
                    }
                }
                if (a == wspK1)
                {
                    return false;
                }
                k = a;
                g = b;
                a--;
                b--;
                while (a != wspK1 && tab[a][b] == 0)
                {
                    a--;
                    b--;
                }
                if (a == wspK1)
                {
                    tab[wspK1][wspK2] = tab[wspP1][wspP2];
                    tab[k][g] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        if (zbicieCZP == true && zbicieCZD == false)
        {
            cout << "Musisz dokona� obowi�zkowego zbicia" << endl;
            cout << endl;
            pokazaniePlanszy(plansza, wielkosc_planszy);
            return false;
        }
        if (zbicieCZP == false && zbicieCZD == false)
        {
            if (wspK1 > wspP1 && wspK2 > wspP2)
            {
                a = wspP1 + 1;
                b = wspP2 + 1;
                k = wspK1 - 1;
                g = wspK2 - 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a++;
                    b++;
                }
                return true;
            }
            if (wspK1 > wspP1 && wspK2 < wspP2)
            {
                a = wspP1 + 1;
                b = wspP2 - 1;
                k = wspK1 - 1;
                g = wspK2 + 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a++;
                    b--;
                }
                return true;
            }
            if (wspK1 < wspP1 && wspK2 > wspP2)
            {
                a = wspP1 - 1;
                b = wspP2 + 1;
                k = wspK1 + 1;
                g = wspK2 - 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a--;
                    b++;
                }
                return true;
            }
            if (wspK1 < wspP1 && wspK2 < wspP2)
            {
                a = wspP1 - 1;
                b = wspP2 - 1;
                k = wspK1 + 1;
                g = wspK2 + 1;
                while (a != k)
                {
                    if (tab[a][b] != 0)
                    {
                        return false;
                    }
                    a--;
                    b--;
                }
                return true;
            }
        }
    }
    return false;
}
// funkcja, kt�ra sprawdza ile jest figur bia�ych
int liczbaFigurBialych(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    int ilosc = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] == 1 || tab[i][j] == 11)
            {
                ilosc++;
            }
        }
    }
    return ilosc;
}

// funkcja, ktora sprawdza ile jest figur czerwonych
int liczbaFigurCzerwonych(int tab[wielkosc_planszy][wielkosc_planszy], int rozmiar)
{
    int ilosc = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (tab[i][j] == 2 || tab[i][j] == 22)
            {
                ilosc++;
            }
        }
    }
    return ilosc;
}
// funkcja, kt�ra sprawdza czy gracz, ktory ma biale moze wykona� jakikolwiek ruch
int main()
{

    // Ustawienie pocz�tkowego uk�adu planszy
    konwersjaPlanszyNaTablice(plansza, wielkosc_planszy);

    cout << "W A R C A B Y   K L A S Y C Z N E  P L U S" << endl;
    /*jezykUzytkownika = "w";
    cout << "" << endl;
    cout << "Wybierz j�zyk (Select language) - E-English    P-Polski" << endl;
    while (jezykUzytkownika != 'E' && jezykUzytkownika != 'P')
    {
        cin >> jezykUzytkownika;
    }
    string jezyk = "";
    if (jezykUzytkownika == "P")
        {
        jezyk = "POLSKI";
        }
    else
        {
        jezyk = "ENGLISH";
        }

    cout << "Wybrany j�zyk: " + jezyk + "" << endl;
    */

    cout << "" << endl;


    // Pokazanie pocz�tkowe uk�adu planszy    

    pokazaniePlanszy(plansza, wielkosc_planszy);

    // zmienna, kt�ra informuje, jaka jest aktualna kolejka
    int kolejka = 1;

    // zmienna, kt�ra informuje czy gra jest sko�czona czy nie
    bool czyKoniecGry = false;

    /* zmienna, kt�ra informuj� ile gracze wykonali ruch�ww damami bez zmniejszania liczby
    pionow, pozostaj�cych na planszy */
    int ruchyDamamiBezZbicia = 0;

    // zmienna, kt�ra sprawdza czy dany ruch jest dozwolony
    bool dozwolony;

    // zmienne, kt�re sprawdzaj� ile figur danego koloru jest na planszy przed i po ruchu
    int bialePrzed;
    int bialePo;
    int czerwonePrzed;
    int czerwonePo;

    // zmienna, kt�ra sprawdza czy mo�liwe jest zbicie
    bool zbicieBialaDama;
    bool zbicieBialymPionkiem;
    bool zbicieCzerwonymPionkiem;
    bool zbicieCzerwonaDama;
    bool zbicie;

    // zmienne, kt�re informuj� o wspo�rz�dnych pionka lub figury
    char wsp2litP;
    int wsp1P;
    int wsp2P;
    char wsp2litK;
    int wsp1K;
    int wsp2K;

    // zmienna, kt�ra sprawdza ile razy u�ytkownik wykona� nieprawid�owy ruch
    int prawidlowyRuch = 0;

    // zmienna, kt�ra ustala j�zyk rozgrywki
    // char jezykUzytkownika;

    // dozwolone wsp�rz�de X dla ruch�w pionkiem
    set<char> zbiorDozwolonychX = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    // dozwolone wsp�rz�de Y dla ruch�w pionkiem
    set<int> zbiorDozwolonychY = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int ileElementow;

    cout << "P O C Z � T E K   P O J E D Y N K U " << endl;
    cout << endl;

    // p�tla, w ktorej zostaje realizowana rozgrywka - gracze wykonuj� ruchy
    while (czyKoniecGry == false)
    {
        bool flaga = true;
        dozwolony = true;
        prawidlowyRuch = 0;
        if (kolejka % 2 == 1)
        {
            cout << "Ruch gracza, kt�ry ma bia�e figury (pionki oznaczone 1 oraz damki 11)" << endl;
            cout << endl;
            while (flaga == true)
            {
                if (prawidlowyRuch >= 5)
                {
                    cout << """Gracz, ktory ma biale figury przegra�, poniewaz pope�ni� zbyt wiele nieprawid�owych wpis�w """ << endl;
                    czyKoniecGry = true;
                    break;
                }
                cout << "Podaj pozycj� pocz�tkow� tj. na kt�rej znajduje si� figura, kt�r� chcesz zagra�:" << endl;
                cout << "Wsp�rz�dna X (od A do H): ";
                ileElementow = 0;
                while (ileElementow == 0)
                {
                    cin >> wsp2litP;
                    ileElementow = zbiorDozwolonychX.count(wsp2litP);
                }

                cout << "";
                cout << "Wsp�rz�dna Y (od 1 do 8): ";
                ileElementow = 0;
                while (ileElementow == 0)
                {
                    cin >> wsp1P;
                    ileElementow = zbiorDozwolonychY.count(wsp1P);
                }

                wsp2P = int(wsp2litP) - 65;
                wsp1P = wsp1P - 1;
                if (wsp1P < 0 || wsp1P >= wielkosc_planszy || wsp2P < 0 || wsp2P >= wielkosc_planszy)
                {
                    cout << "Nie ma mo�liwo�ci wyboru takiego pola na planszy. Musisz wybra� wsp�rz�dne jeszcze raz.";
                    cout << endl;
                    pokazaniePlanszy(plansza, wielkosc_planszy);
                    prawidlowyRuch++;
                }
                else if (plansza[wsp1P][wsp2P] == 1 || plansza[wsp1P][wsp2P] == 11)
                {
                    if (bicieBialymPionkiem(plansza, wielkosc_planszy) == true)
                    {
                        zbicieBialymPionkiem = true;
                    }
                    if (bicieBialymPionkiem(plansza, wielkosc_planszy) == false)
                    {
                        zbicieBialymPionkiem = false;
                    }
                    if (bicieCzerwonymPionkiem(plansza, wielkosc_planszy) == true)
                    {
                        zbicieCzerwonymPionkiem = true;
                    }
                    if (bicieCzerwonymPionkiem(plansza, wielkosc_planszy) == false)
                    {
                        zbicieCzerwonymPionkiem = false;
                    }
                    if (bicieBialaDama(plansza, wielkosc_planszy) == true)
                    {
                        zbicieBialaDama = true;
                    }
                    if (bicieBialaDama(plansza, wielkosc_planszy) == false)
                    {
                        zbicieBialaDama = false;
                    }
                    if (bicieCzerwonaDama(plansza, wielkosc_planszy) == true)
                    {
                        zbicieCzerwonaDama = true;
                    }
                    if (bicieCzerwonaDama(plansza, wielkosc_planszy) == false)
                    {
                        zbicieCzerwonaDama = false;
                    }
                    if (bicieBialymPionkiem(plansza, wielkosc_planszy) == true || bicieBialaDama(plansza, wielkosc_planszy) == true)
                    {
                        zbicie = true;
                    }
                    else
                    {
                        zbicie = false;
                    }
                    cout << "Podaj pozycj� docelow� tj. na kt�r� zostaje przemieszczona figura, kt�r� chcesz zagra�:" << endl;
                    cout << "Wsp�rz�dna X (od A do H): ";
                    ileElementow = 0;
                    while (ileElementow == 0)
                    {
                        cin >> wsp2litK;
                        ileElementow = zbiorDozwolonychX.count(wsp2litK);
                    }

                    cout << "";
                    cout << "Wsp�rz�dna Y (od 1 do 8):";
                    ileElementow = 0;
                    wsp1K = 0;
                    while (ileElementow == 0)
                    {
                        cin >> wsp1K;
                        ileElementow = zbiorDozwolonychY.count(wsp1K);
                    }

                    wsp2K = int(wsp2litK) - 65;
                    wsp1K = wsp1K - 1;
                    czerwonePrzed = liczbaFigurCzerwonych(plansza, wielkosc_planszy);
                    if (wsp1K < 0 || wsp1K >= wielkosc_planszy || wsp2K < 0 || wsp2K >= wielkosc_planszy)
                    {
                        cout << "Nie ma mo�liwo�ci wyboru takiego pola na planszy. Musisz wybra� wsp�rz�dne jeszcze raz.";
                        cout << endl;
                        pokazaniePlanszy(plansza, wielkosc_planszy);
                        prawidlowyRuch++;
                    }
                    else if (dozwolonyRuch(plansza, wielkosc_planszy, wsp1P, wsp2P, wsp1K, wsp2K, zbicieBialymPionkiem, zbicieBialaDama, zbicieCzerwonymPionkiem, zbicieCzerwonaDama, ruchyDamamiBezZbicia) == true)
                    {
                        plansza[wsp1K][wsp2K] = plansza[wsp1P][wsp2P];
                        plansza[wsp1P][wsp2P] = 0;
                        czerwonePo = liczbaFigurCzerwonych(plansza, wielkosc_planszy);
                        if (zbicieBialymPionkiem == false && zbicieBialaDama == false)
                        {
                            if (plansza[wsp1K][wsp2K] == 1 && wsp1K == 7)
                            {
                                plansza[wsp1K][wsp2K] = 11;
                            }
                            kolejka++;
                        }
                        else if (bicieBialymPionkiem(plansza, wielkosc_planszy) == false && bicieBialaDama(plansza, wielkosc_planszy) == false)
                        {
                            if (plansza[wsp1K][wsp2K] == 1 && wsp1K == 7)
                            {
                                plansza[wsp1K][wsp2K] = 11;
                            }
                            kolejka++;
                        }
                        else
                        {
                            cout << "Kolejka tego samego gracza, poniewaz powinien dokona� obowi�zkowe zbicie" << endl;
                        }
                        if (plansza[wsp1K][wsp2K] == 11 && czerwonePrzed == czerwonePo)
                        {
                            ruchyDamamiBezZbicia++;
                        }
                        if (plansza[wsp1K][wsp2K] == 11 && czerwonePrzed > czerwonePo)
                        {
                            ruchyDamamiBezZbicia = 0;
                        }
                        flaga = false;
                    }
                    else
                    {
                        cout << "Musisz wybra� wspo�rz�dne jeszcze raz." << endl;
                        cout << endl;
                        pokazaniePlanszy(plansza, wielkosc_planszy);
                        prawidlowyRuch++;
                    }

                }
                else
                {
                    cout << "Nie mo�esz tego zrobic. Musisz wybra� wspo�rz�dn� jeszcze raz.";
                    cout << endl;
                    pokazaniePlanszy(plansza, wielkosc_planszy);
                }

            }

        }
        else
        {
            cout << "Ruch gracza, kt�ry ma czerwone figury" << endl;
            cout << endl;
            while (flaga == true)
            {
                if (prawidlowyRuch >= 5)
                {
                    cout << """Gracz, ktory ma czerwone figury przegra�, poniewaz pope�ni� zbyt wiele nieprawid�owych wpis�w""" << endl;
                    czyKoniecGry = true;
                    break;
                }
                cout << "Podaj pozycj� pocz�tkow� tj. na kt�rej znajduje si� figura, kt�r� chcesz zagra�:" << endl;
                cout << "Wsp�rz�dna X (od A do H): ";
                ileElementow = 0;
                while (ileElementow == 0)
                {
                    cin >> wsp2litP;
                    ileElementow = zbiorDozwolonychX.count(wsp2litP);
                }

                cout << "";
                cout << "Wsp�rz�dna Y (od 1 do 8): ";
                ileElementow = 0;
                while (ileElementow == 0)
                {
                    cin >> wsp1P;
                    ileElementow = zbiorDozwolonychY.count(wsp1P);
                }

                cout << "";
                wsp2P = int(wsp2litP) - 65;
                wsp1P = wsp1P - 1;
                if (wsp1P < 0 || wsp1P >= wielkosc_planszy || wsp2P < 0 || wsp2P >= wielkosc_planszy)
                {
                    cout << "Nie ma mo�liwo�ci wyboru takiego pola na planszy. Musisz wybra� wsp�rz�dne jeszcze raz.";
                    cout << endl;
                    prawidlowyRuch++;
                    pokazaniePlanszy(plansza, wielkosc_planszy);
                }
                else if (plansza[wsp1P][wsp2P] == 2 || plansza[wsp1P][wsp2P] == 22)
                {
                    if (bicieCzerwonymPionkiem(plansza, wielkosc_planszy) == true)
                    {
                        zbicieCzerwonymPionkiem = true;
                    }
                    if (bicieCzerwonymPionkiem(plansza, wielkosc_planszy) == false)
                    {
                        zbicieCzerwonymPionkiem = false;
                    }
                    if (bicieCzerwonaDama(plansza, wielkosc_planszy) == true)
                    {
                        zbicieCzerwonaDama = true;
                    }
                    if (bicieCzerwonaDama(plansza, wielkosc_planszy) == false)
                    {
                        zbicieCzerwonaDama = false;
                    }
                    if (bicieCzerwonymPionkiem(plansza, wielkosc_planszy) == true || bicieCzerwonaDama(plansza, wielkosc_planszy) == true)
                    {
                        zbicie = true;
                    }
                    else
                    {
                        zbicie = false;
                    }
                    cout << "Podaj pozycj� docelow� tj. na kt�r� zostaje przemieszczona figura, kt�r� chcesz zagra�:" << endl;
                    cout << "Wsp�rz�dna X (od A do H): ";
                    ileElementow = 0;
                    while (ileElementow == 0)
                    {
                        cin >> wsp2litK;
                        ileElementow = zbiorDozwolonychX.count(wsp2litK);
                    }

                    cout << "Wsp�rz�dna Y (od 1 do 8): ";
                    ileElementow = 0;
                    while (ileElementow == 0)
                    {
                        cin >> wsp1K;
                        ileElementow = zbiorDozwolonychY.count(wsp1K);
                    }

                    wsp2K = int(wsp2litK) - 65;
                    wsp1K = wsp1K - 1;
                    bialePrzed = liczbaFigurBialych(plansza, wielkosc_planszy);
                    if (wsp1K < 0 || wsp1K >= wielkosc_planszy || wsp2K < 0 || wsp2K >= wielkosc_planszy)
                    {
                        cout << "Nie ma mo�liwo�ci wyboru takiego pola na planszy. Musisz wybra� wsp�rz�dne jeszcze raz.";
                        cout << endl;
                        prawidlowyRuch++;
                        pokazaniePlanszy(plansza, wielkosc_planszy);
                    }
                    else if (dozwolonyRuch(plansza, wielkosc_planszy, wsp1P, wsp2P, wsp1K, wsp2K, zbicieBialymPionkiem, zbicieBialaDama, zbicieCzerwonymPionkiem, zbicieCzerwonaDama, ruchyDamamiBezZbicia) == true)
                    {
                        plansza[wsp1K][wsp2K] = plansza[wsp1P][wsp2P];
                        plansza[wsp1P][wsp2P] = 0;
                        bialePo = liczbaFigurBialych(plansza, wielkosc_planszy);
                        if (zbicieCzerwonymPionkiem == false && zbicieCzerwonaDama == false)
                        {
                            if (plansza[wsp1K][wsp2K] == 2 && wsp1K == 0)
                            {
                                plansza[wsp1K][wsp2K] = 22;
                            }
                            kolejka++;
                        }
                        else if (bicieCzerwonymPionkiem(plansza, wielkosc_planszy) == false && bicieCzerwonaDama(plansza, wielkosc_planszy) == false)
                        {
                            if (plansza[wsp1K][wsp2K] == 2 && wsp1K == 0)
                            {
                                plansza[wsp1K][wsp2K] = 22;
                            }
                            kolejka++;
                        }
                        else
                        {
                            cout << "Kolejka tego samego gracza, poniewa� powinien dokona� obowi�zkowe zbicie" << endl;
                        }
                        if (plansza[wsp1K][wsp2K] == 22 && czerwonePrzed == czerwonePo)
                        {
                            ruchyDamamiBezZbicia++;
                        }
                        if (plansza[wsp1K][wsp2K] == 22 && czerwonePrzed > czerwonePo)
                        {
                            ruchyDamamiBezZbicia = 0;
                        }
                        flaga = false;
                    }
                    else
                    {
                        cout << "Musisz wybra� wspo�rz�dne jeszcze raz" << endl;
                        cout << endl;
                        prawidlowyRuch++;
                        pokazaniePlanszy(plansza, wielkosc_planszy);
                    }
                }
                else
                {
                    cout << "Nie mo�esz tego zrobic. Musisz wybra� wsp�rz�dne jeszcze raz.";
                    cout << endl;
                    pokazaniePlanszy(plansza, wielkosc_planszy);
                }
            }
        }
        // pokazanie planszy po wykonaniu ruchu
        pokazaniePlanszy(plansza, wielkosc_planszy);

        if (liczbaFigurCzerwonych(plansza, wielkosc_planszy) == 0)
        {
            cout << "Gracz graj�cy bia�ymi figurami wygra� pojedynek" << endl;
            czyKoniecGry = true;
        }
        if (liczbaFigurBialych(plansza, wielkosc_planszy) == 0)
        {
            cout << "Gracz graj�cy czerwonymi figurami wygra� pojedynek" << endl;
            czyKoniecGry = true;
        }
        if (ruchyDamamiBezZbicia == 30)
        {
            cout << "Gra zako�czy�a si� remisem " << endl;
            czyKoniecGry = true;
        }
    }

}
