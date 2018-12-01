#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void dodajKlocek(int tab[ROZM+2][ROZM+2])
{
    int komorki[4]= {1,1, 1,1};
    wczytajStrukture(tab, "KLOCEK", 2, 2, komorki);
}

void dodajLodz(int tab[ROZM+2][ROZM+2])
{
    int komorki[9]= {0,1,0, 1,0,1, 0,1,0};
    wczytajStrukture(tab, "LODZ", 3, 3, komorki);
}

void dodajKoniczynka(int tab[ROZM+2][ROZM+2])
{
    int komorki[9]= {1,1,0, 1,0,1, 0,1,0};
    wczytajStrukture(tab, "KONICZYNKA", 3, 3, komorki);
}

void dodajStaw(int tab[ROZM+2][ROZM+2])
{
    int komorki[16]= {0,1,1,0, 1,0,0,1, 1,0,0,1, 0,1,1,0};
    wczytajStrukture(tab, "STAW", 4, 4, komorki);
}

void dodajKrysztal(int tab[ROZM+2][ROZM+2])
{
    int komorki[12]= {0,1,0, 1,0,1, 1,0,1, 0,1,0};
    wczytajStrukture(tab, "Krysztal", 4, 3, komorki);
}

void dodajBochenek(int tab[ROZM+2][ROZM+2])
{
    int komorki[16]= {0,1,1,0, 1,0,0,1, 1,0,1,0, 0,1,0,0};
    wczytajStrukture(tab, "BOCHENEK", 4, 4, komorki);
}

void dodajSzybowiec(int tab[ROZM+2][ROZM+2])
{
    int komorki[9]= {1,1,1, 1,0,0, 0,1,0};
    wczytajStrukture(tab, "SZYBOWIEC", 3, 3, komorki);
}

void dodajDakota(int tab[ROZM+2][ROZM+2])
{
    int komorki[20]= {0,1,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,1,1,1,0};
    wczytajStrukture(tab, "DAKOTA", 4, 5, komorki);
}

void dodajBlinker(int tab[ROZM+2][ROZM+2])
{
    int komorki[3]= {1,1,1};
    wczytajStrukture(tab, "BLINKER", 1, 3, komorki);
}

void dodajZabka(int tab[ROZM+2][ROZM+2])
{
    int komorki[16]= {0,1,1,0, 1,0,0,0, 0,0,0,1, 0,1,1,0};
    wczytajStrukture(tab, "ZABKA", 4, 4, komorki);
}

void dodajKrokodyl(int tab[ROZM+2][ROZM+2])
{
    int komorki[144]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,  0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,  0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                      };
    wczytajStrukture(tab, "KROKODYL", 9, 16, komorki);
}

void dodajFontanna(int tab[ROZM+2][ROZM+2])
{
    int komorki[45]= {0,0,1,1,0,1,1,0,0, 0,0,0,0,0,0,0,0,0, 0,0,0,1,0,1,0,0,0, 1,1,0,1,0,1,0,1,1, 1,1,1,0,0,0,1,1,1};
    wczytajStrukture(tab, "FONTANNA", 5, 9, komorki);
}

