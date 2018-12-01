#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROZM 60

void rysujPlansze(int tab[ROZM+2][ROZM+2]); // wyswietla plansze komorek, skrajne wiersze i kolumny ze stalymi komorkami 0, nie sa wyswietlane
void odswierzEkran(int tab[ROZM+2][ROZM+2]); // czysci ekran i rysuje plansze
void wyczyscBuf (void); // czysci bufor
void nieprawidlowyZnak(void); //czysci bufor i wyswietla komunikat o nieprawidlowym znaku
void wypiszTytul (char tytul[20], int tab[ROZM+2][ROZM+2]); // odswierza ekran i Wypisuje naglowek o tresci tytul[20]
int wczytajWybor(void); // zwraca wczytana przez uzytkownika liczbe
int wczytajWiersz(int rozmx, int tab[ROZM+2][ROZM+2]); //wczytuje od uzytkownika numer wiersza lewego gornego wiercholka struktury o rozmiarze rozmx wierszy, bez mozliwosci wyjscia na brzeg
int wczytajKolumne(int rozmy, int tab[ROZM+2][ROZM+2]); //wczytuje od uzytkownika numer kolumny lewego gorneg wiercholka struktury o romiarze rozmy wierszy, bez mozliwosci wyjscia na brzeg
void wczytajStrukture(int tab[ROZM+2][ROZM+2], char nazwa[40], int wiersze, int kolumny, int komorki[]); //umozliwia uzytkownikowi wczytanie struktury o nazwie 'nazwa'
void dodajZywa(int tab[ROZM+2][ROZM+2]); // umozliwia uzytkownikowi dodanie jednej zywej komorki
void dodajMartwa(int tab[ROZM+2][ROZM+2]); //umozliwia uzytkownikowi dodanie jednej martwej komorki
void wypelnijKomorki0(int tab[ROZM+2][ROZM+2]); //wypelnia cala tablice zerami
void wypelnijLosowo(int tab[ROZM+2][ROZM+2]); // umozliwia uzytkownikowi wypelnienie tablicy losowo, z wyborem prawdopodobienstwa ze komorka bedzie zywa
void wypelnijKomorki1(int tab[ROZM+2][ROZM+2]); //wypelnia plansze jedynkami (brzegi pozostaja zerami)
bool wlaczIteracje(int tab[ROZM+2][ROZM+2]); // Zwraca false jesli uklad komorek sie nie zmienia, true jesli sie zmieni
bool znajdzZywa(int tab[ROZM+2][ROZM+2]); // Zwraca true jesli znajdzie zywa komorka, false jesli nie znajdzie
