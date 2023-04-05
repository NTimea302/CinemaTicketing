/**********************************************************/
/* Cinema Ticketing                                       */
/* Copyright:                                             */
/* License:                                               */
/* Authors: Nagy Timea, Nemes Raluca                      */
/* Version: 1                                             */
/* Updates:                                               */
/**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "InOut.h"
#include "InOut.c"
#include "Searches.h"
#include "MatrixManagement.c"

int main()
{
    Movie movie_list[50];
    int n = 0 , nr = 0, x = 0; //the number of movies
    char f = '\0';
    read_file(&movie_list, &n);
    srand(time(NULL));
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                x = rand()%3;
                if(x == 1)
                    movie_list[k].room_places[i*9+j] = 1;
                else
                if(x == 0)
                    movie_list[k].room_places[i*9+j] = 0;
                else
                    movie_list[k].room_places[i*9+j] = 0;
            }
        }

    }
   // display_file(movie_list, n);

    main_menu(movie_list, n);
    printf("\nPress any key to exit!\n");
    f = getch();
    exit(EXIT_SUCCESS);
    return 0;
}
