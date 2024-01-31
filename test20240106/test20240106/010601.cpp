#include<stdio.h>
int main()
{
int i;

for (i = 100; i < 200; i++)
	if ((i - 2) % 4 == 0)
		if (!((i - 3) % 7))
			if ((i - 5) % 9 == 0)
				printf("%d", i);
return 0;
}