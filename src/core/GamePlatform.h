#pragma once
#ifndef __EMBER_PLATFORM_H
#define __EMBER_PLATFORM_H

/*
 * @file GamePlatform.h
 * @author PJ O Halloran
 * @date 14/12/2016
 *
 * Where platform specific types headers are defined and/or included.
 */

#include <cstdlib>
#include <cstdio>

#include "GameTypes.h"

#if _WINDOWS
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <direct.h>
#include <crtdbg.h>

// TODO Am i using GLEW?
//#include <GL/glew.h>

#include <GL/glfw3.h>
#define GLFW_FUNC_PRE GLFWAPI

#define STRCPY char *strcpy_s(char *, size_t, const char *);

// TODO using custom new?
// #define GCC_NEW new(_NORMAL_BLOCK,__FILE__, __LINE__)

#else
// Defining handy mmioFOURCC macro for non WIN32 platforms...
#ifndef mmioFOURCC
#define mmioFOURCC( ch0, ch1, ch2, ch3 )                \
	( (ember::core::I64)(ember::core::U8)(ch0) | ( (ember::core::I64)(ember::core::U8)(ch1) << 8 ) |    \
	  ( (ember::core::I64)(ember::core::U8)(ch2) << 16 ) | ( (ember::core::I64)(ember::core::U8)(ch3) << 24 ) )
#endif

#define STRCPY char *strcpy(char *, const char *);

// TODO using custom new?
//#define GCC_NEW new

#if TARGET_OS_MAC
	
	#ifdef __APPLE__
		#include <TargetConditionals.h>
		//#include <GL/glew.h>
		#include <OpenGL/gl.h>
		#include <OpenGL/glext.h>
		#include <GLFW/glfw3.h>
		#define GLFW_FUNC_PRE GLFWAPI
	#endif
	
	#include <assert.h>
	
#elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
	
	#ifdef __APPLE__
		#include <TargetConditionals.h>
		#include <OpenGLES/ES2/gl.h>
		#include <OpenGLES/ES2/glext.h>
	#endif
	
#elif TARGET_OS_UNIX
	// TODO: ...
#else
	#error "Platform not yet supported!"
#endif
#endif

#endif
