#pragma once
#ifndef __EMBER_POINT3_H
#define __EMBER_POINT3_H

/*
 * @file Point3.h
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * 3D Point in space.
 */

#include "EmberMathDefines.h"
#include "EmberMathUtils.h"

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		class Vector3;
		
		class Point3
		{
			private:
			
				static const U32 Size = 3;
				
				F32 _vec[Size];
				
			public:
			
				explicit inline Point3()
				{
					memset( _vec, 0, sizeof( F32 ) * Size );
				};
				
				explicit inline Point3( const F32 x, const F32 y, const F32 z )
				{
					_vec[0] = x;
					_vec[1] = y;
					_vec[2] = z;
				};
				
				explicit inline Point3( const F32 scaler )
				{
					_vec[0] = scaler;
					_vec[1] = scaler;
					_vec[2] = scaler;
				};
				
				explicit inline Point3( const F32 ptArr[Size] )
				{
					memcpy( _vec, ptArr, sizeof( F32 ) * Size );
				};
				
				inline Point3( const Point3 &copyPt )
				{
					memcpy( _vec, copyPt._vec, sizeof( F32 ) * Size );
				};
				
				explicit Point3( const Vector3 &vec );
				
				~Point3() { };
				
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
				
				inline Point3 &operator=( const Point3 &rhs )
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
				
				Point3 &operator=( const Vector3 &rhs );
				
				inline bool operator==( const Point3 &rhs ) const
				{
					if ( this == &rhs )
					{
						return true;
					}
					
					return Compare( _vec[0], rhs._vec[0] ) && \
					       Compare( _vec[1], rhs._vec[1] ) && \
					       Compare( _vec[2], rhs._vec[2] );
				};
				
				inline bool operator!=( const Point3 &rhs ) const
				{
					return !( *this == rhs );
				};
				
				Vector3 operator-( const Point3 &rhs ) const;
				
				Point3 operator+( const Vector3 &rhs ) const;
				
				Point3 operator-( const Vector3 &rhs ) const;
				
				Point3 &operator+=( const Vector3 &rhs );
				
				Point3 &operator-=( const Vector3 &rhs );
				
				inline Point3 operator-() const
				{
					return Point3( -_vec[0], -_vec[1], -_vec[2] );
				};
				
				inline bool operator<( const Point3 &rhs ) const
				{
					return ( _vec[0] < rhs._vec[0] ) && \
					       ( _vec[1] < rhs._vec[1] ) && \
					       ( _vec[2] < rhs._vec[2] );
				};
				
				inline bool operator<=( const Point3 &rhs ) const
				{
					return ( _vec[0] <= rhs._vec[0] ) && \
					       ( _vec[1] <= rhs._vec[1] ) && \
					       ( _vec[2] <= rhs._vec[2] );
				};
				
				inline bool operator>( const Point3 &rhs ) const
				{
					return ( _vec[0] > rhs._vec[0] ) && \
					       ( _vec[1] > rhs._vec[1] ) && \
					       ( _vec[2] > rhs._vec[2] );
				};
				
				inline bool operator>=( const Point3 &rhs ) const
				{
					return ( _vec[0] >= rhs._vec[0] ) && \
					       ( _vec[1] >= rhs._vec[1] ) && \
					       ( _vec[2] >= rhs._vec[2] );
				};
				
				/*
				 * Get the distance squared between two 3D points.
				 *
				 * Use this method if you want to compare two distance values as it
				 * is fast (no casting or calculating the square root).  If you need
				 * the actual distance, then please use Distance() instead.
				 *
				 * @param pt The other point to get the distance to.
				 *
				 * @return F32 The distance squared between two 3D points.
				 */
				inline F32 DistanceSqr( const Point3 &pt ) const
				{
					F32 dX = pt._vec[0] - _vec[0];
					F32 dY = pt._vec[1] - _vec[1];
					F32 dZ = pt._vec[2] - _vec[2];
					return dX * dX + dY * dY + dZ * dZ;
				};
				
				/*
				 * Get the distance between two 3D points.
				 *
				 * @param pt The other point to get the distance to.
				 *
				 * @return F32 The distance between two 3D points.
				 */
				inline F32 Distance( const Point3 &pt ) const
				{
					return static_cast<F32>( sqrt( static_cast<F32>( DistanceSqr( pt ) ) ) );
				};
				
				inline const char *ToString() const
				{
					#ifdef EMBER_MATH_TO_STRING
					std::stringstream strStream;
					strStream << "[" << _vec[0] << ", " << _vec[1] << ", " << _vec[2] << "]";
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
		
		extern const Point3 Origin;
		
		/*
		 * Performs linear interpolation on two 3 component points.
		 *
		 * @param a The start point.
		 * @param b The end point.
		 * @param value Interpolation value (should be between 0
		 *                          and 1, if not it is clamped).
		 * @param outPt Output pt.
		 *
		 * @return Point3& Output pt.
		 */
		Point3 &Point3Lerp( const Point3 &a, const Point3 &b, F32 value, Point3 &outPt );
		
		/*
		 * Given three points in 3D space, calulate the normal vector.
		 *
		 * The points must be supplied in counterclockwise order in order to
		 * calculate the normal correctly.
		 *
		 * @param ptOne The first point.
		 * @param ptTwo The second point.
		 * @param ptThree The third point.
		 * @param normalOut Object that contains details on the normal vector.
		 */
		Vector3 &CalculateNormal( const Point3 &ptOne, const Point3 &ptTwo, const Point3 &ptThree, Vector3 &normalOut );
		
		/*
		 * Given three points in 3D space, calulate the UNIT normal vector.
		 *
		 * The points must be supplied in counterclockwise order in order to
		 * calculate the normal correctly.
		 *
		 * @param ptOne The first point.
		 * @param ptTwo The second point.
		 * @param ptThree The third point.
		 * @param normalOut Object that contains details on the normal vector.
		 */
		inline Vector3 &CalculateUnitNormal( const Point3 &ptOne, const Point3 &ptTwo, const Point3 &ptThree, Vector3 &normalOut );
		
		/*
		 * Generate a Point3 with random xyz components.
		 *
		 * @param min The minimum point.
		 * @param max The maximum point.
		 * @param pt The Point3 object to hold the random componenets.
		 *
		 * @return Point3& A reference to the Point3 object with the random
		 *                  components. It refers to the same object passed
		 *                  in.
		 */
		Point3 &RandomPoint3( const Point3 &min, const Point3 &max, Point3 &pt );
	}
}
#endif
