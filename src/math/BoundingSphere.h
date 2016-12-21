#pragma once
#ifndef __EMBER_BOUNDING_SPHERE_H
#define __EMBER_BOUNDING_SPHERE_H

/*
 * @file BoundingSphere.h
 * @author PJ O Halloran
 * @date 21/12/2016
 */

#include "core/EmberTypes.h"

#include "Point3.h"

namespace ember
{
	namespace math
	{
		class BoundingSphere
		{
			private:
			
				Point3 _centrePt;
				F32 _radius;
				
			public:
			
				inline explicit BoundingSphere() : _centrePt(), _radius( 0.0f ) { };
				
				inline explicit BoundingSphere( const Point3 &centrePt, const F32 radius ) : _centrePt( centrePt ), _radius( radius ) { };
				
				~BoundingSphere() { };
				
				inline Point3 GetCentre() const
				{
					return _centrePt;
				};
				
				inline void SetCentre( const Point3 &centrePt )
				{
					_centrePt = centrePt;
				};
				
				inline F32 GetRadius() const
				{
					return _radius;
				};
				
				inline void SetRadius( const F32 radius )
				{
					_radius = radius;
				};
				
				inline bool IsPointInside( const Point3 &pos ) const
				{
					const F32 dis = _centrePt.Distance( pos );
					return dis <= _radius;
				};
				
				inline bool IsValid() const
				{
					return _radius > 0.0f;
				};
				
		};
	}
}

#endif
