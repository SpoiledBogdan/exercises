/*Таблица перевода температур по Фаренгейту и Цельсию 
с 0 до 300 с помощью цикла while*/

#include <stdio.h>

int main()
{
    int min, max, step;
    float farh, celsium;
    
    min = 0;
    max = 300;
    step = 20;
    farh = min;
    
    printf("    ТАБЛИЦА ПЕРЕВОДА ТЕМПЕРАТУР\n\n");
    printf("    Фаренгейт  Цельсий\n");
    while (farh <= max) {
        celsium = (5.0 / 9.0) * (farh - 32);
        printf("\t%3.0f    %6.2f\n", farh, celsium);
        farh = farh + step;
    }

    return 0;
}


