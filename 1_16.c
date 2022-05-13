#include <stdio.h>
#define MAX 1000 /*max len of string*/

int getline(char s[]) {
	int i, c;

	for (i = 0; i < MAX && ((c = getchar()) != EOF) && (c != '\n'); i++) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0'; /*end of string*/

	return i;
}

/*func that save max string*/
void copy(char current[], char max[]) {
	int i = 0;

	while ((current[i] = max[i]) != '\0') {
		i++;
	}
}

int main(void) {

	int len = 0; /*current length of string*/
	int max_len = 0; /*max length of string*/

	char str[MAX]; /*current string*/
	char max_str[MAX]; /*max string*/

	printf("type a string:\n");

	while ((len = getline(str)) > 0) { 
		if (len > max_len) {
			max_len = len;
			copy(max_str, str);
		}
	}

	printf("max string - %s\nlength is - %d\n", max_str, max_len);

	return 0;
}
