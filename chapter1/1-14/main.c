#include <stdio.h>
#include <ctype.h>

#define ALPHABET	26

int main()
{
	int c;
	int freq[ALPHABET];

	/* initialise array to zero */
	for (int i = 0; i < ALPHABET; i++)
		freq[i] = 0;

	/* Count the frequency of each character a-z */
	while ((c = getchar()) != EOF) {
		if ((c = tolower(c)) >= 'a' && c <= 'z') {
			freq[c - 'a']++;
		}
	}

	/* draw the histogram */
	for (int i = 'a'; i <= 'z'; i++) {
		printf("%c | ", i);
		for (int j = freq[i - 'a']; j > 0; j--)
			printf("#");
		printf("\n");
	}
}
