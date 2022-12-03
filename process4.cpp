#include <stdio.h>

int main(void) {

	int sum1 = 0;
	for (int i = 0; i < 3000; i++)
	{
		for (int j = 0; j < 5000; j++)
		{
			sum1 = sum1 + i + j;
		}
	}

	return 0;
}