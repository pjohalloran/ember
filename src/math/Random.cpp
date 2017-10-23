/*
 * @file Random.cpp
 * @author PJ O Halloran
 * @date 22/12/2016
 */

#include "Random.h"

#include <cstring>
#include <ctime>

#include <chrono>
#include <functional>

namespace ember
{
	namespace math
	{
		Random::Random() : _rand()
		{
			auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
			_rand = std::mt19937( seed );
		}
		
		void Random::Randomize()
		{
			auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
			_rand = std::mt19937( seed );
		}
		
		U32 Random::Value()
		{
			return _rand();
		}
		
		F32 Random::ValueF32()
		{
			I32 r = static_cast<F32>( Value() );
			F32 divisor = static_cast<F32>( 0xffffffff );
			return ( r / divisor ) + 0.5f;
		}
		
		U32 Random::Range( U32 min, U32 max )
		{
			auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
			auto rangeRand = std::bind( std::uniform_int_distribution<U32>( min, max ), std::mt19937( seed ) );
			return rangeRand();
		}
		
		F32 Random::Range( F32 min, F32 max )
		{
			auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
			auto rangeRand = std::bind( std::uniform_real_distribution<F32>( min, max ), std::mt19937( seed ) );
			return rangeRand();
		}
	}
}
