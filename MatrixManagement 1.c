#include "MatrixManagement.h"

void print_places(char matrix[100])
{
    printf("   1 2 3 4 5 6 7 8 9\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%d: ", i+1);
        for(int j = 0; j < 9; j++)
        {
            printf("%d ", matrix[i*9+j]);
        }
        printf("\n");
    }
}

void allocate_place(Movie movie_list[100], int i, int places_no)
{
    int a = 0, b = 0;
    printf("The movie you chose is: %s\n", movie_list[i].name);
    printf("The available places for that movie are listed below (1 - occupied, 0 - free):\nPlease enter the row and the column of the selected place!\n");
    print_places(movie_list[i].room_places);
    for(int j = 1; j <= places_no; j++)
    {
        get_row_and_column(&a,&b,j);
        if (movie_list[i].room_places[(a-1)*9+(b-1)] == 0)
            movie_list[i].room_places[(a-1)*9+(b-1)] = 1;
        else
        {
            printf("\nThis place is already taken! Please choose another one!\n");
            j--;
        }
    }
    printf("The updated places are:\n");
    print_places(movie_list[i].room_places);
}

void get_row_and_column(int a, int b, int j)
{
    printf("Row of place %d:", j); scanf("%d", a);
    printf("Column of place %d:", j); scanf("%d", b);
}

void check_title(Movie movie_list[100], char title[100], int n, int places_no, float *price)
{
    char buffer[100] = "\0";
    bool breaak = 0;
    for(int i = 0; i < n && breaak == 0; i++)
    {
        strcpy(buffer, movie_list[i].name);
        for(int cnt = 0; cnt <= strlen(buffer); cnt++)
            buffer[cnt] = toupper(buffer[cnt]);
        buffer[strlen(title)] = '\0';
        if(strcmp(title, buffer) == 0)
        {
            allocate_place(movie_list, i, places_no);
            for(int g = 1; g <= places_no; g++)
            {
                if (strcmp(movie_list[i].type, "2D") == 0)
                    (*price) = (*price) + 7.0;
                if (strcmp(movie_list[i].type, "3D") == 0)
                    (*price) = (*price) + 15.0;
                if (strcmp(movie_list[i].type, "4DX") == 0)
                    (*price) = (*price) + 25.0;
                if (strcmp(movie_list[i].type, "7D") == 0)
                    (*price) = (*price) + 25.0;
            }
            breaak = 1;
        }
    }
    if(!breaak)
        printf("\nThe entered title is not correct! Please try again.\n");
}

int random_number()
{
    srand(time(NULL));
    int r = rand();
    return r;
}
