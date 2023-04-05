/**********************************************************/
/* InOut.c - See InOut.h for copyright and info           */
/**********************************************************/
#include <time.h>
#include <stdlib.h>

#include "InOut.h"
#include "Searches.c"
#include "MatrixManagement.h"

void main_menu(Movie movie_list[100], int n)
{
     char c = '/0';
     printf("Welcome to the Cinema!\n");
     label2:
     printf("What would you like to do? Press the correct key!\n(t) Select movies by type (2D, 3D, 4DX, 7D)\n(d) Select movies by date and hour\n(g) Select movies by genre\n(a) Select movies by age\n(c) View coming soon movies\n");
     printf("(s) Stop\n");
     c = getch();
     while(c != 's')
     {
         switch(c)
         {
             case 't': type_file(movie_list, n); goto label2;
                        break;
             case 'd': date_file(movie_list, n); goto label2;
                        break;
             case 'g': genre_file(movie_list, n); goto label2;
                        break;
             case 'a': age_file(movie_list, n); goto label2;
                        break;
             case 'c': soon_file(movie_list, n); goto label2;
                        break;
             default: printf("Pressed the wrong key! Try again, please.\n\n"); c = getch(); goto label2;
                        break;
         }
     }
}

void read_file(Movie movie_list[100], int *n)
{
    int  i = 0;
    char c;
    char buffer[100];

    FILE *file_ptr;
    file_ptr = fopen("Movies.txt", "r");

    while((c = fgetc(file_ptr)) != EOF)
    {
        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].name, "%c%s", c, buffer);                           //  CITIM NUMELE
        movie_list[i].name[strlen(movie_list[i].name) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].type, "%s", buffer);                                //  CITIM TYPE
        movie_list[i].type[strlen(movie_list[i].type) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].genre, "%s", buffer);                               //  CITIM GENUL
        movie_list[i].genre[strlen(movie_list[i].genre) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].date, "%s", buffer);                                //  CITIM DATA
        movie_list[i].date[strlen(movie_list[i].date) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].hour, "%s", buffer);                                //  CITIM ORA
        movie_list[i].hour[strlen(movie_list[i].hour) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].age, "%s", buffer);                                 //  CITIM ANII
        movie_list[i].age[strlen(movie_list[i].age) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(movie_list[i].room, "%s", buffer);                                //  CITIM SALA
        movie_list[i].room[1] = '\0';

        i++;
    }

    (*n) = i;
    fclose(file_ptr);
   // printf("Files read succesfully!\n");
}

void display_file(Movie movie_list[100], int n)
{
    printf("Name \t\t\t");
    printf("| Type \t");
    printf("| Genre\t\t");
    printf("| Date \t\t");
    printf("| Time \t");
    printf("| Age  \t");
    printf("| Room \t\n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\t", movie_list[i].name);
        printf("| %s\t", movie_list[i].type);
        printf("| %s\t", movie_list[i].genre);
        printf("| %s\t", movie_list[i].date);
        printf("| %s\t", movie_list[i].hour);
        printf("| %s+\t", movie_list[i].age);
        printf("| room %s\t\n", movie_list[i].room);
    }
}

void choose_movie(Movie movie_list[100], int n)
{
    char  c[10] = "\0", s = '\0', f = '\0';
    int   places_no = 0;
    char  title[100] = "\0";
    float price = 0.0f;

    printf("\nWould you like to select and reserve places for a movie from above? yes/no\n");
    scanf("%s", c);
    if(strcmp(c, "yes") == 0)
    {
        printf("Enter the title of the movie you would like to see: ");
        scanf("%s", title);
        fflush(stdin);
        for(int cnt = 0; cnt <= strlen(title); cnt++)
            title[cnt] = toupper(title[cnt]);
        printf("How many places would you like to reserve?\n");
        scanf("%d", &places_no);
        fflush(stdin);
        while(places_no < 1 || places_no > 100)
        {
            printf("\nThe entered number is not correct!\nPlease try again!\n");
            scanf("%d", &places_no);
            fflush(stdin);
        }
        check_title(movie_list, title, n, places_no, &price);
        printf("\nWould you like to assure some food and drink to your movie? y/n");
        s = getch();
        if(s == 'y')
        {
            printf("\nPlease enter the number of the snack/snacks you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            snacks_file(&price);
            printf("\nPlease enter the number of the drink/drinks you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            drinks_file(&price);
            printf("\nPlease enter the number of the treat you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            treats_file(&price);
            printf("\nPlease enter the number of the candy you wish to try. When you are ready press 0. If you do not want any, just press 0.\n");
            candy_file(&price);
            printf("\nPlease enter the number of the snack/snacks you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            combo_file(&price);
        }
        printf("\nThank you for reserving your place! You will have to pay %.2f $. Your confirmation number is: %4.d.\nPlease go with your confirmation number, with 15 - 20 minutes before the movie to the cinema cashier and pay.\n", price, random_number()%4000);
        printf("Press any key to exit!\n");
        f = getch();
        exit(EXIT_SUCCESS);
    }
}

void display_prices()
{
    float price_list[10];

    price_list[1] = 7;
    price_list[2] = 15;
    price_list[3] = 25;
    price_list[4] = 25;

    printf("Here are the prices for the movie tickets:\n ~2D  %.2f$\n ~3D  %.2f$\n ~4DX %.2f$\n ~7D  %.2f$\n", price_list[1], price_list[2], price_list[3], price_list[4]);
}
