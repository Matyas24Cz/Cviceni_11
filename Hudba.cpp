

#include "Hudba.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>	

#include "HudbaDB.h"

struct t_hudba* prvni = NULL;
int vyhlrok;

void OnAdd()
{
	char my_name[ZNACKA_SIZE];
	char my_album[ZNACKA_SIZE];
	int my_year;

	printf("\nNazev interpreta: ");
	scanf_s("%s", my_name, ZNACKA_SIZE);
	while (getchar() != '\n');
	printf("\nNazev alba: ");
	scanf_s("%s", my_album, ZNACKA_SIZE);
	while (getchar() != '\n');
	printf("\nRok vydani: ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	add(my_name, my_album, my_year, &prvni);
}

void OnDel()
{
	int my_year;

	printf("\nRok vydani: ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	del(my_year, &prvni);
}

void ShowCars()
{
	struct t_hudba* aktHudba = prvni;
	printf("\nZadejte rok: ");
	scanf("%d", &vyhlrok);
	while (aktHudba)
	{

		if (vyhlrok == aktHudba->rok) {
			printf_s("Nazev interpreta: %s Rok vydani: %d  Nazev alba: %s\n", aktHudba->interpret, aktHudba->rok, aktHudba->nazevalba);

		}
		aktHudba = aktHudba->dalsi;

	}
	while (getchar() != '\n');
}


int main()
{
	char  cmd;

	do
	{
		
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();
			break;
		case 'd':
			OnDel();
			break;
		case 'p':
			ShowCars();
			break;
		}
	} while (cmd != 'q');
	return 0;
}


