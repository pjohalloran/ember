#pragma once
#ifndef __EMBER_EVENT_DATA_H
#define __EMBER_EVENT_DATA_H

/*
 * @file EventData.h
 * @author PJ O Halloran
 * @date 4/01/2017
 */

#include "core/Ember.h"

//#include "math/Point3.h"

namespace ember
{
	namespace events
	{
		using namespace ember::core;
		//using namespace ember::math;
		
		struct Variant
		{
			enum Type
			{
				TypeBool,
				TypeI32,
				TypeU32,
				TypeI64,
				TypeU64,
				TypeF32,
				TypeF64,
				//TypePoint3,
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
				//Point3 asPoint3;
			};
			
			Type type;
		};
		
		struct Event
		{
			const U32 MaxArgs = 8;
			
			//foonathan::string_id Id;
			U32 ArgCount;
			//string_id Keys[MaxArgs];
			//Variant Data[MaxArgs];
			
			Event *Clone()
			{
				// return deep copy of me
				return nullptr;
			};
		};
	}
}

#endif
