#!/usr/bin/env bash
gcc -Wall -o app liste_entiers.c liste_entiers.h test_liste.c
./app
rm app
