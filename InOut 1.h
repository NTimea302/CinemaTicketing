/**********************************************************/
/* InOut.h - All the functions for input and output       */
/* Copyright:                                             */
/* License:                                               */
/* Authors: Nagy Timea, Nemes Raluca                      */
/* Version:                                               */
/* Updates:                                               */
/**********************************************************/
#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
       char name[150];
       char type[5];
       char genre[30];
       char date[20];
       char hour[20];
       char age[5];
       char room[5];
       char room_places[100];
} Movie;

extern void main_menu();
extern void read_file(Movie[], int *n);
extern void display_file(Movie[], int n);
void choose_movie(Movie movie_list[100], int n);
void display_prices();

#endif // INOUT_H_INCLUDED
