#include <iostream>
#include <array>

#include "functions.h"

bool less_than( const void * a, const void * b )
{
	const int *a_ = static_cast< const int * >(a);
	const int *b_ = static_cast< const int * >(b);

	return ( *a_ < *b_ );
}

bool greater_than_five( const void * num )
{
	const int *num_ = static_cast< const int * >(num);

	return ( *num_ > 5 );
}

bool equal( const void * a, const void * b )
{
	const int *a_ = static_cast< const int * >(a);
	const int *b_ = static_cast< const int * >(b);

	return ( *a_ == *b_ );
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

// ============================================================================
//                                                        1 - MIN FUNCTION TEST
// ============================================================================
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


// ============================================================================
//                                                    2 - REVERSE FUNCTION TEST
// ============================================================================
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
	std::cout << std::endl << std::endl;


// ============================================================================
//                                                       3 - COPY FUNCTION TEST
// ============================================================================
	std::cout << ">>> TEST 3: copy function\n";
	std::array < int, 4 > arr3_0 = { 10, 20, 30, 40 };
	std::array < int, 8 > arr3_1 = { 0 };
	std::cout << "Using int arrays: ";
	printArray( arr3_1.begin(), arr3_1.end(), sizeof(int) );
	std::cout << " < ";
	printArray( arr3_0.begin(), arr3_0.end(), sizeof(int) );
	std::cout << std::endl;
	auto result3_1 = graal::copy( arr3_0.begin(), arr3_0.end(), arr3_1.begin(), sizeof(int) );
	std::cout << "Result: ";
	printArray( arr3_1.begin(), arr3_1.end(), sizeof(int) );
	std::cout << " return address index: " << ((int *)result3_1 - arr3_1.begin()) << std::endl;

	std::array < int, 8 > arr3_2 = { 0 };
	std::cout << "Using int arrays: ";
	printArray( arr3_2.begin(), arr3_2.end(), sizeof(int) );
	std::cout << " < ";
	printArray( arr3_0.begin(), arr3_0.end(), sizeof(int) );
	std::cout << std::endl;
	auto result3_2 = graal::copy( arr3_0.begin(), arr3_0.end() - 2, arr3_2.begin() + 3, sizeof(int) );
	std::cout << "Result: ";
	printArray( arr3_2.begin(), arr3_2.end(), sizeof(int) );
	std::cout << " return address index: " << ((int *)result3_2 - arr3_2.begin()) << std::endl << std::endl;


// ============================================================================
//                                                      4 - CLONE FUNCTION TEST
// ============================================================================
	std::cout << ">>> TEST 4: clone function\n";
	std::array < int, 10 > arr4 = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	std::cout << "Using int arrays: ";
	printArray( arr4.begin(), arr4.end(), sizeof(int) );
	std::cout << std::endl;
	auto result4 = graal::clone( arr4.begin(), arr4.end(), sizeof(int) );
	std::cout << "Result: ";
	printArray( result4, (int *)result4 + arr4.size(), sizeof(int) );
	std::cout << std::endl << std::endl;
	delete[] (int *)result4;


// ============================================================================
//                                                    5 - FIND_IF FUNCTION TEST
// ============================================================================
	std::cout << ">>> TEST 5: find_if function\n";
	std::array < int, 10 > arr5_1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << "Using int array: ";
	printArray( arr5_1.begin(), arr5_1.end(), sizeof(int) );
	std::cout << std::endl;
	auto result5_1 = graal::find_if( arr5_1.begin(), arr5_1.end(), sizeof(int), greater_than_five );
	std::cout << "Result: ";
	printArray( (int *)result5_1, arr5_1.end(), sizeof(int) );
	std::cout << std::endl;

	std::array < int, 10 > arr5_2 = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
	std::cout << "Using int array: ";
	printArray( arr5_2.begin(), arr5_2.end(), sizeof(int) );
	std::cout << std::endl;
	auto result5_2 = graal::find_if( arr5_2.begin(), arr5_2.end(), sizeof(int), greater_than_five );
	std::cout << "Result: ";
	printArray( (int *)result5_2, arr5_2.end(), sizeof(int) );
	std::cout << std::endl << std::endl;


// ============================================================================
//                                                       6 - FIND FUNCTION TEST
// ============================================================================
	std::cout << ">>> TEST 6: find function\n";
	int value = 5;
	std::array < int, 10 > arr6_1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << "Using int array: ";
	printArray( arr6_1.begin(), arr6_1.end(), sizeof(int) );
	std::cout << std::endl;
	auto result6_1 = graal::find( arr6_1.begin(), arr6_1.end(), sizeof(int), &value, equal );
	std::cout << "Result: ";
	printArray( (int *)result6_1, arr6_1.end(), sizeof(int) );
	std::cout << std::endl;

	std::array < int, 10 > arr6_2 = { 1, 2, 3, 4, 4, 4, 4, 4, 4, 4 };
	std::cout << "Using int array: ";
	printArray( arr6_2.begin(), arr6_2.end(), sizeof(int) );
	std::cout << std::endl;
	auto result6_2 = graal::find( arr6_2.begin(), arr6_2.end(), sizeof(int), &value, equal );
	std::cout << "Result: ";
	printArray( (int *)result6_2, arr6_2.end(), sizeof(int) );
	std::cout << std::endl;

	return EXIT_SUCCESS;
}	