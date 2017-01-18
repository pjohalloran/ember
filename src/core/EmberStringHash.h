#pragma once
#ifndef __EMBER_STRING_HASH_H
#define __EMBER_STRING_HASH_H

// These defines tell string_id to actually store strings in an in memory db and do checks for collisions at runtime.
#if defined(STRING_HASH_DATABASE_ON)
	#define FOONATHAN_STRING_ID_DATABASE
	#define FOONATHAN_STRING_ID_MULTITHREADED
#endif

#include <string_id.hpp>
#include <database.hpp>
#include <error.hpp>
#include <generator.hpp>

#include "EmberTypes.h"

namespace ember
{
	namespace core
	{
		typedef foonathan::string_id::default_database StringHashDatabase;
		typedef foonathan::string_id::string_id StringHash;
		typedef foonathan::string_id::collision_error StringHashCollisionError;
		
		StringHash Hash( const char *str );
	}
}

#endif
