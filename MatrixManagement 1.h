#ifndef MATRIXMANAGEMENT_H_INCLUDED
#define MATRIXMANAGEMENT_H_INCLUDED

void print_matrix(char[100]);
void allocate_place(Movie movie_list[100], int i, int places_no);
void get_row_and_column(int a, int b, int j);
void check_title(Movie movie_list[100], char title[100], int n, int places_no, float *price);
int random_number();

#endif // MATRIXMANAGEMENT_H_INCLUDED
