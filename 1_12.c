#include <stdio.h>

#define IN 1 /*inside the word*/
#define OUT 0 /*at the beginning of a word*/

int main()
{
	int c, state;

	while ((c = getchar()) != EOF) 
	{
		if (c == '\n' || c == ' ' || c == '\t') 
		{
			if (state == IN) 
			{
				putchar('\n');
			}
			
			state = OUT;

		}

		else 
		{
			putchar(c);
			state = IN;
		}
	}

    return 0;
}