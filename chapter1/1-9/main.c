#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF) {

		if (c == ' ') {
			printf("%c", c);
			while ((c = getchar()) == ' ')
				;
		}
		printf("%c", c);
	}
}
