/*Ctrl+D:Linux; Ctrl+Z:Windows*/
#include <stdio.h>

int main()
{
	int chr, s, t, n;
	s = 0; /*spases*/
	t = 0; /*tabs*/
	n = 0; /*srings*/
	while ((chr = getchar()) != EOF)
		if (chr == ' ')
			++s;
		else if (chr == '\t')
			++t;
		else if (chr == '\n')
			++n;
	printf("spases: %d\n", s);
	printf("tabs: %d\n", t);
	printf("strings: %d\n", n);

	return 0;
}
