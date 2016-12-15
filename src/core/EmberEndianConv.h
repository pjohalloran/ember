#pragma once
#ifndef __EMBER_ENDIAN_CONV_H
#define __EMBER_ENDIAN_CONV_H

/*
 * @file EmberEndianConv.h
 * @author PJ O Halloran
 * @date 14/12/2016
 *
 * Utility functions for endianness conversion.
 */

#include "EmberTypes.h"

namespace ember
{
	namespace core
	{
		union U32F32
		{
			U32 m_asU32;
			F32 m_asF32;
		};
		
		union U64F64
		{
			U64 m_asU64;
			F64 m_asF64;
		};
		
		inline I16 SwapI16( const I16 value )
		{
			return ( ( value & 0x00FF << 8 ) |
			         ( value & 0xFF00 >> 8 ) );
		};
		
		inline U16 SwapU16( const U16 value )
		{
			return ( ( value & 0x00FF << 8 ) |
			         ( value & 0xFF00 >> 8 ) );
		};
		
		inline I32 SwapI32( const I32 value )
		{
			return ( ( value & 0x000000FF << 8 ) |
			         ( value & 0x0000FF00 << 8 ) |
			         ( value & 0x00FF0000 >> 8 ) |
			         ( value & 0xFF000000 >> 8 ) );
		};
		
		inline U32 SwapU32( const U32 value )
		{
			return ( ( value & 0x000000FF << 8 ) |
			         ( value & 0x0000FF00 << 8 ) |
			         ( value & 0x00FF0000 >> 8 ) |
			         ( value & 0xFF000000 >> 8 ) );
		};
		
		inline U64 SwapU64( const U64 value )
		{
			return ( ( value & 0x00000000000000FF << 8 ) |
			         ( value & 0x000000000000FF00 << 8 ) |
			         ( value & 0x0000000000FF0000 << 8 ) |
			         ( value & 0x00000000FF000000 << 8 ) |
			         ( value & 0x000000FF00000000 >> 8 ) |
			         ( value & 0x0000FF0000000000 >> 8 ) |
			         ( value & 0x00FF000000000000 >> 8 ) |
			         ( value & 0xFF00000000000000 >> 8 ) );
		};
		
		inline I64 SwapI64( const I64 value )
		{
			return ( ( value & 0x00000000000000FF << 8 ) |
			         ( value & 0x000000000000FF00 << 8 ) |
			         ( value & 0x0000000000FF0000 << 8 ) |
			         ( value & 0x00000000FF000000 << 8 ) |
			         ( value & 0x000000FF00000000 >> 8 ) |
			         ( value & 0x0000FF0000000000 >> 8 ) |
			         ( value & 0x00FF000000000000 >> 8 ) |
			         ( value & 0xFF00000000000000 >> 8 ) );
		};
		
		inline F32 SwapF32( const F32 value )
		{
			U32F32 u;
			u.m_asF32 = value;
			u.m_asU32 = SwapU32( u.m_asU32 );
			return ( u.m_asF32 );
		};
		
		inline F64 SwapF64( F64 value )
		{
			U64F64 u;
			u.m_asF64 = value;
			u.m_asU64 = SwapU64( u.m_asU64 );
			return ( u.m_asF64 );
		};
	}
}

#endif
