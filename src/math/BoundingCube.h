#pragma once
#ifndef __EMBER_BOUNDING_CUBE_H
#define __EMBER_BOUNDING_CUBE_H

/*
 * @file BoundingCube.h
 * @author PJ O Halloran
 * @date 21/12/2016
 */

#include "core/EmberTypes.h"

#include "Point3.h"

namespace ember
{
	namespace math
	{
		class BoundingCube
		{
			private:
			
				Point3 _min;
				Point3 _max;
				
			public:
			
				inline explicit BoundingCube() : _min(), _max() { };
				
				inline explicit BoundingCube( const Point3 &min, const Point3 &max ) : _min( min ), _max( max ) { };
				
				~BoundingCube() { };
				
				inline Point3 GetMin() const
				{
					return _min;
				};
				
				inline void SetMin( const Point3 &min )
				{
					_min = min;
				};
				
				inline Point3 GetMax() const
				{
					return _max;
				};
				
				inline void SetMax( const Point3 &max )
				{
					_max = max;
				};
				
				inline bool IsPointInside( const Point3 &pt ) const
				{
					const F32 x = pt.X();
					const F32 y = pt.Y();
					const F32 z = pt.Z();
					return x >= _min.X() && \
					       y >= _min.Y() && \
					       z >= _min.Z() && \
					       x <= _max.X() && \
					       y <= _max.Y() && \
					       z <= _max.Z();
				};
				
				inline F32 GetWidth() const
				{
					return _max.X() - _min.X();
				};
				
				inline F32 GetHeight() const
				{
					return _max.Y() - _min.Y();
				};
				
				inline F32 GetDepth() const
				{
					return _max.Z() - _min.Z();
				};
				
				inline bool IsValid() const
				{
					return ( _min.X() <= _max.X() ) && ( _min.Y() <= _max.Y() ) && ( _min.Z() <= _max.Z() );
				};
		};
	}
}

#endif
