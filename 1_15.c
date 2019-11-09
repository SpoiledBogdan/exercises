#include <stdio.h>

float table(float f);

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

float table(float f) {
	return (5.0 / 9.0) * (f - 32);
}