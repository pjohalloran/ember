/*
 * @file EmberVariant.cpp
 * @author PJ O Halloran
 * @date 21/12/2016
 */

#include "EmberVariant.h"

#include "math/Point2.h"
#include "math/Point3.h"
#include "math/Vector3.h"
#include "math/Vector4.h"
#include "math/Matrix4.h"

#include <loguru.hpp>

namespace ember
{
	namespace core
	{
		void EmberVariant::SetPoint2( const Point2 &pt )
		{
			type = TypePoint2;
			memcpy( asPoint2, pt.GetComponentsConst(), sizeof( F32 ) * TwoComp );
		}
		
		void EmberVariant::SetPoint3( const Point3 &pt )
		{
			type = TypePoint3;
			memcpy( asPoint3, pt.GetComponentsConst(), sizeof( F32 ) * ThreeComp );
		}
		
		void EmberVariant::SetVector3( const Vector3 &vec )
		{
			type = TypeVector3;
			memcpy( asVector3, vec.GetComponentsConst(), sizeof( F32 ) * ThreeComp );
		}
		
		void EmberVariant::SetVector4( const Vector4 &vec )
		{
			type = TypeVector4;
			memcpy( asVector4, vec.GetComponentsConst(), sizeof( F32 ) * FourComp );
		}
		
		void EmberVariant::SetMatrix3( const Matrix3x3 &matrix )
		{
			DCHECK_NOTNULL_F( matrix );
			
			type = TypeMatrix3;
			memcpy( asMatrix3, matrix, sizeof( F32 ) * NineComp );
		}
		
		void EmberVariant::SetMatrix4( const Matrix4 &matrix )
		{
			type = TypeMatrix4;
			memcpy( asMatrix4, matrix.GetComponentsConst(), sizeof( F32 ) * SixteenComp );
		}
		
		void EmberVariant::SetString( const char *str )
		{
			DCHECK_NOTNULL_F( str, "invalid parameter" );
			DCHECK_LE_F( strlen( str ), MaxStringLen, "String can be mamximum of %u characters in length", MaxStringLen );
			
			type = TypeString;
			strcpy( asString, str );
		}
		
		bool EmberVariant::TryGetValue( Point2 &pt ) const
		{
			if ( type != TypePoint2 )
			{
				return false;
			}
			
			pt = Point2( asPoint2 );
			return true;
		}
		
		bool EmberVariant::TryGetValue( Point3 &pt ) const
		{
			if ( type != TypePoint3 )
			{
				return false;
			}
			
			pt = Point3( asPoint3 );
			return true;
		}
		
		bool EmberVariant::TryGetValue( Vector3 &vec ) const
		{
			if ( type != TypeVector3 )
			{
				return false;
			}
			
			vec = Vector3( asVector3 );
			return true;
		}
		
		bool EmberVariant::TryGetValue( Vector4 &vec ) const
		{
			if ( type != TypeVector4 )
			{
				return false;
			}
			
			vec = Vector4( asVector4 );
			return true;
		}
		
		bool EmberVariant::TryGetValue( Matrix3x3 &matrix ) const
		{
			DCHECK_NOTNULL_F( matrix );
			
			if ( type != TypeMatrix3 )
			{
				return false;
			}
			
			memcpy( matrix, asMatrix3, NineComp * sizeof( F32 ) );
			return true;
		}
		
		bool EmberVariant::TryGetValue( Matrix4 &matrix ) const
		{
			if ( type != TypeMatrix4 )
			{
				return false;
			}
			
			matrix = Matrix4( asMatrix4 );
			return true;
		}
		
		bool EmberVariant::TryGetValue( char *str ) const
		{
			DCHECK_NOTNULL_F( str );
			
			if ( type != TypeString )
			{
				return false;
			}
			
			strcpy( str, asString );
			
			return true;
		}
	}
}
