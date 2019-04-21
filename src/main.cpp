#include <iostream>
#include <array>

#include "functions.h"

bool less_than(const void * a, const void * b)
{
	const int *a_ = static_cast< const int * >(a);
	const int *b_ = static_cast< const int * >(b);

	return (*a_ < *b_);
}

void printArray( void * first, void * last, std::size_t size )
{
	byte * pf = (byte *) first;
	byte * pl = (byte *) last; 

	std::cout << "[ ";

	while( pf < pl )
	{
		std::cout << *(int *)pf << " ";
		pf += size;
	}
	std::cout << "]";
}

int main( void )
{	
	std::cout << ">>> TEST 1: min function\n";
	std::array < int, 7 > arr1_1 = { -10, 6, 7, 2, -3, 1, -5 };
	std::cout << "Using int array: ";
	printArray( arr1_1.begin(), arr1_1.end(), sizeof(int) );
	std::cout << std::endl;
	auto result1_1 = graal::min( arr1_1.begin(), arr1_1.end(), sizeof(int), less_than );
	std::cout << "Result: " << *(int *)result1_1 << std::endl;

	std::array < int, 8 > arr1_2 = { 0, -2, -3, -4, -5, -6, -7, -8 };
	std::cout << "Using int array: ";
	printArray( arr1_2.begin(), arr1_2.end(), sizeof(int) );
	std::cout << std::endl;
	auto result1_2 = graal::min( arr1_2.begin(), arr1_2.end(), sizeof(int), less_than );
	std::cout << "Result: " << *(int *)result1_2 << std::endl << std::endl;



	std::cout << ">>> TEST 2: reverse function\n";
	std::array < int, 5 > arr2_1 = { 1, 2, 3, 4, 5 };
	std::cout << "Using int array: ";
	printArray( arr2_1.begin(), arr2_1.end(), sizeof(int) );
	std::cout << std::endl;
	graal::reverse( arr2_1.begin(), arr2_1.end(), sizeof(int) );
	std::cout << "Result: ";
	printArray( arr2_1.begin(), arr2_1.end(), sizeof(int) );
	std::cout << std::endl;

	std::array < int, 6 > arr2_2 = { 1, 2, 3, 4, 5, 6 };
	std::cout << "Using int array: ";
	printArray( arr2_2.begin(), arr2_2.end(), sizeof(int) );
	std::cout << std::endl;
	graal::reverse( arr2_2.begin(), arr2_2.end(), sizeof(int) );
	std::cout << "Result: ";
	printArray( arr2_2.begin(), arr2_2.end(), sizeof(int) );
	std::cout << std::endl;



	return 0;
}	