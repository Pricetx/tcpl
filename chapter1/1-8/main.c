#include <stdio.h>

int main()
{
	int c, bl, ta, nl;

	bl = 0;
	ta = 0;
	nl = 0;

	while ((c = getchar()) != EOF)
		if (c == ' ')
			++bl;
		else if (c == '\t')
			++ta;
		else if (c == '\n')
			++nl;
	printf("Blanks: %d | Tabs: %d | Newlines %d\n", bl, ta, nl);
}
