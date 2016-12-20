/*
 * @file EmberMathUtils.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 */

#include "EmberMathUtils.h"

namespace ember
{
	namespace math
	{
		F32 Clamp01( F32 &value )
		{
			return Clamp<F32>( value, 0.0f, 1.0f );
		};
		
		F64 Clamp01( F64 &value )
		{
			return Clamp<F64>( value, 0.0, 1.0 );
		};
	}
}
