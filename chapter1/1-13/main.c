#include <stdio.h>

#define IN      1       /* inside a word */
#define OUT     0       /* outside a word */
#define MAXLEN	10	/* maximum word length */

/* Prints a histogram of the lengths of words in it's input */
int main()
{
	int c, nother, state, wlength, max;
	int nlength[MAXLEN];

	nother = wlength = max = 0;
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

	/* draw the horizontal histogram */
	printf("Horizontal histogram:\n\n");

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

	if(nother > max)
		max = nother;

	/* get the highest frequency */
	for (int i = 0; i < MAXLEN; i++) {
		if (nlength[i] > max)
			max = nlength[i];
	}

	/* draw the vertical histogram */
	printf("\n\nVertical histogram:\n\n");

	for (int i = max; i > 0; i--) {
		printf("%3d | ", i);

		/* draw the 1-9 column */
		for (int j = 1; j < MAXLEN; j++) {
			if ((nlength[j] - i) >= 0)
				printf("# ");
			else
				printf("  ");
		}

		/* draw the "other" column */
		if ((nother - i) >= 0)
			printf("# ");
		else
			printf(" ");

		printf("\n");
	}

	printf("    ");
	for (int i = 0; i < (MAXLEN * 2) + 1; i++)
		printf("-");
	printf("\n");

	printf("     ");
	for (int i = 1; i < MAXLEN; i++)
		printf("%2d", i);
	printf(" other\n");
}
