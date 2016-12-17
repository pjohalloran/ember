/*
 * @file WindowSystem.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include "WindowSystem.h"

namespace ember
{
	namespace app
	{
		void glfw_error_callback( int error, const char *errorMsg )
		{
			LOG_F( ERROR, "GLFW error code = %i, message = %s", error, errorMsg );
		}
		
		using namespace ember::core;
		
		bool WindowSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize window system when already running!" );
				return true;
			}
			
			glfwSetErrorCallback( glfw_error_callback );
			
			if ( !glfwInit() )
			{
				LOG_F( ERROR, "Failed to initialize GLFW" );
				return false;
			}
			
			_window = glfwCreateWindow( 640, 480, "Hello World", NULL, NULL );
			
			if ( !_window )
			{
				LOG_F( ERROR, "Failed to create GLFW window" );
				glfwTerminate();
				return false;
			}
			
			glfwMakeContextCurrent( _window );
			
			LOG_F( INFO, "WindowSystem initialized (GLFW version = %s, OpenGL version = %s) ", glfwGetVersionString(), glGetString( GL_VERSION ) );
			
			_initialized = true;
			return true;
		}
		
		bool WindowSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown window system but is not yet initialized" );
				return true;
			}
			
			glfwTerminate();
			glfwSetErrorCallback( nullptr );
			
			_window = nullptr;
			_initialized = false;
			
			LOG_F( INFO, "Window system shut down" );
			
			return true;
		}
		
		void WindowSystem::PollEvents()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Window system needs to be initialized before use." );
				return;
			}
			
			glfwPollEvents();
		}
		
		void WindowSystem::SwapBuffers()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Window system needs to be initialized before use." );
				return;
			}
			
			glfwSwapBuffers( _window );
		}
	}
}
