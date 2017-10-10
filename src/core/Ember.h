#pragma once
#ifndef __EMBER_H
#define __EMBER_H

/*
 * @file Ember.h
 * @author PJ O Halloran
 * @date 15/12/2016
 *
 * Header for Ember Core defines.
 */

#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <new>
#include <memory>

#include <loguru/loguru.hpp>

#include "EmberTypes.h"
#include "EmberPlatform.h"
#include "EmberStringHash.h"
#include "EmberVariant.h"

// TODO include these ?
// #include <boost/shared_ptr.hpp>

namespace ember
{
	namespace core
	{
		template<class T>
		void Delete( T *ptr ) throw()
		{
			if ( ptr )
			{
				delete ptr;
				ptr = NULL;
			}
		};
		
		template<class T>
		void DeleteArray( T *arr ) throw()
		{
			if ( arr )
			{
				delete [] arr;
				arr = NULL;
			}
		};
		
		// template<class T>
		// class SortBy_SharedPtr_Content {
		// public:
		//     bool operator()(const boost::shared_ptr<T> &lhs, const boost::shared_ptr<T> &rhs) const {
		//         return (*lhs < *rhs);
		//     };
		// };
		
		class NonCopyable
		{
			protected:
				NonCopyable() {};
				~NonCopyable() {};
			private:
				NonCopyable( const NonCopyable & );
				const NonCopyable &operator=( const NonCopyable & );
		};
		
		std::string GetOpenGLError( const GLenum errorCode );
		
		// Define OpenGL check and clear error macros so that this slow error checking can be compiled out for the release build!
		bool GfCheckGlError();
		bool GfCheckGlErrorTrc( const char *msg );
#define GF_CHECK_GL_ERROR() GfCheckGlError()
#define GF_CHECK_GL_ERROR_TRC(msg) GfCheckGlErrorTrc(msg)
		
#if DEBUG
	#define GF_CLEAR_GL_ERROR() { GLenum err; do { err = glGetError(); } while(err != GL_NO_ERROR); }
#else
	#define GF_CLEAR_GL_ERROR()
#endif
	}
}

#endif
