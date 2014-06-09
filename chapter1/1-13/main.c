#include <stdio.h>

#define IN      1       /* inside a word */
#define OUT     0       /* outside a word */
#define MAXLEN	10	/* maximum word length */

/* Prints a histogram of the lengths of words in it's input */
int main() {
	int c, nother, state, wlength;
	int nlength[MAXLEN];

	nother = wlength = 0;
	state = OUT;
	for(int i = 0; i < MAXLEN; i++)
		nlength[i] = 0;

	/* increment the nlength array each time a word of n characters
	   is found */
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			if (state == IN) {
				state = OUT;
				if (wlength < MAXLEN)
					nlength[wlength]++;
				else
					nother++;
				wlength = 0;
			}
		} else {
			state = IN;
			wlength++;
		}
	}

	/* draw the histogram */
	printf("other | ");
	for (int j = nother; j > 0; j--)
		printf("#");
	printf("\n");

	for (int i = MAXLEN - 1; i > 0; i--) {
		printf("%5d | ", i);
		for (int j = nlength[i]; j > 0; j--)
			printf("#");
		printf("\n");
	}
}
