#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HudbaDB.h"

void add(char* interpret, char* nazevalba, int rok, struct t_hudba** uk_prvni)
{
	struct t_hudba* novaHudba;
	struct t_hudba* aktHudba;

	
	novaHudba = (struct t_hudba*)malloc(sizeof(struct t_hudba));

	strcpy_s(novaHudba->interpret, ZNACKA_SIZE, interpret);
	novaHudba->rok = rok;
	strcpy_s(novaHudba->nazevalba, ZNACKA_SIZE, nazevalba);
	novaHudba->dalsi = NULL;

	aktHudba = *uk_prvni;

	if (*uk_prvni == NULL) 
	{
		*uk_prvni = novaHudba;
		return;
	}
	else if ((strcmp(novaHudba->interpret, aktHudba->interpret)) < 0) 
	{
		novaHudba->dalsi = *uk_prvni;
		*uk_prvni = novaHudba;
		return;
	}



	while (aktHudba)
	{
		if (aktHudba->dalsi == NULL)
		{
			aktHudba->dalsi = novaHudba;
			return;
		}
		else if ((strcmp(novaHudba->interpret, aktHudba->interpret)) < 0)
			
		{
			novaHudba->dalsi = aktHudba->dalsi;
			aktHudba->dalsi = novaHudba;
			return;
		}
		aktHudba = aktHudba->dalsi;
	}
}

void del(int rok, struct t_hudba** uk_prvni)
{
	struct t_hudba* aktHudba;

	while (*uk_prvni && (*uk_prvni)->rok == rok)
	{
		struct t_hudba* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni); 
		*uk_prvni = newPrvni;
	}

	aktHudba = *uk_prvni;
	while (aktHudba && aktHudba->dalsi)
	{
		if (aktHudba->dalsi->rok == rok)
		{
			struct t_hudba* newDalsi = aktHudba->dalsi->dalsi;
			free(aktHudba->dalsi);
			aktHudba->dalsi = newDalsi;
		}
		aktHudba = aktHudba->dalsi;
	}
}