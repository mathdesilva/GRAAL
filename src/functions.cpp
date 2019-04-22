#include "functions.h"

namespace graal{

	const void * min( const void * first, const void * last, std::size_t size, Compare cmp )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;
		byte smallest[ size ];
		byte aux[ size ];

		void * res = pfirst;

		std::memcpy( smallest, pfirst, size );

		while( pfirst < plast )
		{
			std::memcpy( aux, pfirst, size );

			if( cmp( aux, smallest ) )
			{	
				std::memcpy( smallest, pfirst, size );
				res = pfirst;
			}

			pfirst += size;
		}

		return res;
	}

	void reverse( void * first, void * last, std::size_t size )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;
		byte aux[ size ];

		plast -= size;
		while( pfirst < plast )
		{
			std::memcpy( aux, pfirst, size );
			std::memcpy( pfirst, plast, size );
			std::memcpy( plast, aux, size );

			pfirst += size;
			plast -= size;
		}
	}

	void * copy( const void * first, const void * last, const void * d_first, std::size_t size )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;
		byte * pd_first = (byte *) d_first;

		while( pfirst < plast )
		{
			std::memcpy( pd_first, pfirst, size );

			pfirst += size;
			pd_first += size;
		}

		void * res = pd_first;

		return res; 
	}

	void * clone( const void * first, const void * last, std::size_t size )
	{
		// TODO: implement the function
	}

	const void * find_if( const void * first, const void * last, std::size_t size, Predicate p )
	{
		// TODO: implement the function
	}

	const void * find( const void * first, const void * last, std::size_t size, const void * value, Equal eq )
	{
		// TODO: implement the function
	}

	bool all_of( const void * first, const void * last, std::size_t size, Predicate p )
	{
		// TODO: implement the function
	}

	bool any_of( const void * first, const void * last, std::size_t size, Predicate p )
	{
		// TODO: implement the function
	}

	bool none_of( const void * first, const void * last, std::size_t size, Predicate p )
	{
		// TODO: implement the function
	}

	bool equal( const void * first1, const void * last1, const void * first2, Equal eq )
	{
		// TODO: implement the function
	}

	bool equal( const void * first1, const void * last1, const void * first2, const void * last2, Equal eq )
	{
		// TODO: implement the function
	}

	void * unique( void * first, void * last, std::size_t size, Equal eq )
	{
		// TODO: implement the function
	}

	void * partition( void * first, void * last, std::size_t size, Predicate p)
	{
		// TODO: implement the function
	}

	void * sort( void * first, std::size_t count, std::size_t size, Compare cmp )
	{
		// TODO: implement the function
	}
}