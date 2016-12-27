/*
 * @file Random.cpp
 * @author PJ O Halloran
 * @date 22/12/2016
 */

#include "Random.h"

#include <cstring>
#include <ctime>

// Period parameters
#define CMATH_N 624
#define CMATH_M 397
#define CMATH_MATRIX_A 0x9908b0df
#define CMATH_UPPER_MASK 0x80000000
#define CMATH_LOWER_MASK 0x7fffffff

// Tempering parameters
#define CMATH_TEMPERING_MASK_B 0x9d2c5680
#define CMATH_TEMPERING_MASK_C 0xefc60000
#define CMATH_TEMPERING_SHIFT_U(y) (y >> 11)
#define CMATH_TEMPERING_SHIFT_S(y) (y << 7)
#define CMATH_TEMPERING_SHIFT_T(y) (y << 15)
#define CMATH_TEMPERING_SHIFT_L(y) (y >> 18)

namespace ember
{
	namespace math
	{
		Random::Random()
		{
			_seed = 1;
			_seedSp = 0;
			memset( _mt, 0, sizeof( U64 ) * CMATH_N );
			_mti = CMATH_N + 1;
		}
		
		void Random::Randomize()
		{
			SetRandomSeed( static_cast<U32>( time( NULL ) ) );
		}
		
		U32 Random::Value( U32 n )
		{
			U64 y;
			static U64 mag01[2] = {0x0, CMATH_MATRIX_A};
			
			if ( n == 0 )
			{
				return 0;
			}
			
			// generate N words at one time
			if ( _mti >= CMATH_N )
			{
				I32 kk;
				
				if ( _mti == CMATH_N + 1 )
				{
					// a default initial seed is used
					SetRandomSeed( 4357 );
				}
				
				for ( kk = 0; kk < CMATH_N - CMATH_M; kk++ )
				{
					y = ( _mt[kk] & CMATH_UPPER_MASK ) | ( _mt[kk + 1] & CMATH_LOWER_MASK );
					_mt[kk] = _mt[kk + CMATH_M] ^ ( y >> 1 ) ^ mag01[y & 0x1];
				}
				
				for ( ; kk < CMATH_N - 1; kk++ )
				{
					y = ( _mt[kk] & CMATH_UPPER_MASK ) | ( _mt[kk + 1] & CMATH_LOWER_MASK );
					_mt[kk] = _mt[kk + ( CMATH_M - CMATH_N )] ^ ( y >> 1 ) ^ mag01[y & 0x1];
				}
				
				y = ( _mt[CMATH_N - 1] & CMATH_UPPER_MASK ) | ( _mt[0] & CMATH_LOWER_MASK );
				_mt[CMATH_N - 1] = _mt[CMATH_M - 1] ^ ( y >> 1 ) ^ mag01[y & 0x1];
				
				_mti = 0;
			}
			
			y = _mt[_mti++];
			y ^= CMATH_TEMPERING_SHIFT_U( y );
			y ^= CMATH_TEMPERING_SHIFT_S( y ) & CMATH_TEMPERING_MASK_B;
			y ^= CMATH_TEMPERING_SHIFT_T( y ) & CMATH_TEMPERING_MASK_C;
			y ^= CMATH_TEMPERING_SHIFT_L( y );
			
			return y % n;
		}
		
		F32 Random::Value()
		{
			I32 r = ( F32 )Value( 0xffffffff );
			F32 divisor = static_cast<F32>( 0xffffffff );
			return ( r / divisor ) + 0.5f;
		}
		
		F32 Random::Range( F32 min, F32 max )
		{
			if ( min >= max )
			{
				// bad input...
				return min;
			}
			
			F32 f = Value();
			return ( f * ( max - min ) ) + min;
		}
		
		void Random::SetRandomSeed( U32 newSeed )
		{
			// setting initial seeds to m_mt[N] using
			// the generator Line 25 of Table 1 in
			// [KNUTH 1981, The Art of Computer Programming
			//    Vol. 2 (2nd Ed.), pp102]
			_mt[0] = newSeed & 0xffffffff;
			
			for ( _mti = 1; _mti < CMATH_N; _mti++ )
			{
				_mt[_mti] = ( 69069 * _mt[_mti - 1] ) & 0xffffffff;
			}
			
			_seed = newSeed;
		}
	}
}
