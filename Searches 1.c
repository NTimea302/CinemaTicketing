/**********************************************************/
/* Searches.c - See Searches.h for copyright and info     */
/**********************************************************/
#include <stdbool.h>
#include "Searches.h"

void type_file(Movie movie_list[100], int n)
{
   printf("What type of movie would you like to see?\n");
   char type[5] = "\0";
   scanf("%s", type);
   for(int cnt = 0; cnt <= strlen(type); cnt++)
        type[cnt] = toupper(type[cnt]);
   while (!((strcmp(type, "2D") == 0) || (strcmp(type, "3D") == 0) || (strcmp(type, "4DX") == 0) || (strcmp(type, "7D") == 0)))    //If the entered string does not have the correct format
   {
            printf("The entered string is not a movie type! Please try again!\n");
            scanf("%s", type);
   }
   bool exist_movie = 0;
   printf("Name \t\t\t");
   printf("| Genre\t\t");
   printf("| Date \t\t");
   printf("| Time \t");
   printf("| Room \t\t");
   printf("| Age  \t\n");
   for(int i = 0; i <= n; i++)
   {
        if (strcmp(movie_list[i].type, type) == 0)
        {
            exist_movie = 1;
            printf("%s\t", movie_list[i].name);
            printf("| %s\t", movie_list[i].genre);
            printf("| %s\t", movie_list[i].date);
            if(strcmp(movie_list[i].hour, "Coming soon") != 0)
                printf("| %s\t", movie_list[i].hour);
            else
                printf("| -\t");
            printf("| room %s\t", movie_list[i].room);
            printf("| %s+\t\n", movie_list[i].age);
        }
   }
   if(!exist_movie)
    printf("Right now there are no movies of type %s, please search for another type or try again in a few days!", type);
   display_prices();
   choose_movie(movie_list, n);
}


void date_file(Movie movie_list[100], int n)
{
    bool exist_movie = 0;
    char date[20] = "\0";
    printf("Tell us the date you would like to see the movie (yyyy/mm/dd)\n");
    label:
    scanf("%s", date);
    for(int i = 0; i <= n; i++)
        if(strcmp(movie_list[i].date, date) == 0)
            exist_movie = 1;
    if(exist_movie)
    {
        printf("Name \t\t\t");
        printf("| Genre\t\t");
        printf("| Type \t");
        printf("| Hour \t");
        printf("| Room   ");
        printf("| Age  \t\n");
    }
    exist_movie = 0;
       for(int i = 0; i <= n; i++)
       {
           if(strcmp(movie_list[i].date, date) == 0)
           {
                exist_movie = 1;
                printf("%s\t", movie_list[i].name);
                printf("| %s\t", movie_list[i].genre);
                printf("| %s\t", movie_list[i].type);
                printf("| %s\t", movie_list[i].hour);
                printf("| room %s ", movie_list[i].room);
                printf("| %s+\t\n", movie_list[i].age);
           }
       }
       if(!exist_movie)
       {
           printf("Right now there are no movies on %s available, please enter another date!\n", date);
           goto label;
       }
       display_prices();
       choose_movie(movie_list, n);
}

void genre_file(Movie movie_list[100], int n)
{

    printf("The genre of the movie you would like to see (Romantic/Sci-Fi/Holidays/Action/Horror/Comedy/Thriller/Athletics/Animation)\n");
    char genre[20] = "\0";
    scanf("%s", genre);
    genre[0] = toupper(genre[0]);
    while (!((strcmp(genre, "Romantic") == 0) || (strcmp(genre, "Sci-Fi") == 0) || (strcmp(genre, "Holidays") == 0) || (strcmp(genre, "Action") == 0) || (strcmp(genre, "Horror") == 0) || (strcmp(genre, "Comedy") == 0) || (strcmp(genre, "Thriller") == 0) || (strcmp(genre, "Athletics") == 0) || (strcmp(genre, "Animation") == 0)))
     {
         printf("The genre is not correct. Please try again\n");
         scanf("%s", genre);
     }
   printf("The %s movie are:\n", genre);
   bool exist_movie = 0;
   printf("Name \t\t\t");
   printf("| Type \t");
   printf("| Date \t\t");
   printf("| Time \t\t");
   printf("| Room \t\t");
   printf("| Age  \t\n");

   for(int i = 0; i <= n; i++)
   {
       if((strcmp(movie_list[i].genre, genre) == 0))
       {
            exist_movie = 1;
            printf("%s\t", movie_list[i].name);
            printf("| %s\t", movie_list[i].type);
            printf("| %s\t", movie_list[i].date);
            if(strcmp(movie_list[i].hour, "Coming soon") != 0)
                printf("| %s\t\t", movie_list[i].hour);
            else
                printf("| %s\t", movie_list[i].hour);
            printf("| room %s\t", movie_list[i].room);
            printf("| %s+\t\n", movie_list[i].age);
       }

   }
   if(!exist_movie)
     printf("Right now there are no movies of genre %s available, please enter another genre!", genre);
   display_prices();
   choose_movie(movie_list, n);
}

void age_file(Movie movie_list[100], int n)
  {
       int age = 0, movie_age = 0;
       printf("Enter your age (1 - 99):\n");
       scanf("%d", &age);
   bool exist_movie = 0;
   if(age < 10) printf("There are no available movies for under 10 years!");
   else
   {
       printf("Name \t\t\t");
       printf("| Genre\t\t");
       printf("| Type \t");
       printf("| Date \t\t");
       printf("| Room \t\t");
       printf("| Age  \t\n");

       for(int i = 0; i < n; i++)
       {
           movie_age = movie_list[i].age[1] - '0' + (movie_list[i].age[0] - '0')*10;
           if(movie_age <= age)
           {
                exist_movie = 1;
                printf("%s\t", movie_list[i].name);
                printf("| %s\t", movie_list[i].genre);
                printf("| %s\t", movie_list[i].type);
                printf("| %s\t", movie_list[i].date);
                printf("| room %s\t", movie_list[i].room);
                printf("| %s+\t\n", movie_list[i].age);
           }
       }
   }
   if(!exist_movie && age >= 10)
   {
       printf("Right now there are no movies of age %d available, please enter another age!", age);
       age_file(movie_list, n);
   }
   display_prices();
   choose_movie(movie_list, n);
}

void soon_file(Movie movie_list[100], int n)
{
   bool exist_movie = 0;
   printf("Name \t\t\t");
   printf("| Genre\t\t");
   printf("| Type \t");
   printf("| Date \t\t");
   printf("| Room \t\t");
   printf("| Age  \t\n");

   for(int i = 0; i <= n; i++)
   {
       if((strcmp(movie_list[i].date, "Coming soon") == 0))
       {
            exist_movie = 1;
            printf("%s\t", movie_list[i].name);
            printf("| %s\t", movie_list[i].genre);
            printf("| %s\t", movie_list[i].type);
            printf("| %s\t", movie_list[i].date);
            printf("| room %s\t", movie_list[i].room);
            printf("| %s+\t\n", movie_list[i].age);
       }
   }
   if(!exist_movie)
     printf("Right now there are no Coming soon movies\n");
   display_prices();
}


