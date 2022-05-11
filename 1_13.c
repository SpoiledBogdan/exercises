//word length
#include <stdio.h>
#define LEN 10

int main(void) {
	int c, word[LEN];
	int count = 0;

	for (int i = 0; i < LEN; ++i) {
		word[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			count++;
		}

		else {
			++word[count];
		}
	}

	for (int i = 0; i < LEN; ++i) {
		printf("length words %d- %d\n", i, word[i]);
	}

	return 0;
}
