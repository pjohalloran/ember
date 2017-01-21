#pragma once
#ifndef __EMBER_VARIANT_H
#define __EMBER_VARIANT_H

/*
 * @file EventVariant.h
 * @author PJ O Halloran
 * @date 21/01/2017
 */

#include "core/Ember.h"

namespace ember
{
	namespace core
	{
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
			
			inline void SetBool( bool value )
			{
				type = TypeBool;
				asBool = value;
			};
			
			inline bool TryGetValue( bool &value )
			{
				if ( type != TypeBool )
				{
					return false;
				}
				
				value = asBool;
				return true;
			};
			
			inline void SetI32( I32 value )
			{
				type = TypeI32;
				asI32 = value;
			};
		};
	}
}

#endif
