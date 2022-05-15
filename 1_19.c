//1_19

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

/*len of string*/
int strlen(char s[]) {
	int i = 0;

	while (s[i] != '\n') {
		i++;
	}

	return i;
}

void tail_garbage(char s[], int s_len) {
	int i = s_len - 2; /*remove NULL terminator and '\0'*/

	while ((s[i] == ' ') || (s[i] == '\t')) {
		s[i] = '\0';
		--i;
	}

	s[++i] = '\n';
}

void reverse(char original[], char reverce[], int s_len) {
	int i = 0;

	/*initialization reverce string*/
	for (int j = 0; j < MAX; j++) {
		reverce[j] = original[j];
	}

	for (s_len -= 2; s_len >= 0; s_len--) {
		reverce[i] = original[s_len];
		i++;
	}
}

int main(void) {

	int len = 0; 
	char str[MAX]; 
	char rev_str[MAX];

	printf("type a string:\n");

	while ((len = getline(str)) > 0) {

		tail_garbage(str, len);

		if (str[0] != '\n') {
			reverse(str, rev_str, len);
			printf("str before reverse - %s\n", str);
			printf("str after reverse - %s\n", rev_str);
		}

		else {
			printf("empty string\n");
		}
	}

	return 0;
}
