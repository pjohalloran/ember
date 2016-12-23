/*
 * @file ember_eastl_memory.cpp
 * @author PJ O Halloran
 * @date 23/12/2016
 *
 * File with simple allocator defines, required to link with and use EASTL.
 */

#include <cstdlib>

void *operator new[]( size_t size, const char *pName, int flags, unsigned debugFlags, const char *file, int line )
{
	return malloc( size );
}

void *operator new[]( size_t size, size_t alignment, size_t alignmentOffset, const char *pName, int flags, unsigned debugFlags, const char *file, int line )
{
	return malloc( size );
}
