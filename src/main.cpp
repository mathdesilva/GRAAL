#include <iostream>
#include <array>

#include "functions.h"

bool comparar(const void * a, const void * b)
{
	const int *a_ = static_cast< const int * >(a);
	const int *b_ = static_cast< const int * >(b);

	return (*a_ < *b_);
}

int main( void )
{	
	std::array < int, 7 > arr = { -10, 6, 7, 2, -3, 1, -5 };
	auto result1 = graal::min( arr.begin(), arr.end(), sizeof(int), comparar );
	const int * res = static_cast< const int * >(result1);
	std::cout << *res << std::endl;

	return 0;
}	