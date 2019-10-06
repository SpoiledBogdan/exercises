/*Таблица перевода температур по Фаренгейту и Цельсию 
с 300 до 0 с помощью оператора for*/

#include <stdio.h>

int main()
{
    float farh;
    
    printf("    ТАБЛИЦА ПЕРЕВОДА ТЕМПЕРАТУР\n\n");
    printf("    Фаренгейт  Цельсий\n");
    
    for (farh = 300; farh >= 0; farh = farh - 20)
        printf("\t%3.0f    %6.1f\n", farh, (5.0 / 9.0) * (farh - 32.0));
    return 0;
}

