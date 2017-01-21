/*
 * @file EmberStringHash.cpp
 * @author PJ O Halloran
 * @date 15/12/2016
 */

#include <loguru.hpp>

#include "EmberStringHash.h"

#include "app/EmberApp.h"

namespace ember
{
	namespace core
	{
		StringHash Hash( const char *str )
		{
			DCHECK_NOTNULL_F( str, "Hash() invalid parameter" );
			
			#if defined(STRING_HASH_DATABASE_ON)
			
			try
			{
				return StringHash( str, *ember::app::Application->StringHashDatabase() );
			}
			catch ( StringHashCollisionError &error )
			{
				// this should be extremely rare and in builds with STRING_HASH_DATABASE_ON, i want to know about it
				LOG_F( ERROR, "StringHashCollisionError occurred (%s)", error.str() );
				throw;
			}
			
			#else
			
			return StringHash( str, *ember::app::Application->StringHashDatabase() );
			
			#endif
		}
	}
}
