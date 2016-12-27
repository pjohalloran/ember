#pragma once
#ifndef __EMBER_MATH_DEFINES_H
#define __EMBER_MATH_DEFINES_H

/*
 * @file EmberMathDefines.h
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * Single header to configure debug info.
 */

//
// Config options for ember::math
//

//
// Include if you want to have ToString() method on all Math utils for debugging.
// (Otherwise it returns an empty string)
// Will also include std::string and std::streams.
//
#define EMBER_MATH_TO_STRING

//
// Use Cramer implementation of calculating the inverse of a Matrix.
// If its off (default) laplaces expansion method is instead used.
//
// Cramer method taken from a 1999 paper released by Intel
// titled "Streaming SIMD Extensions - Inverse of a 4*4 matrix".
//
// Laplace expansion taken from OpenGL Superbible 5th Edition.
//
//#define EMBER_MATRIX_USE_CRAMER_INVERSE

//
// Defines
//

// For common std math utils
#include <cmath>

// For memset, memcpy
#include <cstring>

// For info in 'ToString()'
#ifdef EMBER_MATH_TO_STRING
	#include <string>
	#include <ostream>
	#include <sstream>
#endif

#include "core/EmberTypes.h"

#endif
