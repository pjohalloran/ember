/*
 * @file Plane.cpp
 * @author PJ O Halloran
 * @date 20/11/2010
 */

#include "Plane.h"

#include "Matrix4.h"

namespace ember
{
	namespace math
	{
	
		Plane::Plane( const Vector3 &normal, const Point3 &point ) : _normal( normal ), _d( 0.0f )
		{
			_normal.Normalize();
			RecalculateD( point );
		}
		
		Plane::Plane( const Point3 &pt0, const Point3 &pt1, const Point3 &pt2 ) : _normal(), _d( 0.0f )
		{
			Vector3 u, v;
			u = pt1 - pt0;
			v = pt2 - pt0;
			
			u.Cross( v, _normal );
			_normal.Normalize();
			RecalculateD( pt0 );
		}
		
		Plane &Plane::Normalize()
		{
			F32 magNormal = _normal.Magnitude();
			_normal /= magNormal;
			_d /= magNormal;
			return *this;
		}
		
		F32 Plane::Distance( const Point3 &pt ) const
		{
			return _normal.Dot( Vector3( pt ) ) + _d;
		}
		
		Plane &Plane::Transform( const Matrix4 &transformMatrix )
		{
			Plane tmp;
			Transformed( transformMatrix, tmp );
			*this = tmp;
			return *this;
		}
		
		void Plane::Transformed( const Matrix4 &transformMatrix, Plane &outPlane ) const
		{
			// We need to calculate the inverse, transpose of the transformation matrix to transform the plane!
			Matrix4 tmpMat;
			transformMatrix.Inversed( tmpMat );
			tmpMat.Transpose();
			
			// Create a 4 componenet vector from this plane storing the normal in XYZ and the D component in W.
			Vector4 planeVec4( _normal.X(), _normal.Y(), _normal.Z(), _d );
			
			// Transform the plane.
			Vector4 tPlaneVec4 = transformMatrix * planeVec4;
			
			// Store the result in the output Plane object.
			outPlane._normal.Set( tPlaneVec4.X(), tPlaneVec4.Y(), tPlaneVec4.Z() );
			outPlane._d = tPlaneVec4.W();
		}
		
		void Plane::GetNearestPoint( const Point3 &pt, Point3 &nearestPlanePt ) const
		{
			F32 k = Distance( pt );
			Vector3 ptToPlaneVec = _normal * -k;
			nearestPlanePt = pt + ptToPlaneVec;
		}
	}
	
}
