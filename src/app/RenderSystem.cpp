/*
 * @file RenderSystem.cpp
 * @author PJ O Halloran
 * @date 27/12/2016
 */

#include "RenderSystem.h"

#include "core/EmberPlatform.h"
#include "app/WindowSystem.h"
#include "app/EmberApp.h"

namespace ember
{
	namespace app
	{
		const char *RenderSystem::Name = "Render";
		
		bool RenderSystem::VInitialize( int argc, char **argv )
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			CHECK_WITH_INFO_F( Application != nullptr && Application->Window() != nullptr && Application->Window()->VInitialized(), "WindowSystem needs to be intialized before the %s", "%s", Name );
			
			if ( flextInit( Application->Window()->GetWindow() ) != GL_TRUE )
			{
				LOG_F( ERROR, "Failed to init the FLEXT system with version %i.%i and core profile %i", FLEXT_MAJOR_VERSION, FLEXT_MINOR_VERSION, FLEXT_CORE_PROFILE );
				return false;
			}
			
			LOG_F( INFO, "Setup FLEXT system using version %i.%i and core profile %i", FLEXT_MAJOR_VERSION, FLEXT_MINOR_VERSION, FLEXT_CORE_PROFILE );
			
			rmt_BindOpenGL();
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		bool RenderSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when already running!", Name );
				return true;
			}
			
			rmt_UnbindOpenGL();
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *RenderSystem::VGetSystemName()
		{
			return Name;
		}
		
		void RenderSystem::Clear()
		{
			glClear( GL_COLOR_BUFFER_BIT );
		}
		
		void RenderSystem::SwapBuffers()
		{
			glfwSwapBuffers( Application->Window()->GetWindow() );
		}
		
		void RenderSystem::Draw()
		{
		
		}
	}
}
