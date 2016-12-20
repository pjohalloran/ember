/*
 * @file Vector4.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 4D Vector.
 */

#include "Vector4.h"

#include "Point3.h"

namespace ember
{
	namespace math
	{
		const Vector4 Up4( Up );
		const Vector4 Right4( Right );
		const Vector4 Forward4( Forward );
		
		Vector4::Vector4( const Point3 &pt )
		{
			m_vec[0] = pt.X();
			m_vec[1] = pt.Y();
			m_vec[2] = pt.Z();
			m_vec[3] = 1.0f;
		}
		
		Vector4 &Vector4::operator=( const Point3 &rhs )
		{
			m_vec[0] = rhs.X();
			m_vec[1] = rhs.Y();
			m_vec[2] = rhs.Z();
			m_vec[3] = 1.0f;
			return *this;
		}
		
		Vector4 &Vector4Lerp( const Vector4 &a, const Vector4 &b, const F32 value, Vector4 &outVec )
		{
			value = Clamp01( value );
			outVec.Set( InterpolateFloat( value, a.X(), b.X() ), \
			            InterpolateFloat( value, a.Y(), b.Y() ), \
			            InterpolateFloat( value, a.Z(), b.Z() ), \
			            InterpolateFloat( value, a.W(), b.W() ) );
			return outVec;
		}
		
		Vector4 &Random( CRandom &rng, const Vector4 &min, const Vector4 &max, Vector4 &outVec )
		{
			outVec.SetX( rng.Random( min.X(), max.X() ) );
			outVec.SetY( rng.Random( min.Y(), max.Y() ) );
			outVec.SetZ( rng.Random( min.Z(), max.Z() ) );
			outVec.SetW( rng.Random( min.W(), max.W() ) );
			return outVec;
		}
	}
}