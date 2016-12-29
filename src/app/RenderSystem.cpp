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
		using namespace ember::core;
		
		const char *RenderSystem::Name = "Render";
		
		bool RenderSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			if ( flextInit( Application->Window()->GetWindow() ) != GL_TRUE )
			{
				LOG_F( ERROR, "Failed to init the FLEXT system with version %i.%i and core profile %i", FLEXT_MAJOR_VERSION, FLEXT_MINOR_VERSION, FLEXT_CORE_PROFILE );
				return false;
			}
			
			LOG_F( INFO, "Setup FLEXT system using version %i.%i and core profile %i", FLEXT_MAJOR_VERSION, FLEXT_MINOR_VERSION, FLEXT_CORE_PROFILE );
			
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
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *RenderSystem::VGetSystemName()
		{
			return Name;
		}
		
		void RenderSystem::SwapBuffers()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "%s needs to be initialized before use.", Name );
				return;
			}
			
			glfwSwapBuffers( Application->Window()->GetWindow() );
		}
	}
}
