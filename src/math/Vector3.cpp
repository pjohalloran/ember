/*
 * @file Vector3.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 3D Vector.
 */

#include "Vector3.h"

#include "Point3.h"
#include "Vector4.h"

#include "app/EmberApp.h"

namespace ember
{
	namespace math
	{
		using namespace ember::app;
		
		const Vector3 XAxis( 1.0f, 0.0f, 0.0f );
		const Vector3 YAxis( 0.0f, 1.0f, 0.0f );
		const Vector3 ZAxis( 0.0f, 0.0f, 1.0f );
		const Vector3 Up( 0.0f, 1.0f, 0.0f );
		const Vector3 Right( 1.0f, 0.0f, 0.0f );
		const Vector3 Forward( 0.0f, 0.0f, -1.0f );
		
		Vector3::Vector3( const Point3 &pt )
		{
			_vec[0] = pt.X();
			_vec[1] = pt.Y();
			_vec[2] = pt.Z();
		}
		
		Vector3::Vector3( const Vector4 &vec4 )
		{
			if ( vec4.W() > 0.0f )
			{
				_vec[0] = vec4.X() / vec4.W();
				_vec[1] = vec4.Y() / vec4.W();
				_vec[2] = vec4.Z() / vec4.W();
			}
			else
			{
				_vec[0] = vec4.X();
				_vec[1] = vec4.Y();
				_vec[2] = vec4.Z();
			}
		}
		
		Vector3 &Vector3::operator=( const Vector4 &rhs )
		{
			if ( !Compare( rhs.W(), 0.0f ) )
			{
				_vec[0] = rhs.X() / rhs.W();
				_vec[1] = rhs.Y() / rhs.W();
				_vec[2] = rhs.Z() / rhs.W();
			}
			else
			{
				_vec[0] = rhs.X();
				_vec[1] = rhs.Y();
				_vec[2] = rhs.Z();
			}
			
			return *this;
		};
		
		Vector3 &Vector3::operator=( const Point3 &rhs )
		{
			_vec[0] = rhs.X();
			_vec[1] = rhs.Y();
			_vec[2] = rhs.Z();
			return *this;
		};
		
		Vector3 &Vector3Lerp( const Vector3 &a, const Vector3 &b, F32 lerpValue, Vector3 &outVec )
		{
			lerpValue = Clamp01( lerpValue );
			outVec.Set( Interpolate( lerpValue, a.X(), b.X() ), \
			            Interpolate( lerpValue, a.Y(), b.Y() ), \
			            Interpolate( lerpValue, a.Z(), b.Z() ) );
			return outVec;
		}
		
		Vector3 &RandomVector3( const Vector3 &min, const Vector3 &max, Vector3 &outVec )
		{
			outVec.SetX( Application->RNG()->Range( min.X(), max.X() ) );
			outVec.SetY( Application->RNG()->Range( min.Y(), max.Y() ) );
			outVec.SetZ( Application->RNG()->Range( min.Z(), max.Z() ) );
			return outVec;
		}
	}
}
