#include <stdio.h>

#define	IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* Prints it's input one word per line */
int main() {
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			if (state == IN) {
				putchar('\n');
				state = OUT;
			}
		} else {
			state = IN;
			putchar(c);
		}
	}
}
