/*
 * @file Ember.cpp
 * @author PJ O Halloran
 * @date 15/12/2016
 */

#include "Ember.h"

namespace ember
{
	namespace core
	{
		std::string GetOpenGLError( const GLenum errorCode )
		{
			std::string str;
			
			switch ( errorCode )
			{
				case GL_INVALID_ENUM:
					{
						str.assign( "GL_INVALID_ENUM: unacceptable value for a enumerated argument" );
					}
					break;
					
				case GL_INVALID_VALUE:
					{
						str.assign( "GL_INVALID_VALUE: numeric argument out of range" );
					}
					break;
					
				case GL_INVALID_OPERATION:
					{
						str.assign( "GL_INVALID_OPERATION: operation is not allowed in the current state" );
					}
					break;
					
				case GL_INVALID_FRAMEBUFFER_OPERATION:
					{
						str.assign( "GL_INVALID_FRAMEBUFFER_OPERATION: framebuffer object is not complete" );
					}
					break;
					
				case GL_OUT_OF_MEMORY:
					{
						str.assign( "GL_OUT_OF_MEMORY: not enough memory left to execute the command" );
					}
					break;
					
				case GL_NO_ERROR:
					{
						str.assign( "No OpenGL error occurred" );
					}
					break;
					
				default:
					{
						str.assign( "Unknown OpenGL error occurred" );
					}
					break;
			}
			
			return str;
		}
		
		bool GfCheckGlError()
		{
			#if DEBUG
			GLenum err = glGetError();
			
			LOG_IF_F( ERROR, err != GL_NO_ERROR, GetOpenGLError( err ).c_str() );
			
			return err == GL_NO_ERROR;
			#else
			return true;
			#endif
		}
		
		bool GfCheckGlErrorTrc( const char *msg )
		{
			#if DEBUG
			GLenum err = glGetError();
			
			LOG_IF_F( ERROR, err != GL_NO_ERROR, ( msg + GetOpenGLError( err ) ).c_str() );
			
			return err == GL_NO_ERROR;
			#else
			return true;
			#endif
		}
	}
}
