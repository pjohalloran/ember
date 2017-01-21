#pragma once
#ifndef __EMBER_RANDOM_H
#define __EMBER_RANDOM_H

/*
 * @file Random.h
 * @date 22/12/2016
 */

#include "core/EmberTypes.h"

#include <random>

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		class Random
		{
			private:
			
				std::mt19937 _rand;
				
			public:
			
				Random();
				~Random() {};
				
				void Randomize();
				
				U32 Value();
				
				F32 ValueF32();
				
				U32 Range( U32 min, U32 max );
				
				F32 Range( F32 min, F32 max );
				
				inline F32 Range01()
				{
					return Range( 0.0f, 1.0f );
				};
		};
	}
}

#undef CMATH_N

#endif
