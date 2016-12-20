#pragma once
#ifndef __EMBER_MATH_UTILS_H
#define __EMBER_MATH_UTILS_H

/*
 * @file EmberMathUtils.h
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * Common Math utilities.
 */

#include <cmath>

#include "core/EmberTypes.h"

#define F64_ERROR_DELTA 0.000001
#define F32_ERROR_DELTA 0.000001f
#define PI 3.14159265358979323846
#define TWO_PI 2.0 * PI
#define PI_DIV_180 0.017453292519943296
#define INV_PI_DIV_180 57.2957795130823229
#define DegreesToRadians(x) ((x)*PI_DIV_180)
#define RadiansToDegrees(x) ((x)*INV_PI_DIV_180)
#define HoursToDegrees(x) ((x) * (1.0 / 15.0))
#define HoursToRadians(x) DegreesToRadians(HoursToDegrees(x))
#define DegreesToHours(x) ((x) * 15.0))
#define RadiansToHours(x) DegreesToHours(RadiansToDegrees(x))

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		inline bool Compare( const F32 a, const F32 b, const F32 epsilon = F32_ERROR_DELTA )
		{
			return std::abs( a - b ) <= epsilon;
		};
		
		inline bool Compare( const F64 a, const F64 b, const F64 epsilon = F64_ERROR_DELTA )
		{
			return std::abs( a - b ) <= epsilon;
		};
		
		inline F32 Interpolate( const F32 value, const F32 min, const F32 max )
		{
			return min + ( value * ( max - min ) );
		};
		
		inline F64 Interpolate( const F64 value, const F64 min, const F64 max )
		{
			return min + ( value * ( max - min ) );
		};
		
		template<typename T>
		bool Clamp( T &value, const T &min, const T &max )
		{
			bool clamp = false;
			
			if ( value < min )
			{
				clamp = true;
				value = min;
			}
			else if ( value > max )
			{
				clamp = true;
				value = max;
			}
			
			return clamp;
		};
		
		F32 Clamp01( const F32 value );
		
		F64 Clamp01( const F64 value );
		
		template<typename T>
		T Max( const T &a, const T &b )
		{
			if ( a > b )
			{
				return a;
			}
			
			return b;
		};
		
		template<typename T>
		T Min( const T &a, const T &b )
		{
			if ( a < b )
			{
				return a;
			}
			
			return b;
		};
	}
}

#endif
