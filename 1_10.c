#include <stdio.h>
/*ANCII*/
#define TAB 9	
#define BACK 8
#define SLASH 92

int main()
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == TAB)
			printf("\\t");
		if (c == BACK)
			printf("\\b");
		if (c == SLASH)
			printf("\\");
		putchar(c);
	}

    return 0;
}