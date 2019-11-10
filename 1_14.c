#include<stdio.h>
#define LEN 12

int main(void) {
	int c, i, j, space, other;
	int digit[LEN];

	for (i = 0; i < LEN; ++i)
		digit[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			++digit[c - '0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			++digit[11];
		else
			++digit[12];
	}

	for (i = 0; i < LEN; ++i){
        printf("%d : ", i);
        for (j = 1; j <= digit[i]; ++j)
            printf("-");
        printf("> %d\n", digit[i]); }
}