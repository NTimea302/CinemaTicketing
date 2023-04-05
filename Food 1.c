#include "InOut.h"
#include <stdio.h>

void snacks_file(float *price)
{
    float price_list[20];
    int food = 0;

     price_list[1] = 7.5;
     price_list[2] = 4;
     price_list[3] = 2.4;
     price_list[4] = 3.5;
     price_list[5] = 6;

     printf("Here is the snacks menu:\n ~1.HOTDOG+CHIPS %.2f $\n ~2.CHEESE DOG+CHIPS %.2f $\n ~3.CURLY FRIES %.2f $\n ~4.MOZZARELLA STICKS %.2f $\n ~5.TOASTED RAVIOLI %.2f $\n\n", price_list[1], price_list[2], price_list[3], price_list[4], price_list[5]);

    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}

void drinks_file(float *price)
{
     float price_list[20];
     int food = 0;

     price_list[1] = 4.75;
     price_list[2] = 5.75;
     price_list[3] = 6.75;
     price_list[4] = 4.00;

     printf("Here is the drinks menu:\n ~1.SMALL FOUNTAIN %.2f $\n ~2.MEDIUM FOUNTAIN %.2f $\n ~3.LARGE FOUNTAIN %.2f $\n ~4.WATER %.2f $\n\n", price_list[1], price_list[2], price_list[3], price_list[4]);
    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}

void treats_file(float *price)
{
    float price_list[20];
    int food = 0;

    price_list[1] = 2.50;
    printf("Do you want some treats too :) ?\n ~1.CHOCOLATE+CHIP COOKIE %.2f $\n\n", price_list[1]);

    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}

void candy_file(float *price)
{
     float price_list[20];
     int food = 0;

     price_list[1] = 2.35;
     price_list[2] = 3.35;
     price_list[3] = 4.45;

     printf("How about some candies :D ?\n ~1.SMALL %.2f $\n ~2.MEDIUM %.2f $\n ~3.LARGE %.2f $\n\n", price_list[1], price_list[2], price_list[3]);

    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}

void combo_file(float *price)
{
     float price_list[20];
     int food = 0;

     price_list[1] = 15.25;
     price_list[2] = 17.75;
     price_list[3] = 22.00;
     price_list[4] = 12.50;
     price_list[5] = 7.50;

     printf("Combo menu:\n ~1.COUPLES COMBO %.2f $\n ~2.COMBO1 %.2f $\n ~3.COMBO2 %.2f $\n ~4.COMBO3 %.2f $\n ~5.KIDS COMBO %.2f $\n\n", price_list[1], price_list[2], price_list[3], price_list[4], price_list[5]);

    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}
