#include <stdio.h>

/* copies input to output, replacing printing instances of
   \t, \b and \\. */
int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\");
		else
			putchar(c);
	}
}
