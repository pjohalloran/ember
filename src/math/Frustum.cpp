/*
 * @file Frustrum.cpp
 * @author PJ O Halloran
 * @date 22/12/2016
 */

#include "Frustum.h"

namespace ember
{
	namespace math
	{
	
		Frustrum::Frustrum() : _fov( PI / 4.0f ), _aspect( 1.0f ), _near( 1.0f ), _far( 1000.0f )
		{
		}
		
		bool Frustrum::Inside( const Point3 &pt ) const
		{
			for ( I32 i = 0; i < NumPlanes; ++i )
			{
				if ( !_planes[i].Inside( pt ) )
				{
					return false;
				}
			}
			
			return true;
		}
		
		bool Frustrum::Inside( const BoundingSphere &bs ) const
		{
			for ( I32 i = 0; i < NumPlanes; ++i )
			{
				if ( _planes[i].Inside( bs ) )
				{
					return false;
				}
			}
			
			return true;
		}
		
		void Frustrum::Init( const F32 fov, const F32 aspect, const F32 nearClip, const F32 farClip )
		{
			_fov = F32( DegreesToRadians( fov ) );
			_aspect = aspect;
			_near = nearClip;
			_far = farClip;
			
			F32 tanFovOver2 = F32( tan( _fov / 2.0f ) );
			F32 nearFov2 = _near * tanFovOver2;
			F32 farFov2 = _far * tanFovOver2;
			
			// Calculate the near & far right and near & far up vertices of the Frustrum.
			Vector3 nearRight = nearFov2 * _aspect * RightDir;
			Vector3 farRight = farFov2 * _aspect * RightDir;
			Vector3 nearUp = nearFov2 * UpDir;
			Vector3 farUp = farFov2 * UpDir;
			
			// points start in the upper right and go around clockwise
			_nearClipPoints[0] = ( _near * ForwardDir ) - nearRight + nearUp;
			_nearClipPoints[1] = ( _near * ForwardDir ) + nearRight + nearUp;
			_nearClipPoints[2] = ( _near * ForwardDir ) + nearRight - nearUp;
			_nearClipPoints[3] = ( _near * ForwardDir ) - nearRight - nearUp;
			
			_farClipPoints[0] = ( _far * ForwardDir ) - farRight + farUp;
			_farClipPoints[1] = ( _far * ForwardDir ) + farRight + farUp;
			_farClipPoints[2] = ( _far * ForwardDir ) + farRight - farUp;
			_farClipPoints[3] = ( _far * ForwardDir ) - farRight - farUp;
			
			_planes[Near] = Plane( _nearClipPoints[2], _nearClipPoints[1], _nearClipPoints[0] );
			_planes[Far] = Plane( _farClipPoints[0], _farClipPoints[1], _farClipPoints[2] );
			_planes[Right] = Plane( _farClipPoints[2], _farClipPoints[1], Origin );
			_planes[Top] = Plane( _farClipPoints[1], _farClipPoints[0], Origin );
			_planes[Left] = Plane( _farClipPoints[0], _farClipPoints[3], Origin );
			_planes[Bottom] = Plane( _farClipPoints[3], _farClipPoints[2], Origin );
		}
	}
}
