#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funkcje.h"
#include <time.h>
#include <stdbool.h>

void rysujPlansze(int tab[ROZM+2][ROZM+2])
{
    for (int i=0; i<(ROZM)*2+1; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
        {
            printf("|%c", (tab[i][j] ? 'O' : ' '));
        }
        printf("|\n");
    }
    for (int i=0; i<(ROZM)*2+1; i++)
    {
        printf("-");
    }
    printf("\n");
}

void odswierzEkran(int tab[ROZM+2][ROZM+2])
{
    printf("\n");
    system("clear");
    rysujPlansze(tab);
}

void wyczyscBuf ()
{
    char c;
    do
        c=getchar();
    while
    (c!='\n' && c!=EOF);
}

void nieprawidlowyZnak()
{
    printf("\nNieprawidlowy znak!\n");
    wyczyscBuf();
    sleep(1);
}

void wypiszTytul(char tytul[40],int tab[ROZM+2][ROZM+2])
{
    odswierzEkran(tab);
    printf("\n---------------------------------------------\n");
    printf("%s", tytul);
    printf("\n---------------------------------------------\n");
}

int wczytajWybor(void)
{
    int wybor;
    printf("---------------------------------------------\n");
    printf("Twoj wybor: ");
    scanf("%d", &wybor);
    return wybor;
}

int wczytajWiersz(int rozmx, int tab[ROZM+2][ROZM+2])
{
    int i;
    printf("Wprowadz\n");
    printf("Numer wiersza(1-%d): ", ROZM+1-rozmx);
    while(scanf("%d", &i)!=1 || !(i>=1 && i<=ROZM+1-rozmx))
    {
        nieprawidlowyZnak();
        odswierzEkran(tab);
        printf("Numer wiersza(1-%d): ", ROZM+1-rozmx);
    }
    return i;
}

int wczytajKolumne(int rozmy, int tab[ROZM+2][ROZM+2])
{
    int j;
    printf("Numer kolumny(1-%d): ", ROZM+1-rozmy);
    while(scanf("%d", &j)!=1 || !(j>=1 && j<=ROZM+1-rozmy))
    {
        nieprawidlowyZnak();
        odswierzEkran(tab);
        printf("Numer kolumny(1-%d): ", ROZM+1-rozmy);
    }
    return j;
}

void wczytajStrukture(int tab[ROZM+2][ROZM+2], char nazwa[40], int wiersze, int kolumny, int komorki[])
{
    wypiszTytul(nazwa, tab);
    int licznik=0;
    for (int i=0; i<wiersze; ++i)
    {
        for (int j=0; j<kolumny; ++j)
        {
            printf("|%c", (komorki[licznik] ? 'O' : ' '));
            ++licznik;
        }
        printf("|\n");
    }
    printf("\n0 - Wroc\n");
    printf("1 - Dodaj\n");
    int wybor;
    scanf("%d", &wybor);
    if (wybor==1)
    {
        printf("Wspolrzedne lewego gornego wierzcholka: \n");
        licznik=0;
        int i, j;
        i=wczytajWiersz(wiersze,tab);
        j=wczytajKolumne(kolumny,tab);
        for (int n=i; n<i+wiersze; ++n)
        {
            for (int k=j; k<j+kolumny; ++k)
            {
                tab[n][k]=komorki[licznik];
                ++licznik;
            }
        }
    }
}

void dodajZywa(int tab[ROZM+2][ROZM+2])
{
    wypiszTytul("DODAWANIE ZYWEJ KOMORKI", tab);
    tab[wczytajWiersz(1,tab)][wczytajKolumne(1,tab)]=1;
}

void dodajMartwa(int tab[ROZM+2][ROZM+2])
{
    wypiszTytul("DODAWANIE MARTWEJ KOMORKI", tab);
    tab[wczytajWiersz(1,tab)][wczytajKolumne(1,tab)]=0;
}

void wypelnijKomorki0(int tab[ROZM+2][ROZM+2])
{
    for (int i=0; i<ROZM+2; ++i)
    {
        for (int j=0; j<ROZM+2; ++j)
            tab[i][j]=0;
    }
}

void wypelnijLosowo(int tab[ROZM+2][ROZM+2])
{
    int procent;
    int x;
    printf("\nPodaj jakie chcesz prawdopodobienstwo by komorki byly zywe(0-100)%%: ");
    while(scanf("%d", &procent)!=1 || !(procent>=0 && procent<=100))
    {
        nieprawidlowyZnak();
        odswierzEkran(tab);
        printf("\nPodaj jakie chcesz prawdopodobienstwo by komorki byly zywe(0-100)%%: ");
    }
    printf("\n");
    int zarodek;
    time_t tt;
    zarodek=time(&tt);
    srand(zarodek);
    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
        {
            x=rand()%100;
            if (x<procent)
                tab[i][j]=1;
            else
                tab[i][j]=0;
        }
    }
}

void wypelnijKomorki1(int tab[ROZM+2][ROZM+2])
{
    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
            tab[i][j]=1;
    }
}

bool wlaczIteracje(int tab[ROZM+2][ROZM+2])
{
    int bufor[ROZM+2][ROZM+2];
    int suma;
    wypelnijKomorki0(bufor);
    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
        {
            suma=tab[i-1][j-1]+tab[i][j-1]+tab[i+1][j-1]+tab[i+1][j]+tab[i+1][j+1]+tab[i][j+1]+tab[i-1][j+1]+tab[i-1][j];
            if (tab[i][j]==0)
            {
                if (suma==3)
                    bufor[i][j]=1;
            }
            else if (suma==2 || suma==3)
                bufor[i][j]=1;
        }
    }
    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
        {
            if (tab[i][j]!=bufor[i][j])
            {
                i=ROZM+1;
                break;
            }
            if (i==ROZM && j==ROZM)
            {
                printf("\nUklad staly!\n");
                sleep(2);
                return false;
            }
        }
    }

    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
            tab[i][j]=bufor[i][j];
    }
    return true;
}

bool znajdzZywa(int tab[ROZM+2][ROZM+2])
{
    for (int i=1; i<ROZM+1; ++i)
    {
        for (int j=1; j<ROZM+1; ++j)
            if (tab[i][j]==1)
                return true;
    }
    return false;
}


