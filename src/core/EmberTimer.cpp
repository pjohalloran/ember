/*
 * @file EmberTimer.cpp
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include "EmberTimer.h"

//#include "EmberApp.h"

namespace ember
{
	using namespace app;
	
	namespace core
	{
		void EmberTimer::Start()
		{
			if ( _running )
			{
				return;
			}
			
			_start = Application->Time()->GetCurrentTime();
			_running = true;
		}
		
		void EmberTimer::Stop()
		{
			if ( !_running )
			{
				return;
			}
			
			_end = Application->Time()->GetCurrentTime();
			_running = false;
		}
	}
}
