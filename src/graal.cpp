#include "graal.h"

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
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;
		const int n_bytes = plast - pfirst;

		byte * clone = new byte [n_bytes];
		byte * aux = (byte *) &clone[0];
		void * res = aux;

		while( pfirst < plast)
		{
			std::memcpy( aux, pfirst, size );

			aux += size;
			pfirst += size;
		}

		return res;
	}

	const void * find_if( const void * first, const void * last, std::size_t size, Predicate p )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;

		while( pfirst < plast )
		{
			if( p( pfirst ) )
			{
				return pfirst;
			}

			pfirst += size;
		}

		return plast;
	}

	const void * find( const void * first, const void * last, std::size_t size, const void * value, Equal eq )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;

		while( pfirst < plast )
		{
			if( eq( pfirst, value ) )
			{
				return pfirst;
			}

			pfirst += size;
		}

		return plast;
	}

	bool all_of( const void * first, const void * last, std::size_t size, Predicate p )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;
		bool res = true;

		while( pfirst < plast )
		{
			if( not p( pfirst ) )
			{
				res = false;
				break;
			}

			pfirst += size;
		}

		return res;
	}

	bool any_of( const void * first, const void * last, std::size_t size, Predicate p )
	{
		byte * pfirst = (byte *) first;
		byte * plast = (byte *) last;
		bool res = false;

		while( pfirst < plast )
		{
			if( p( pfirst ) )
			{
				res = true;
				break;
			}

			pfirst += size;
		}

		return res;
	}

	bool none_of( const void * first, const void * last, std::size_t size, Predicate p )
	{
		// TODO: implement the function
		return true;
	}

	bool equal( const void * first1, const void * last1, const void * first2, Equal eq )
	{
		// TODO: implement the function
		return true;
	}

	bool equal( const void * first1, const void * last1, const void * first2, const void * last2, Equal eq )
	{
		// TODO: implement the function
		return true;
	}

	void * unique( void * first, void * last, std::size_t size, Equal eq )
	{
		// TODO: implement the function
		return last;
	}

	void * partition( void * first, void * last, std::size_t size, Predicate p)
	{
		// TODO: implement the function
		return last;
	}

	void * sort( void * first, std::size_t count, std::size_t size, Compare cmp )
	{
		// TODO: implement the function
		return first;
	}
}