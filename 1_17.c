//1_17

#include <stdio.h>
#define MAX 1000 /*max len of string*/

int getline(char s[]) {
	int i, c;

	for (i = 0; i <= MAX && ((c = getchar()) != EOF) && (c != '\n'); i++) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0'; /*end of string*/

	return i;
}

int main(void) {

	int len = 0; 
	char str[MAX]; 

	printf("type a string:\n");

	while ((len = getline(str)) > 0) { 
		printf("len = %d\n", len);

		if (len >= 80) {
			printf("line from 80 chars:\n %s\n", str);
		}
	}

	return 0;
}
