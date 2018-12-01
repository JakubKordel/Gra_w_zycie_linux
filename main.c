#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "menu.h"

int main()
{
    printf("---------------------------------------------\n");
    printf("GRA W ZYCIE");
    printf("\n---------------------------------------------\n");
    printf("Witaj! \nWlacz pelny ekran i wcisnij dwa razy enter\n");
    getchar();
    wyczyscBuf();
    int tab[ROZM+2][ROZM+2];
    wypelnijKomorki0(tab);
    int wybor;
    while (wybor!=8)
    {
        wypiszTytul("MENU GLOWNE", tab);
        printf("Wcisnij:\n");
        printf("1 - Aby uruchomic gre w zycie\n");
        printf("2 - Aby zmienic wszystkie komorki na martwe\n");
        printf("3 - Aby zapelnic zywymi\n");
        printf("4 - Aby dodac pojedyncza zywa komorke\n");
        printf("5 - Aby zmienic komorke na martwa\n");
        printf("6 - Aby wygenerowac plansze losowo\n");
        printf("7 - Aby dodac gotowe struktury zywych komorek\n");
        printf("8 - Aby zakonczyc gre\n");
        wybor=wczytajWybor();
        switch(wybor)
        {
        case 1:
            menuUruchamiania(tab);
            break;
        case 2:
            wypelnijKomorki0(tab);
            break;
        case 3:
            wypelnijKomorki1(tab);
            break;
        case 4:
            dodajZywa(tab);
            break;
        case 5:
            dodajMartwa(tab);
            break;
        case 6:
            wypelnijLosowo(tab);
            break;
        case 7:
            gotoweStruktury(tab);
            break;
        case 8:
            break;
        case 9:
            wypelnijLosowo50(tab);
            break;
        default:
            nieprawidlowyZnak();
            break;
        }
    }
    return 0;
}
