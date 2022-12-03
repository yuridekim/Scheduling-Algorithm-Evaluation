#include <stdio.h>
#include <iostream>
#include <time.h>

int fibo(int num);

int main(void) {

	int num = 27;
	int i;

	for (i = 0; i < num; i++)
	{
		std::cout << "";
	}
    
	return 0;
}

int fibo(int num) {

	if (num == 0) return 0;
	else if (num == 1) return 1;
	else return fibo(num - 1) + fibo(num - 2);
}