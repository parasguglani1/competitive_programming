#include <iostream>
using namespace std;

int main()
{
	int i = 10;
	int j = 21;

	// read right to left
	int const *p = &i;
	// pointer pointing to constant integer
	p = &j;

	// constant pointer pointing to integer
	int *const p2 = &i;
	(*p2)++;
	// p2 = &j;

	// constant pointer pointing to constant integer
	int const *const p3 = &i;
	// p3 = &j;
	// (*p3)++;
}
