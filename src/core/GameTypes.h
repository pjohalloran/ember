#pragma once
#ifndef __EMBER_GAME_TYPES_H
#define __EMBER_GAME_TYPES_H

/*
 * @file GameTypes.h
 * @author PJ O Halloran
 * @date 14/12/2016
 *
 * Header for framework types.
 */

namespace ember
{
	namespace core
	{
		typedef char I8;
		typedef unsigned char U8;
		typedef short I16;
		typedef unsigned short U16;
		typedef int I32;
		typedef unsigned int U32;
		typedef long I64;
		typedef unsigned long U64;
		typedef float F32;
		typedef double F64;
		
		// TODO - i might not need these anymore depending on what i bring over from gameframework
		
		// // Matrix3x3 array definition (a F32 array as it is used in GLSL shaders only).
		// typedef F32 Matrix3x3[9];
		//
		// 		// unsigned long is 32 bits or 64 bits depending on the target architecture...
		// 		// However, 3rd party data chunks used in framework (zlib (.zip), .wav) use 4 bytes for DWORD no matter
		// 		//  what the architeture used is...  So we will explicitly define DWORD and WORD types here!
		// #if defined(__i386__)
		// 		typedef ember::core::U64 DWORD;
		// 		typedef ember::core::U16 WORD;
		// #elif defined(__x86_64__)
		// 		typedef ember::core::U32 DWORD;
		// 		typedef ember::core::U16 WORD;
		// #endif
	}
}

#endif
