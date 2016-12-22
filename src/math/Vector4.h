#pragma once
#ifndef __EMBER_VECTOR4_H
#define __EMBER_VECTOR4_H

/*
 * @file Vector4.h
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 4D Vector.
 */

#include "EmberMathDefines.h"
#include "EmberMathUtils.h"

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		class Point3;
		class Vector3;
		
		class Vector4
		{
			private:
			
				static const U32 Size = 4;
				
				F32 _vec[Size];
				
			public:
			
				explicit inline Vector4()
				{
					memset( _vec, 0, sizeof( F32 ) * Size );
				};
				
				explicit inline Vector4( const F32 x, const F32 y, const F32 z, const F32 w )
				{
					_vec[0] = x;
					_vec[1] = y;
					_vec[2] = z;
					_vec[3] = w;
				};
				
				explicit inline Vector4( const F32 scaler )
				{
					_vec[0] = scaler;
					_vec[1] = scaler;
					_vec[2] = scaler;
					_vec[3] = scaler;
				};
				
				explicit inline Vector4( const F32 vecArr[Size] )
				{
					memcpy( _vec, vecArr, sizeof( F32 ) * Size );
				};
				
				inline Vector4( const Vector4 &copyVec )
				{
					memcpy( _vec, copyVec._vec, sizeof( F32 ) * Size );
				};
				
				/*
				 * Converts a 3D point to a positional Vector4 with a w component (with
				 * a value of 1).
				 *
				 * The Vector4 has a w component of 1 to make scaling unnessecary as
				 * homogenous coordinates with a w value greater than 1 must have their
				 * xyz coordinates divided by the w component to get the original 3D
				 * point (See Mathematics for Computer Graphics b John Vince, 2nd
				 * Edition, Chapter 7 Transformations, pg. 57).
				 */
				explicit Vector4( const Point3 &pt );
				
				/*
				 * Converts a 3D vector to a 4D vector with a w component(with a
				 * value of 0).
				 *
				 * A vector is defined by two points [x, y, z, 1] and [x', y', z', 1].
				 * The reason that the w component of the 4D homogenous vector is 0 is
				 * that the w component collapses to 0 when you subtract two points
				 * (See Mathematics for Computer Graphics by John Vince, 2nd Edition,
				 * Chapter 7 Transformations, pg. 99).
				 */
				explicit Vector4( const Vector3 &vec3 );
				
				~Vector4() { };
				
				inline F32 X() const
				{
					return ( _vec[0] );
				};
				
				inline F32 Y() const
				{
					return ( _vec[1] );
				};
				
				inline F32 Z() const
				{
					return ( _vec[2] );
				};
				
				inline F32 W() const
				{
					return ( _vec[3] );
				};
				
				inline void SetX( const F32 x )
				{
					_vec[0] = x;
				};
				
				inline void SetY( const F32 y )
				{
					_vec[1] = y;
				};
				
				inline void SetZ( const F32 z )
				{
					_vec[2] = z;
				};
				
				inline void SetW( const F32 w )
				{
					_vec[3] = w;
				};
				
				inline void Set( const F32 x, const F32 y, const F32 z, const F32 w )
				{
					_vec[0] = x;
					_vec[1] = y;
					_vec[2] = z;
					_vec[3] = w;
				};
				
				inline Vector4 &operator=( const Vector4 &rhs )
				{
					if ( this == &rhs )
					{
						return *this;
					}
					
					_vec[0] = rhs._vec[0];
					_vec[1] = rhs._vec[1];
					_vec[2] = rhs._vec[2];
					_vec[3] = rhs._vec[3];
					
					return *this;
				};
				
				Vector4 &operator=( const Vector3 &rhs );
				
				Vector4 &operator=( const Point3 &rhs );
				
				inline bool operator==( const Vector4 &rhs ) const
				{
					if ( this == &rhs )
					{
						return ( true );
					}
					
					return ( Compare( _vec[0], rhs._vec[0] ) && \
					         Compare( _vec[1], rhs._vec[1] ) && \
					         Compare( _vec[2], rhs._vec[2] ) && \
					         Compare( _vec[3], rhs._vec[3] ) );
				};
				
				inline bool operator!=( const Vector4 &rhs ) const
				{
					return !( *this == rhs );
				};
				
				inline Vector4 operator+( const Vector4 &rhs ) const
				{
					return Vector4( _vec[0] + rhs._vec[0], \
					                _vec[1] + rhs._vec[1], \
					                _vec[2] + rhs._vec[2], \
					                _vec[3] + rhs._vec[3] );
				};
				
				inline Vector4 operator-( const Vector4 &rhs ) const
				{
					return Vector4( _vec[0] - rhs._vec[0], \
					                _vec[1] - rhs._vec[1], \
					                _vec[2] - rhs._vec[2], \
					                _vec[3] - rhs._vec[3] );
				};
				
				inline Vector4 &operator+=( const Vector4 &rhs )
				{
					_vec[0] += rhs._vec[0];
					_vec[1] += rhs._vec[1];
					_vec[2] += rhs._vec[2];
					_vec[3] += rhs._vec[3];
					return ( *this );
				};
				
				inline Vector4 &operator-=( const Vector4 &rhs )
				{
					_vec[0] -= rhs._vec[0];
					_vec[1] -= rhs._vec[1];
					_vec[2] -= rhs._vec[2];
					_vec[3] -= rhs._vec[3];
					return ( *this );
				};
				
				inline Vector4 operator-() const
				{
					return Vector4( -_vec[0], -_vec[1], -_vec[2], -_vec[3] );
				};
				
				inline Vector4 operator*( const F32 scaler ) const
				{
					Vector4 copy( *this );
					
					copy._vec[0] *= scaler;
					copy._vec[1] *= scaler;
					copy._vec[2] *= scaler;
					copy._vec[3] *= scaler;
					
					return copy;
				};
				
				inline Vector4 operator/( const F32 scaler ) const
				{
					Vector4 copy( *this );
					
					if ( !Compare( scaler, 0.0f ) )
					{
						copy._vec[0] /= scaler;
						copy._vec[1] /= scaler;
						copy._vec[2] /= scaler;
						copy._vec[3] /= scaler;
					}
					
					return copy;
				};
				
				inline Vector4 &operator*=( const F32 scaler )
				{
					_vec[0] *= scaler;
					_vec[1] *= scaler;
					_vec[2] *= scaler;
					_vec[3] *= scaler;
					return *this;
				};
				
				inline Vector4 &operator/=( const F32 scaler )
				{
					if ( !Compare( scaler, 0.0f ) )
					{
						_vec[0] /= scaler;
						_vec[1] /= scaler;
						_vec[2] /= scaler;
						_vec[3] /= scaler;
					}
					
					return *this;
				};
				
				inline bool operator<( const Vector4 &rhs ) const
				{
					return ( MagnitudeSqr() < rhs.MagnitudeSqr() );
				};
				
				/*
				 * Get the magnitude squared of this vector otherwise known as the
				 * length of the vector.
				 *
				 * This version does not compute the square root and has no casts so
				 * is faster if you want to compare two vectors lengths.  If you need
				 * the actual length of the vector for some operation then you should
				 * use the Magnitude() method instead.
				 *
				 * @return F32 The magnitude or length of this vector squared.
				 */
				inline F32 MagnitudeSqr() const
				{
					return ( _vec[0] * _vec[0] ) + \
					       ( _vec[1] * _vec[1] ) + \
					       ( _vec[2] * _vec[2] ) + \
					       ( _vec[3] * _vec[3] );
				};
				
				/*
				 * Get the magnitude of this vector otherwise known as the
				 * length of the vector.
				 *
				 * @return F32 The magnitude or length of this vector.
				 */
				inline F32 Magnitude() const
				{
					return ( static_cast<F32>( sqrt( static_cast<F32>( MagnitudeSqr() ) ) ) );
				};
				
				inline Vector4 &Normalize()
				{
					const F32 length = Magnitude();
					
					if ( !Compare( length, 0.0f ) )
					{
						_vec[0] /= length;
						_vec[1] /= length;
						_vec[2] /= length;
						_vec[3] /= length;
					}
					
					return *this;
				};
				
				/*
				 * Normalize this vector and store the result in the vector supplied
				 * so as to NOT to modify this vector.
				 *
				 * @param outVecRef The vector to store the result of normalizing this
				 *                      vector in.
				 */
				inline void Normalized( Vector4 &outVecRef ) const
				{
					const F32 length = Magnitude();
					
					if ( !Compare( length, 0.0f ) )
					{
						outVecRef._vec[0] = _vec[0] / length;
						outVecRef._vec[1] = _vec[1] / length;
						outVecRef._vec[2] = _vec[2] / length;
						outVecRef._vec[3] = _vec[3] / length;
					}
				};
				
				/*
				 * Calculate the dot product of this vector and another vector.
				 * Otherwise known as the scaler product.
				 *
				 * Useful for back face culling or lighting calculations as it may be
				 * used to calculate the angle between two vector.
				 *
				 * e.g. If a plane/primitives surface normal vectors' angle to this
				 * vector is > 90, then it is said to be a back facing plane/primitive.
				 *
				 * @param rhsVecRef The other vector to use to get the scaler or dot
				 *                      product of, along with this vector.
				 */
				inline F32 Dot( const Vector4 &rhsVecRef ) const
				{
					return ( _vec[0] * rhsVecRef._vec[0] ) + \
					       ( _vec[1] * rhsVecRef._vec[1] ) + \
					       ( _vec[2] * rhsVecRef._vec[2] ) + \
					       ( _vec[3] * rhsVecRef._vec[3] );
				};
				
				inline const char *ToString() const
				{
					#ifdef EMBER_MATH_TO_STRING
					std::stringstream strStream;
					strStream << "[" << _vec[0] << ", " << _vec[1] << ", " << _vec[2] << ", " << _vec[3] << "]";
					return strStream.str().c_str();
					#else
					return "";
					#endif
				}
				
				inline const F32 *const GetComponentsConst() const
				{
					return _vec;
				};
		};
		
		extern const Vector4 UpDir4;
		extern const Vector4 RightDir4;
		extern const Vector4 ForwardDir4;
		
		inline Vector4 operator*( const F32 lhs, const Vector4 &rhs )
		{
			Vector4 copy( rhs );
			copy = rhs * lhs;
			return copy;
		};
		
		/*
		 * Performs linear interpolation on two 4 component vectors.
		 *
		 * @param a The start vector.
		 * @param b The end vector.
		 * @param interpolateVal Interpolation value (should be between 0
		 *                          and 1, if not it is clamped).
		 * @param outVec Output vector.
		 *
		 * @return Vector4& Output vector.
		 */
		Vector4 &Lerp( const Vector4 &a, const Vector4 &b, F32 value, Vector4 &outVec );
		
		/*
		 * Generate a Vector4 with random xyzw components.
		 *
		 * @param min The minimum vector.
		 * @param max The maximum vector.
		 * @param outVec The Vector to hold the random componenets.
		 *
		 * @return Vector4& A reference to the vector with the random
		 *                  components. It refers to the same object passed
		 *                  in.
		 */
		Vector4 &RandomVector4( const Vector4 &min, const Vector4 &max, Vector4 &outVec );
	}
}
#endif
