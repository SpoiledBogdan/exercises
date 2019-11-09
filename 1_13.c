#include <stdio.h>
#define MAXLEN 10
int main(void) {
    int c, i, s;
    int word_length[MAXLEN];

    s = 0;
    for (i = 0; i < MAXLEN; ++i)
        word_length[i] = 0;
    while ((c = getchar()) != EOF) 

        if (c == ' ' || c == '\t' || c == '\n') 
        {
            if (s >= MAXLEN)
                word_length[0] += 1;
            else if (s > 0)
                word_length[s] += 1;
            s = 0; }
        else
            ++s;

    for (i = 0; i < MAXLEN; ++i)
        printf("length %d: %d\n", i, word_length[i]);

    return 0;
}