/*
 * @file Vector4.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 4D Vector.
 */

#include "Vector4.h"

#include "Vector3.h"
#include "Point3.h"

#include "app/EmberApp.h"

namespace ember
{
	namespace math
	{
		using namespace ember::app;
		
		const Vector4 Up4( Up );
		const Vector4 Right4( Right );
		const Vector4 Forward4( Forward );
		
		Vector4::Vector4( const Point3 &pt )
		{
			_vec[0] = pt.X();
			_vec[1] = pt.Y();
			_vec[2] = pt.Z();
			_vec[3] = 1.0f;
		}
		
		Vector4::Vector4( const Vector3 &vec3 )
		{
			_vec[0] = vec3.X();
			_vec[1] = vec3.Y();
			_vec[2] = vec3.Z();
			_vec[3] = 0.0f;
		}
		
		Vector4 &Vector4::operator=( const Point3 &rhs )
		{
			_vec[0] = rhs.X();
			_vec[1] = rhs.Y();
			_vec[2] = rhs.Z();
			_vec[3] = 1.0f;
			return *this;
		}
		
		Vector4 &Vector4::operator=( const Vector3 &rhs )
		{
			_vec[0] = rhs.X();
			_vec[1] = rhs.Y();
			_vec[2] = rhs.Z();
			_vec[3] = 0.0f;
			
			return *this ;
		};
		
		Vector4 &Lerp( const Vector4 &a, const Vector4 &b, F32 value, Vector4 &outVec )
		{
			value = Clamp01( value );
			outVec.Set( Interpolate( value, a.X(), b.X() ), \
			            Interpolate( value, a.Y(), b.Y() ), \
			            Interpolate( value, a.Z(), b.Z() ), \
			            Interpolate( value, a.W(), b.W() ) );
			return outVec;
		}
		
		Vector4 &RandomVector4( const Vector4 &min, const Vector4 &max, Vector4 &outVec )
		{
			outVec.SetX( Application->RNG()->Range( min.X(), max.X() ) );
			outVec.SetY( Application->RNG()->Range( min.Y(), max.Y() ) );
			outVec.SetZ( Application->RNG()->Range( min.Z(), max.Z() ) );
			outVec.SetW( Application->RNG()->Range( min.W(), max.W() ) );
			return outVec;
		}
	}
}
