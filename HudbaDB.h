#pragma once

#define ZNACKA_SIZE 21

struct t_hudba
{
    char  interpret[ZNACKA_SIZE];
    char  nazevalba[ZNACKA_SIZE];
    int   rok;
    struct t_hudba* dalsi;
};

void add(char* interpret, char* nazevalba, int rok, struct t_hudba** uk_prvni);
void del(int rok, struct t_hudba** uk_prvni);
