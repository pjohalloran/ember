#pragma once
#ifndef __EMBER_VECTOR3_H
#define __EMBER_VECTOR3_H

/*
 * @file Vector3.h
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 3D Vector.
 */

#include <cstring>

#include "core/EmberTypes.h"
#include "EmberMathUtils.h"

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		class Point3;
		class Vector4;
		
		class Vector3
		{
			private:
			
				static const U32 Size = 3;
				
				F32 _vec[Size];
				
			public:
			
				explicit inline Vector3()
				{
					memset( _vec, 0, sizeof( F32 ) * Size );
				};
				
				explicit inline Vector3( const F32 x, const F32 y, const F32 z )
				{
					_vec[0] = x;
					_vec[1] = y;
					_vec[2] = z;
				};
				
				explicit inline Vector3( const F32 scaler )
				{
					_vec[0] = scaler;
					_vec[1] = scaler;
					_vec[2] = scaler;
				};
				
				explicit inline Vector3( const F32 vecArr[Size] )
				{
					memcpy( _vec, vecArr, sizeof( F32 ) * Size );
				};
				
				inline Vector3( const Vector3 &copyVec )
				{
					memcpy( _vec, copyVec._vec, sizeof( F32 ) * Size );
				};
				
				explicit Vector3( const Point3 &pt );
				
				explicit Vector3( const Vector4 &vec4 );
				
				~Vector3() { };
				
				inline F32 X() const
				{
					return _vec[0];
				};
				
				inline F32 Y() const
				{
					return _vec[1];
				};
				
				inline F32 Z() const
				{
					return _vec[2];
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
				
				inline void Set( const F32 x, const F32 y, const F32 z )
				{
					_vec[0] = x;
					_vec[1] = y;
					_vec[2] = z;
				};
				
				inline Vector3 &operator=( const Vector3 &rhs )
				{
					if ( this == &rhs )
					{
						return *this;
					}
					
					_vec[0] = rhs._vec[0];
					_vec[1] = rhs._vec[1];
					_vec[2] = rhs._vec[2];
					
					return *this;
				};
				
				Vector3 &operator=( const Vector4 &rhs );
				Vector3 &operator=( const Point3 &rhs );
				
				inline bool operator==( const Vector3 &rhs ) const
				{
					if ( this == &rhs )
					{
						return true;
					}
					
					return Compare( _vec[0], rhs._vec[0] ) && Compare( _vec[1], rhs._vec[1] ) && Compare( _vec[2], rhs._vec[2] );
				};
				
				inline bool operator!=( const Vector3 &rhs ) const
				{
					return !( *this == rhs );
				};
				
				inline Vector3 operator+( const Vector3 &rhs ) const
				{
					return Vector3( _vec[0] + rhs._vec[0], _vec[1] + rhs._vec[1], _vec[2] + rhs._vec[2] );
				};
				
				inline Vector3 operator-( const Vector3 &rhs ) const
				{
					return Vector3( _vec[0] - rhs._vec[0], _vec[1] - rhs._vec[1], _vec[2] - rhs._vec[2] );
				};
				
				inline Vector3 &operator+=( const Vector3 &rhs )
				{
					_vec[0] += rhs._vec[0];
					_vec[1] += rhs._vec[1];
					_vec[2] += rhs._vec[2];
					return *this;
				};
				
				inline Vector3 &operator-=( const Vector3 &rhs )
				{
					_vec[0] -= rhs._vec[0];
					_vec[1] -= rhs._vec[1];
					_vec[2] -= rhs._vec[2];
					return *this;
				};
				
				inline Vector3 operator-() const
				{
					return Vector3( -_vec[0], -_vec[1], -_vec[2] );
				};
				
				inline Vector3 operator*( const F32 scaler ) const
				{
					Vector3 copy( *this );
					copy._vec[0] *= scaler;
					copy._vec[1] *= scaler;
					copy._vec[2] *= scaler;
					return copy;
				};
				
				inline Vector3 operator/( const F32 scaler ) const
				{
					Vector3 copy( *this );
					
					if ( !Compare( scaler, 0.0f ) )
					{
						copy._vec[0] /= scaler;
						copy._vec[1] /= scaler;
						copy._vec[2] /= scaler;
					}
					
					return copy;
				};
				
				inline Vector3 &operator*=( const F32 scaler )
				{
					_vec[0] *= scaler;
					_vec[1] *= scaler;
					_vec[2] *= scaler;
					return *this;
				};
				
				inline Vector3 &operator/=( const F32 scaler )
				{
					if ( !Compare( scaler, 0.0f ) )
					{
						_vec[0] /= scaler;
						_vec[1] /= scaler;
						_vec[2] /= scaler;
					}
					
					return *this;
				};
				
				inline bool operator<( const Vector3 &rhs ) const
				{
					return MagnitudeSqr() < rhs.MagnitudeSqr();
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
					       ( _vec[2] * _vec[2] );
				};
				
				/*
				 * Get the magnitude of this vector otherwise known as the
				 * length of the vector.
				 *
				 * @return F32 The magnitude or length of this vector.
				 */
				inline F32 Magnitude() const
				{
					return static_cast<F32>( sqrt( static_cast<F32>( MagnitudeSqr() ) ) );
				};
				
				inline Vector3 &Normalize()
				{
					const F32 length = Magnitude();
					
					if ( !Compare( length, 0.0f ) )
					{
						_vec[0] /= length;
						_vec[1] /= length;
						_vec[2] /= length;
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
				inline Vector3 Normalized() const
				{
					Vector3 out;
					const F32 length = Magnitude();
					
					if ( !Compare( length, 0.0f ) )
					{
						out._vec[0] = _vec[0] / length;
						out._vec[1] = _vec[1] / length;
						out._vec[2] = _vec[2] / length;
					}
					
					return out;
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
				inline F32 Dot( const Vector3 &rhsVecRef ) const
				{
					return _vec[0] * rhsVecRef._vec[0] + _vec[1] * rhsVecRef._vec[1] + _vec[2] * rhsVecRef._vec[2];
				};
				
				/*
				 * Calculate the cross product of two vectors.
				 * The resultant vector is orthogonal to this and the other vector.
				 *
				 * Useful for getting the surface normal vector of two vectors.
				 *
				 * @param rhsVecRef The other vector to use to get the scaler or dot
				 *                      product of, along with this vector.
				 */
				inline void Cross( const Vector3 &rhsVecRef, Vector3 &outVecRef ) const
				{
					outVecRef._vec[0] = _vec[1] * rhsVecRef._vec[2] - _vec[2] * rhsVecRef._vec[1];
					outVecRef._vec[1] = -( _vec[0] * rhsVecRef._vec[2] - _vec[2] * rhsVecRef._vec[0] );
					outVecRef._vec[2] = _vec[0] * rhsVecRef._vec[1] - _vec[1] * rhsVecRef._vec[0];
				};
				
				inline std::string ToString() const
				{
					#ifdef EMBER_MATH_TO_STRING
				
					std::stringstream strStream;
					strStream << "[" << _vec[0] << ", " << _vec[1] << ", " << _vec[2] << "]";
					return strStream.str();
					
					#else
					
					return "";
					
					#endif
				};
				
				inline const F32 *const GetComponentsConst() const
				{
					return _vec;
				};
		};
		
		extern const Vector3 Up;
		extern const Vector3 Right;
		extern const Vector3 Forward;
		extern const Vector3 XAxis;
		extern const Vector3 YAxis;
		extern const Vector3 ZAxis;
		
		inline Vector3 operator*( const F32 lhs, const Vector3 &rhs )
		{
			Vector3 copy( rhs );
			copy = rhs * lhs;
			return copy;
		};
		
		/*
		 * Get the angle between two vectors using the dot product.
		 *
		 * @param u The first vector.
		 * @param v The second vector.
		 *
		 * @F32 The angle between the two vectors (in degrees).
		 */
		inline F32 AngleBetween( const Vector3 &u, const Vector3 &v )
		{
			F64 dot = static_cast<F64>( u.Dot( v ) );
			return static_cast<F32>( RadiansToDegrees( acos( dot ) ) );
		};
		
		/*
		 * Check if a vector is a normal vector (of length 1).
		 *
		 * @param vecRef The vector to perform the check upon.
		 *
		 * @return bool True if the vector is of unit length and false if not.
		 */
		inline bool IsNormalized( const Vector3 &vecRef )
		{
			return Compare( vecRef.Magnitude(), 1.0f );
		};
		
		/*
		 * Performs linear interpolation on two 3 component vectors.
		 *
		 * @param a The start vector.
		 * @param b The end vector.
		 * @param interpolateVal Interpolation value.
		 * @param outVec Output vector.
		 *
		 * @return Vector3& Output vector.
		 */
		Vector3 &Lerp( const Vector3 &a, const Vector3 &b, F32 value, Vector3 &outVec );
		
		/*
		 * Generate a Vector3 with random xyz components between a defined
		 * range.
		 *
		 * @param rng The random number generator.
		 * @param min The minimum vector.
		 * @param max The maximum vector.
		 * @param outVec The Vector to hold the random componenets.
		 *
		 * @return Vector3& A reference to the vector with the random
		 *                  components. It refers to the same object passed
		 *                  in.
		 */
		Vector3 &Random( CRandom &rng, const Vector3 &min, const Vector3 &max, Vector3 &outVec );
	}
}
#endif
