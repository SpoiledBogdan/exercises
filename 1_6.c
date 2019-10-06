#include <stdio.h>

int main()
{
    int c;
    c = getchar() != EOF;
    if (c == 1)
        printf("EOF = 1\n");
    else 
        printf("EOF = 0\n");

    return 0;
}
