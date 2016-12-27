#pragma once
#ifndef __EMBER_RANDOM_H
#define __EMBER_RANDOM_H

/*
 * @file Random.h
 * @date 22/12/2016
 *
 * This is a Mersenne Twister pseudorandom number generator
 * originally developed by Takuji Nishimura and Makoto Matsumoto.
 */

#include "core/EmberTypes.h"

#define CMATH_N 624

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		class Random
		{
			private:
			
				U32 _seed;
				U32 _seedSp;
				U64 _mt[CMATH_N];
				I32 _mti;
				
			public:
			
				Random();
				~Random() {};
				
				void Randomize();
				
				void SetRandomSeed( U32 newSeed );
				
				U32 Value( U32 n );
				
				F32 Value();
				
				F32 Range( F32 min, F32 max );
				
				inline F32 Range01()
				{
					return Range( 0.0f, 1.0f );
				};
				
				inline U32 GetRandomSeed() const
				{
					return _seed;
				};
		};
	}
}

#undef CMATH_N

#endif
