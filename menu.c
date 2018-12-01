#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "struktury.h"
#include <unistd.h>

void menuUruchamiania(int tab[ROZM+2][ROZM+2])
{
    wypiszTytul("MENU URUCHAMIANIA", tab);
    int i=0, n;
    printf("Ile cyklow zycia komorek wykonac?: ");
    while(!scanf("%d", &n))
    {
        nieprawidlowyZnak();
        odswierzEkran(tab);
        printf("Ile cyklow zycia komorek wykonac?: ");
    }
    while (i<n && znajdzZywa(tab) && wlaczIteracje(tab))
    {
        odswierzEkran(tab);
        usleep(200000);
        ++i;
    }
    if (znajdzZywa(tab)==false)
    {

        printf("\nWszystkie komorki wyginely po %d cyklu/ach zycia\n", i);
        sleep(2);
    }
}

void gotoweStruktury(int tab[ROZM+2][ROZM+2])
{
    int wybor=1;
    while (wybor!=0)
    {
        wypiszTytul("DODAWANIE GOTOWYCH STRUKTUR", tab);
        printf("Wcisnij:\n");
        printf("0 - Aby wrocic\n");
        printf("Numer struktury aby ja podejrzec i dodac\n");
        printf("\nNiezmienne:\n");
        printf("1. Klocek\n");
        printf("2. Lodz\n");
        printf("3. Koniczynka\n");
        printf("4. Staw\n");
        printf("5. Krysztal\n");
        printf("6. Bochenek\n");
        printf("\nStatki:\n");
        printf("7. Szybowiec\n");
        printf("8. Dakota\n");
        printf("\nOscylatory:\n");
        printf("9. Blinker\n");
        printf("10. Zabka\n");
        printf("11. Krokodyl\n");
        printf("12. Fontanna\n");
        wybor=wczytajWybor();
        switch(wybor)
        {
        case 0:
            break;
        case 1:
            dodajKlocek(tab);
            break;
        case 2:
            dodajLodz(tab);
            break;
        case 3:
            dodajKoniczynka(tab);
            break;
        case 4:
            dodajStaw(tab);
            break;
        case 5:
            dodajKrysztal(tab);
            break;
        case 6:
            dodajBochenek(tab);
            break;
        case 7:
            dodajSzybowiec(tab);
            break;
        case 8:
            dodajDakota(tab);
            break;
        case 9:
            dodajBlinker(tab);
            break;
        case 10:
            dodajZabka(tab);
            break;
        case 11:
            dodajKrokodyl(tab);
            break;
        case 12:
            dodajFontanna(tab);
            break;
        default:
            nieprawidlowyZnak();
            break;
        }
    }
}

