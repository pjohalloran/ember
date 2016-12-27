/*
 * @file Point3.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 3D point in space.
 */

#include "Point3.h"

#include "Vector3.h"
#include "Vector4.h"

#include "app/EmberApp.h"

namespace ember
{
	namespace math
	{
		using namespace ember::app;
		
		const Point3 Origin( 0.0f, 0.0f, 0.0f );
		
		Point3::Point3( const Vector3 &vec )
		{
			_vec[0] = vec.X();
			_vec[1] = vec.Y();
			_vec[2] = vec.Z();
		}
		
		Point3 &Point3::operator=( const Vector3 &rhs )
		{
			_vec[0] = rhs.X();
			_vec[1] = rhs.Y();
			_vec[2] = rhs.Z();
			return *this;
		}
		
		Vector3 Point3::operator-( const Point3 &rhs ) const
		{
			return Vector3( _vec[0] - rhs._vec[0], \
			                _vec[1] - rhs._vec[1], \
			                _vec[2] - rhs._vec[2] );
		}
		
		Point3 Point3::operator+( const Vector3 &rhs ) const
		{
			return Point3( _vec[0] + rhs.X(), \
			               _vec[1] + rhs.Y(), \
			               _vec[2] + rhs.Z() );
		}
		
		Point3 Point3::operator-( const Vector3 &rhs ) const
		{
			return Point3( _vec[0] - rhs.X(), \
			               _vec[1] - rhs.Y(), \
			               _vec[2] - rhs.Z() );
		}
		
		Point3 &Point3::operator+=( const Vector3 &rhs )
		{
			_vec[0] += rhs.X();
			_vec[1] += rhs.Y();
			_vec[2] += rhs.Z();
			return *this;
		}
		
		Point3 &Point3::operator-=( const Vector3 &rhs )
		{
			_vec[0] -= rhs.X();
			_vec[1] -= rhs.Y();
			_vec[2] -= rhs.Z();
			return *this;
		}
		
		Point3 &Lerp( const Point3 &a, const Point3 &b, F32 value, Point3 &outPt )
		{
			value = Clamp01( value );
			outPt.Set( Interpolate( value, a.X(), b.X() ), \
			           Interpolate( value, a.Y(), b.Y() ), \
			           Interpolate( value, a.Z(), b.Z() ) );
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
		
		Vector3 &CalculateUnitNormal( const Point3 &ptOne, const Point3 &ptTwo, const Point3 &ptThree, Vector3 &normalOut )
		{
			normalOut = CalculateNormal( ptOne, ptTwo, ptThree, normalOut );
			normalOut.Normalize();
			return normalOut;
		};
		
		Point3 &RandomPoint3( const Point3 &min, const Point3 &max, Point3 &pt )
		{
			pt.SetX( Application->RNG()->Range( min.X(), max.X() ) );
			pt.SetY( Application->RNG()->Range( min.Y(), max.Y() ) );
			pt.SetZ( Application->RNG()->Range( min.Z(), max.Z() ) );
			return pt;
		}
	}
}
