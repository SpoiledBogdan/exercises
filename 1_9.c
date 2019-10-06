#include <stdio.h>

int main()
{
    int c, space;
    
    space = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++space;
            
        if (c != ' ')
            space = 0;
            
        if (space <= 1)
            putchar(c);
    }
    
    return 0;
}
