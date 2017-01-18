#pragma once
#ifndef __EMBER_EVENT_DATA_H
#define __EMBER_EVENT_DATA_H

/*
 * @file EventData.h
 * @author PJ O Halloran
 * @date 4/01/2017
 */

#include "core/Ember.h"

#include "math/Point3.h"

namespace ember
{
	namespace events
	{
		using namespace ember::core;
		using namespace ember::math;
		
		struct Variant
		{
			static constexpr U32 MaxStringLen = 255;
			
			enum Type
			{
				TypeBool,
				TypeI32,
				TypeU32,
				TypeI64,
				TypeU64,
				TypeF32,
				TypeF64,
				TypeVector2,
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
				I32 asInt;
				U32 asUnsignedInt;
				I64 asLong;
				U64 asUnsignedLong;
				F32 asFloat;
				F64 asDouble;
				F32 asVectorTwo[2];
				F32 asVectorThree[3];
				F32 asVectorFour[4];
				F32 asMatrixThree[9];
				F32 asMatrixNine[16];
				const char *asString[MaxStringLen];
			};
			
			Type type;
		};
		
		struct Event
		{
			static constexpr U32 MaxArgs = 8;
			
			StringHash Id;
			U32 ArgCount;
			U64 Keys[MaxArgs];
			Variant Data[MaxArgs];
			
			Event( StringHash id, U32 argCount ) : Id( id )
			{
				DCHECK_LE_F( argCount, MaxArgs, "An event can only have maximum %i args", MaxArgs );
				
				ArgCount = argCount;
				memset( Keys, 0, sizeof( U64 ) * ArgCount );
				memset( Data, 0, sizeof( Variant ) * ArgCount );
			}
			
			Event *Clone()
			{
				// return deep copy of event
				return nullptr;
			};
		};
	}
}

#endif
