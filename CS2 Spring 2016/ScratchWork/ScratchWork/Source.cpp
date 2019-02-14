// Example program
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace std;
int frequency_of_primes(int n) {
	int i, j;
	int freq = n - 1;
	for (i = 2; i <= n; ++i) for (j = sqrt(i); j>1; --j) if (i%j == 0) { --freq; break; }
	return freq;
}
void main()
{
	int num, i = 0, f;
	clock_t t;
	t = clock();
	while (i<100000)
	{

		num = rand() % 100 + 1;
		cout << num << endl;
		i++;
	}
	t = clock() - t;
	cout << "time = " << t<< (((float) t)/CLK_TCK) << endl;
	system("pause");
}
