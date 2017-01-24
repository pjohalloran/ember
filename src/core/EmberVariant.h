#pragma once
#ifndef __EMBER_VARIANT_H
#define __EMBER_VARIANT_H

/*
 * @file EventVariant.h
 * @author PJ O Halloran
 * @date 21/01/2017
 *
 * Variant type that can hold any POD or ember engine core type.
 */

#include <cstring>

#include "core/Ember.h"

namespace ember
{
	namespace math
	{
		class Point2;
		class Point3;
		class Vector3;
		class Vector4;
		class Matrix4;
	}
	
	namespace core
	{
		using namespace ember::math;
		
		struct EmberVariant
		{
			static constexpr U32 MaxStringLen = 255;
			static constexpr U32 TwoComp = 2;
			static constexpr U32 ThreeComp = 3;
			static constexpr U32 FourComp = 4;
			static constexpr U32 NineComp = 9;
			static constexpr U32 SixteenComp = 16;
			
			enum Type
			{
				TypeUndefined,
				TypeBool,
				TypeI32,
				TypeU32,
				TypeI64,
				TypeU64,
				TypeF32,
				TypeF64,
				TypePoint2,
				TypePoint3,
				TypeVector3,
				TypeVector4,
				TypeMatrix3,
				TypeMatrix4,
				TypeString,
				TypeCount
			};
			
			union
			{
				bool asBool;
				I32 asI32;
				U32 asU32;
				I64 asI64;
				U64 asU64;
				F32 asF32;
				F64 asF64;
				F32 asPoint2[TwoComp];
				F32 asPoint3[ThreeComp];
				F32 asVector3[ThreeComp];
				F32 asVector4[FourComp];
				F32 asMatrix3[NineComp];
				F32 asMatrix4[SixteenComp];
				char asString[MaxStringLen];
			};
			
			Type type;
			U64 handle;
			
			EmberVariant()
			{
				Clear();
			}
			
			inline EmberVariant &operator=( const EmberVariant &rhs )
			{
				if ( this == &rhs )
				{
					return *this;
				}
				
				memcpy( this, ( void * )&rhs, sizeof( EmberVariant ) );
				
				return *this;
			};
			
			inline void Clear()
			{
				type = TypeUndefined;
				memset( this, 0, sizeof( EmberVariant ) );
			}
			
			inline bool IsValid() const
			{
				return type != TypeUndefined;
			}
			
			inline void SetBool( bool value )
			{
				type = TypeBool;
				asBool = value;
			};
			
			inline void SetI32( I32 value )
			{
				type = TypeI32;
				asI32 = value;
			};
			
			inline void SetU32( U32 value )
			{
				type = TypeU32;
				asU32 = value;
			};
			
			inline void SetI64( I64 value )
			{
				type = TypeI64;
				asI64 = value;
			};
			
			inline void SetU64( U64 value )
			{
				type = TypeU64;
				asU64 = value;
			};
			
			inline void SetF32( F32 value )
			{
				type = TypeF32;
				asF32 = value;
			};
			
			inline void SetF64( F64 value )
			{
				type = TypeF64;
				asF64 = value;
			};
			
			void SetPoint2( const Point2 &pt );
			
			void SetPoint3( const Point3 &pt );
			
			void SetVector3( const Vector3 &vec );
			
			void SetVector4( const Vector4 &vec );
			
			void SetMatrix3( const Matrix3x3 &matrix );
			
			void SetMatrix4( const Matrix4 &matrix );
			
			void SetString( const char *str );
			
			inline bool TryGetValue( bool &value ) const
			{
				if ( type != TypeBool )
				{
					return false;
				}
				
				value = asBool;
				return true;
			};
			
			inline bool TryGetValue( I32 &value ) const
			{
				if ( type != TypeI32 )
				{
					return false;
				}
				
				value = asI32;
				return true;
			};
			
			inline bool TryGetValue( U32 &value ) const
			{
				if ( type != TypeU32 )
				{
					return false;
				}
				
				value = asU32;
				return true;
			};
			
			inline bool TryGetValue( I64 &value ) const
			{
				if ( type != TypeI64 )
				{
					return false;
				}
				
				value = asI64;
				return true;
			};
			
			inline bool TryGetValue( U64 &value ) const
			{
				if ( type != TypeU64 )
				{
					return false;
				}
				
				value = asU64;
				return true;
			};
			
			inline bool TryGetValue( F32 &value ) const
			{
				if ( type != TypeF32 )
				{
					return false;
				}
				
				value = asF32;
				return true;
			};
			
			inline bool TryGetValue( F64 &value ) const
			{
				if ( type != TypeF64 )
				{
					return false;
				}
				
				value = asF64;
				return true;
			};
			
			bool TryGetValue( Point2 &pt ) const;
			
			bool TryGetValue( Point3 &pt ) const;
			
			bool TryGetValue( Vector3 &vec ) const;
			
			bool TryGetValue( Vector4 &vec ) const;
			
			bool TryGetValue( Matrix3x3 &matrix ) const;
			
			bool TryGetValue( Matrix4 &matrix ) const;
			
			bool TryGetValue( char *str ) const;
		};
	}
}

#endif
