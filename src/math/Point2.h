#pragma once
#ifndef __EMBER_POINT2_H
#define __EMBER_POINT2_H

/*
 * @file Point2.h
 * @author PJ O Halloran
 * @date 22/12/2016
 *
 * 2D Point.
 */

#include "EmberMathDefines.h"
#include "EmberMathUtils.h"

namespace ember
{
	namespace math
	{
		using namespace ember::core;
		
		class Point2
		{
			private:
			
				static const U32 Size = 2;
				
				F32 _vec[Size];
				
			public:
			
				explicit inline Point2()
				{
					memset( _vec, 0, sizeof( F32 ) * Size );
				};
				
				explicit inline Point2( const F32 x, const F32 y )
				{
					_vec[0] = x;
					_vec[1] = y;
				};
				
				explicit inline Point2( const F32 scaler )
				{
					_vec[0] = scaler;
					_vec[1] = scaler;
				};
				
				explicit inline Point2( const F32 ptArr[Size] )
				{
					memcpy( _vec, ptArr, sizeof( F32 ) * Size );
				};
				
				inline Point2( const Point2 &copyPt )
				{
					memcpy( _vec, copyPt._vec, sizeof( F32 ) * Size );
				};
				
				~Point2() { };
				
				inline F32 X() const
				{
					return _vec[0];
				};
				
				inline F32 Y() const
				{
					return _vec[1];
				};
				
				inline void SetX( const F32 x )
				{
					_vec[0] = x;
				};
				
				inline void SetY( const F32 y )
				{
					_vec[1] = y;
				};
				
				inline void Set( const F32 x, const F32 y )
				{
					_vec[0] = x;
					_vec[1] = y;
				};
				
				inline Point2 &operator=( const Point2 &rhs )
				{
					if ( this == &rhs )
					{
						return *this;
					}
					
					_vec[0] = rhs._vec[0];
					_vec[1] = rhs._vec[1];
					return *this;
				};
				
				inline bool operator==( const Point2 &rhs ) const
				{
					if ( this == &rhs )
					{
						return true;
					}
					
					return Compare( _vec[0], rhs._vec[0] ) && \
					       Compare( _vec[1], rhs._vec[1] );
				};
				
				inline bool operator!=( const Point2 &rhs ) const
				{
					return !( *this == rhs );
				};
				
				inline Point2 operator-() const
				{
					return Point2( -_vec[0], -_vec[1] );
				};
				
				inline bool operator<( const Point2 &rhs ) const
				{
					return ( _vec[0] < rhs._vec[0] ) && \
					       ( _vec[1] < rhs._vec[1] );
				};
				
				inline bool operator<=( const Point2 &rhs ) const
				{
					return ( _vec[0] <= rhs._vec[0] ) && \
					       ( _vec[1] <= rhs._vec[1] );
				};
				
				inline bool operator>( const Point2 &rhs ) const
				{
					return ( _vec[0] > rhs._vec[0] ) && \
					       ( _vec[1] > rhs._vec[1] );
				};
				
				inline bool operator>=( const Point2 &rhs ) const
				{
					return ( _vec[0] >= rhs._vec[0] ) && \
					       ( _vec[1] >= rhs._vec[1] );
				};
				
				/*
				 * Get the distance squared between two 2D points.
				 *
				 * Use this method if you want to compare two distance values as it
				 * is fast (no casting or calculating the square root).  If you need
				 * the actual distance, then please use Distance() instead.
				 *
				 * @param pt The other point to get the distance to.
				 *
				 * @return F32 The distance squared between two 3D points.
				 */
				inline F32 DistanceSqr( const Point2 &pt ) const
				{
					F32 dX = pt._vec[0] - _vec[0];
					F32 dY = pt._vec[1] - _vec[1];
					return dX * dX + dY * dY;
				};
				
				/*
				 * Get the distance between two 3D points.
				 *
				 * @param pt The other point to get the distance to.
				 *
				 * @return F32 The distance between two 3D points.
				 */
				inline F32 Distance( const Point2 &pt ) const
				{
					return static_cast<F32>( sqrt( static_cast<F32>( DistanceSqr( pt ) ) ) );
				};
				
				inline const char *ToString() const
				{
					#ifdef EMBER_MATH_TO_STRING
					std::stringstream strStream;
					strStream << "[" << _vec[0] << ", " << _vec[1] << "]";
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
		
		extern const Point2 Origin2;
		
		/*
		 * Performs linear interpolation on two 2 component points.
		 *
		 * @param a The start point.
		 * @param b The end point.
		 * @param value Interpolation value (should be between 0
		 *                          and 1, if not it is clamped).
		 * @param outPt Output pt.
		 *
		 * @return Point2& Output pt.
		 */
		Point2 &Point2Lerp( const Point2 &a, const Point2 &b, F32 value, Point2 &outPt );
		
		/*
		 * Generate a Point2 with random xy components.
		 *
		 * @param min The minimum point.
		 * @param max The maximum point.
		 * @param pt The Point2 object to hold the random componenets.
		 *
		 * @return Point2& A reference to the Point2 object with the random
		 *                  components. It refers to the same object passed
		 *                  in.
		 */
		Point2 &RandomPoint2( const Point2 &min, const Point2 &max, Point2 &pt );
	}
}
#endif
