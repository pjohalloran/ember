#pragma once
#ifndef __EMBER_VECTOR3_H
#define __EMBER_VECTOR3_H

/*
 * @file EmberMath.h
 * @author PJ O Halloran
 * @date 20/12/2016
 *
 * Single header to include all the ember::math files and to configure
 * debug info.
 */

//
// Config options for ember::math
//

//
// Include if you want to have ToString() method on all Math utils for debugging return iseful info.
// (Otherwise it returns an empty string)
// Will include std::string and string streams.
//
#define EMBER_MATH_TO_STRING 1

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

#include "math/EmberMathUtils.h"
#include "math/Vector3.h"
#include "math/Vector4.h"
#include "math/Point3.h"
//#include "math/Point2.h"
//#include "math/Matrix.h"
//#include "math/Quaternion.h"
//#include "math/Raycast.h"

#endif