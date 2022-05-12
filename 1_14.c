#include <stdio.h>
#define LEN 10

int main(void) {
	int c, space, tab, newl, chars;
	space = tab = newl = chars = 0;
	int digit[LEN];

	for (int i = 0; i < LEN; i++) {
		digit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++digit[c - '0'];
		}

		else if (c == ' ') {
			++space;
		}

		else if (c == '\t') {
			++tab;
		}

		else if (c == '\n') {
			++newl;
		}

		else {
			++chars;
		}
	}

	printf("digits:\n");
	for (int i = 0; i < LEN; i++) {
		printf("count of %d - %d\n", i, digit[i]);
	}

	printf("space - %d\ntabs - %d\nnew line - %d\nother - %d\n", space, tab, newl, chars);

	return 0;
}
