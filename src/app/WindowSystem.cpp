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
		void OnGLFWErrorCallback( int error, const char *errorMsg )
		{
			LOG_F( ERROR, "GLFW error code = %i, message = %s", error, errorMsg );
		}
		
		using namespace ember::core;
		
		const F32 WindowSystem::DPI = 25.4;
		const char *WindowSystem::Name = "Window";
		
		bool WindowSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return false;
			}
			
			glfwSetErrorCallback( OnGLFWErrorCallback );
			
			if ( !glfwInit() )
			{
				LOG_F( ERROR, "Failed to initialize GLFW" );
				return false;
			}
			
			GLFWmonitor *monitor = glfwGetPrimaryMonitor();
			
			if ( !monitor )
			{
				LOG_F( ERROR, "Failed to get the primary monitor" );
				return false;
			}
			
			const GLFWvidmode *mode = glfwGetVideoMode( monitor );
			
			if ( !mode )
			{
				LOG_F( ERROR, "Failed to get the primary monitor's video mode" );
				return false;
			}
			
			glfwWindowHint( GLFW_RED_BITS, mode->redBits );
			glfwWindowHint( GLFW_GREEN_BITS, mode->greenBits );
			glfwWindowHint( GLFW_BLUE_BITS, mode->blueBits );
			glfwWindowHint( GLFW_REFRESH_RATE, mode->refreshRate );
			glfwWindowHint( GLFW_DOUBLEBUFFER, GLFW_TRUE );
			glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_API );
			glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
			glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
			glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );
			glfwWindowHint( GLFW_OPENGL_DEBUG_CONTEXT, GLFW_FALSE );
			glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
			
			//_window = glfwCreateWindow( mode->width, mode->height, "ember", monitor, NULL );
			_window = glfwCreateWindow( mode->width, mode->height, "ember", NULL, NULL );
			
			if ( !_window )
			{
				LOG_F( ERROR, "Failed to create GLFW window" );
				glfwTerminate();
				return false;
			}
			
			glfwMakeContextCurrent( _window );
			
			LOG_F( INFO, "%s initialized (GLFW version = %s, OpenGL version = %s) ", Name, glfwGetVersionString(), glGetString( GL_VERSION ) );
			
			_initialized = true;
			return true;
		}
		
		bool WindowSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s but is not yet initialized", Name );
				return false;
			}
			
			glfwDestroyWindow( _window );
			_window = nullptr;
			
			glfwTerminate();
			glfwSetErrorCallback( nullptr );
			
			_initialized = false;
			
			LOG_F( INFO, "%s shutdown", Name );
			
			return true;
		}
		
		bool WindowSystem::IsClosing() const
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s but is not yet initialized", Name );
				return false;
			}
			
			return glfwWindowShouldClose( _window ) == GLFW_TRUE;
		}
		
		bool WindowSystem::GetWindowSize( F32 &width, F32 &height ) const
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "%s needs to be initialized before use.", Name );
				return false;
			}
			
			int w, h;
			glfwGetWindowSize( _window, &w, &h );
			
			width = ( F32 )w;
			height = ( F32 )h;
			
			return true;
		}
		
		bool WindowSystem::GetFrameBufferSize( F32 &width, F32 &height ) const
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "%s needs to be initialized before use.", Name );
				return false;
			}
			
			int w, h;
			glfwGetFramebufferSize( _window, &w, &h );
			
			width = ( F32 )w;
			height = ( F32 )h;
			
			return true;
		}
		
		bool WindowSystem::GetDpi( int &dpi ) const
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "%s needs to be initialized before use.", Name );
				return false;
			}
			
			GLFWmonitor *monitor = glfwGetPrimaryMonitor();
			
			if ( !monitor )
			{
				LOG_F( ERROR, "Failed to get the primary monitor" );
				return false;
			}
			
			const GLFWvidmode *mode = glfwGetVideoMode( monitor );
			
			if ( !mode )
			{
				LOG_F( ERROR, "Failed to get the primary monitor's video mode" );
				return false;
			}
			
			int w, h;
			glfwGetMonitorPhysicalSize( monitor, &w, &h );
			dpi = mode->width / ( w / DPI );
			
			return true;
		}
		
		const char *WindowSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
