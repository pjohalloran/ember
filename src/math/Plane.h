#pragma once
#ifndef __EMBER_PLANE_H
#define __EMBER_PLANE_H

/*
 * @file Plane.h
 * @author PJ O Halloran
 * @date 21/12/2016
 */

#include "EmberMathDefines.h"
#include "EmberMathUtils.h"
#include "Point3.h"
#include "Vector3.h"
#include "BoundingSphere.h"

namespace ember
{
	namespace math
	{
		class Matrix4;
		
		class Plane
		{
			private:
			
				Vector3 _normal;
				F32 _d;
				
				inline void RecalculateD( const Point3 &point )
				{
					Vector3 negNormal( -_normal );
					_d = negNormal.Dot( Vector3( point ) );
				};
				
			public:
			
				Plane() {};
				
				explicit Plane( const Vector3 &normal, const Point3 &point );
				
				/*
				 * Given three points in 3D space, calculates the 3D plane they all
				 * lie upon.
				 *
				 * The points should be given in clockwise order or else the unit normal
				 * of the plane will be facing in the opposite direction to what you
				 * expect.
				 */
				explicit Plane( const Point3 &pt0, const Point3 &pt1, const Point3 &pt2 );
				
				~Plane() { };
				
				/*
				 * Get the d component of the Plane:
				 * d = -n * Pt0 (where n is the normal of the plane a Pt0 is a point
				 *                  on the plane.)
				 */
				inline F32 GetD() const
				{
					return _d;
				};
				
				inline Vector3 GetUnitNormal() const
				{
					return _normal;
				};
				
				inline Plane &operator=( const Plane &rhs )
				{
					if ( this == &rhs )
					{
						return *this;
					}
					
					_normal = rhs._normal;
					_d = rhs._d;
					return *this;
				};
				
				inline bool operator==( const Plane &rhs ) const
				{
					return _normal == rhs._normal && Compare( _d, rhs._d );
				};
				
				inline bool operator!=( const Plane &rhs ) const
				{
					return !( *this == rhs );
				};
				
				Plane &Normalize();
				
				/*
				 * Calculate the distance from a point in 3D space to this plane.
				 *
				 * The sign of the result indicates what side of the plane the point
				 * is on.  + means it is on the same side as the planes normal.
				 * - means that it lies on the opposite side as the planes normal.
				 * 0 means that it lies on the plane.
				 */
				F32 Distance( const Point3 &pt ) const;
				
				/*
				 * Check if a point lies on or inside the plane.  The same side as
				 * the planes normal.
				 */
				inline bool Inside( const Point3 &pt ) const
				{
					return Distance( pt ) >= 0.0f;
				};
				
				inline bool Inside( const BoundingSphere &sphere ) const
				{
					return ( Distance( sphere.GetCentre() ) - sphere.GetRadius() >= 0.0f );
				};
				
				Plane &Transform( const Matrix4 &transformMatrix );
				
				void Transformed( const Matrix4 &transformMatrix, Plane &outPlane ) const;
				
				/*
				 * Get the nearest point on the plane to a point in 3D space.
				 *
				 * @param pt The point in 3D space which we wish to determine the
				 *              nearest point that lies on the plane to.
				 * @param nearestPlanePt Point object which will hold the nearest point
				 *                          on the plane to "pt".
				 */
				void GetNearestPoint( const Point3 &pt, Point3 &nearestPlanePt ) const;
				
				inline const char *ToString() const
				{
					#ifdef EMBER_MATH_TO_STRING
					std::stringstream strStream;
					strStream << "[ Normal = " << _normal.ToString() << ", D = " << _d << " ]";
					return strStream.str().c_str();
					#else
					return "";
					#endif
				};
				
		};
	}
}

#endif
