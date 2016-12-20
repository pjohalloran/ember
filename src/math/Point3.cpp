/*
 * @file Point3.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 3D point in space.
 */

#include "Vector4.h"

#include "Point3.h"

namespace ember
{
	namespace math
	{
		const Point3 Origin( 0.0f, 0.0f, 0.0f );
		
		Point3 &Lerp( const Point3 &a, const Point3 &b, const F32 value, Point3 &outPt )
		{
			value = Clamp01( value );
			outPt.Set( InterpolateFloat( value, a.GetX(), b.GetX() ), \
			           InterpolateFloat( value, a.GetY(), b.GetY() ), \
			           InterpolateFloat( value, a.GetZ(), b.GetZ() ) );
			return outPt;
		}
		
		Vector3 &CalculateNormal( const Point3 &ptOne, const Point3 &ptTwo, const Point3 &ptThree, Vector3 &normalOut )
		{
			Vector3 u, v;
			
			// See Mathematics for Computer Graphics, 2nd Edition by John Vince,
			// Chapter 6, Vectors, pg. 47 for details on how to calculate the
			// normal for a surface.
			u = ptThree - ptTwo;
			v = ptThree - ptOne;
			u.Cross( v, normalOut );
			
			return normalOut;
		}
		
		Point3 &Random( CRandom &rng, const Point3 &min, const Point3 &max, Point3 &pt )
		{
			pt.SetX( rng.Random( min.X(), max.X() ) );
			pt.SetY( rng.Random( min.Y(), max.Y() ) );
			pt.SetZ( rng.Random( min.Z(), max.Z() ) );
			return pt;
		}
	}
}