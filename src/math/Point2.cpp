/*
 * @file Point2.cpp
 * @author PJ O Halloran
 * @date 22/12/2016
 *
 * 2D point.
 */

#include "Point2.h"

#include "app/EmberApp.h"

namespace ember
{
	namespace math
	{
		using namespace ember::app;
		
		const Point2 Origin2( 0.0f, 0.0f );
		
		Point2 &Lerp( const Point2 &a, const Point2 &b, F32 value, Point2 &outPt )
		{
			value = Clamp01( value );
			outPt.Set( Interpolate( value, a.X(), b.X() ), \
			           Interpolate( value, a.Y(), b.Y() ) );
			return outPt;
		}
		
		Point2 &RandomPoint2( const Point2 &min, const Point2 &max, Point2 &pt )
		{
			pt.SetX( Application->RNG()->Range( min.X(), max.X() ) );
			pt.SetY( Application->RNG()->Range( min.Y(), max.Y() ) );
			return pt;
		}
	}
}
