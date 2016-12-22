#pragma once
#ifndef __EMBER_FRUSTUM_H
#define __EMBER_FRUSTUM_H

/*
 * @file Frustrum.h
 * @author PJ O Halloran
 * @date 26/08/2010
*/

#include "Plane.h"

namespace ember
{
	namespace math
	{
	
		class Frustrum
		{
		
			public:
			
				enum Side
				{
					Near,
					Far,
					Top,
					Right,
					Bottom,
					Left,
					NumPlanes
				};
				
			private:
			
				Plane _planes[NumPlanes];
				Point3 _nearClipPoints[4];
				Point3 _farClipPoints[4];
				F32 _fov;
				F32 _aspect;
				F32 _near;
				F32 _far;
				
			public:
			
				explicit Frustrum();
				~Frustrum() { };
				
				/*
				 * Check if a 3D point is inside the Frustrum.
				 * The 3D point should be transformed to eye/camera space first.
				 */
				bool Inside( const Point3 &pt ) const;
				
				/*
				 * Check if a BoundingSphere is inside the Frustrum.
				 * The position of the sphere should be transformed to eye/camera
				 * space first.
				 */
				bool Inside( const BoundingSphere &bs ) const;
				
				inline const Plane &Get( const Side side )
				{
					return _planes[side];
				};
				
				inline void SetFOV( const F32 fov )
				{
					Init( fov, _aspect, _near, _far );
				};
				
				inline void SetAspect( const F32 aspect )
				{
					Init( _fov, aspect, _near, _far );
				}
				
				inline void SetNear( const F32 nearClip )
				{
					Init( _fov, _aspect, nearClip, _far );
				}
				
				inline void SetFar( const F32 farClip )
				{
					Init( _fov, _aspect, _near, farClip );
				}
				
				void Init( const F32 fov, const F32 aspect, const F32 near, const F32 far );
		};
	}
}

#endif
