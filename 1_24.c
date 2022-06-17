#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


int getLine(char[]);
int roundBrackets(char[]);
int squareBrackets(char[]);
int figuredBrackets(char[]);
int singleQuotesCount(char[]);
int doubleQuotesCount(char[]);


int getLine(char string[])
{
	int i, c;

	for (i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && (c != '\n'); i++)
	{
		string[i] = c;
	}

	if (c == '\n')
	{
		string[i] = c;
		++i;
	}

	string[i] = '\0'; /*end of string*/

	return i; /*return i + 1*/
}


int roundBrackets(char string[])
{
	int i = 0;

	int roundBracketsState = 0; //round brackets
	int singleQuotesState = 0;
	int doubleQuotesState = 0;

	while (string[i] != '\0' && singleQuotesState == 0 && doubleQuotesState == 0)
	{
		if (string[i] == '\'' && singleQuotesState == 0)
		{
			singleQuotesState += 1;
		}

		else if (string[i] == '\'' && singleQuotesState == 1)
		{
			singleQuotesState -= 1;
		}

		if (string[i] == '\"' && doubleQuotesState == 0)
		{
			doubleQuotesState += 1;
		}

		else if (string[i] == '\"' && doubleQuotesState == 1)
		{
			doubleQuotesState -= 1;
		}

		if (string[i] == '(' && singleQuotesState == 0 && doubleQuotesState == 0)
		{
			roundBracketsState += 1;
		}

		else if (string[i] == ')' && singleQuotesState == 0 && doubleQuotesState == 0)
		{
			roundBracketsState -= 1;
		}

		i++;
	}

	return roundBracketsState;
}


int squareBrackets(char string[])
{
	int i = 0;

	int squareBracketsState = 0; //round brackets

	int singleQuotesState = 0;
	int doubleQuotesState = 0;

	while (string[i] != '\0' && singleQuotesState == 0 && doubleQuotesState == 0)
	{
		if (string[i] == '\'' && singleQuotesState == 0)
		{
			singleQuotesState += 1;
		}

		else if (string[i] == '\'' && singleQuotesState == 1)
		{
			singleQuotesState -= 1;
		}

		if (string[i] == '\"' && doubleQuotesState == 0)
		{
			doubleQuotesState += 1;
		}

		else if (string[i] == '\"' && doubleQuotesState == 1)
		{
			doubleQuotesState -= 1;
		}

		if (string[i] == '[' && singleQuotesState == 0 && doubleQuotesState == 0)
		{
			squareBracketsState += 1;
		}

		else if (string[i] == ']' && singleQuotesState == 0 && doubleQuotesState == 0)
		{
			squareBracketsState -= 1;
		}

		i++;
	}

	return squareBracketsState;
}


int figuredBrackets(char string[])
{
	int i = 0;

	int figuredBracketsState = 0; //round brackets

	int singleQuotesState = 0;
	int doubleQuotesState = 0;

	while (string[i] != '\0' && singleQuotesState == 0 && doubleQuotesState == 0)
	{
		if (string[i] == '\'' && singleQuotesState == 0)
		{
			singleQuotesState += 1;
		}

		else if (string[i] == '\'' && singleQuotesState == 1)
		{
			singleQuotesState -= 1;
		}

		if (string[i] == '\"' && doubleQuotesState == 0)
		{
			doubleQuotesState += 1;
		}

		else if (string[i] == '\"' && doubleQuotesState == 1)
		{
			doubleQuotesState -= 1;
		}

		if (string[i] == '{' && singleQuotesState == 0 && doubleQuotesState == 0)
		{
			figuredBracketsState += 1;
		}

		else if (string[i] == '}' && singleQuotesState == 0 && doubleQuotesState == 0)
		{
			figuredBracketsState -= 1;
		}

		i++;
	}

	return figuredBracketsState;
}


int singleQuotesCount(char string[])
{
	int i = 0;
	int singleQuotesState = 0; //quotes brackets

	while (string[i] != '\0')
	{
		if (string[i] == '\'' && singleQuotesState == 0)
		{
			singleQuotesState += 1;
		}

		else if (string[i] == '\'' && singleQuotesState == 1)
		{
			singleQuotesState -= 1;
		}

		i++;
	}

	return singleQuotesState;
}


int doubleQuotesCount(char string[])
{
	int i = 0;
	int doubleQuotesState = 0; //quotes brackets

	while (string[i] != '\0')
	{
		if (string[i] == '\"' && doubleQuotesState == 0)
		{
			doubleQuotesState += 1;
		}

		else if (string[i] == '\"' && doubleQuotesState == 1)
		{
			doubleQuotesState -= 1;
		}

		i++;
	}

	return doubleQuotesState;
}


int main(void)
{
	char str[MAXLINE];

	int state = 0;
	int len = 0;

	int global_roundBracketsState = 0;
	int global_squareBracketsState = 0;
	int global_figureBracketsState = 0;

	int global_singleQuotesState = 0;
	int global_doubleQuotesState = 0;

	while ((len = getLine(str)) > 0)
	{
		global_roundBracketsState += roundBrackets(str);
		global_squareBracketsState += squareBrackets(str);
		global_figureBracketsState += figuredBrackets(str);

		global_singleQuotesState += singleQuotesCount(str);
		global_doubleQuotesState += doubleQuotesCount(str);

	}

	printf("round state - %d\nsquare state - %d\nfigured state - %d\n",
		global_roundBracketsState,
		global_squareBracketsState,
		global_figureBracketsState);

	printf("single quotes state - %d\n", global_singleQuotesState);
	printf("double quotes state - %d\n", global_doubleQuotesState);


	return 0;
}
