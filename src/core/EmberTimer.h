#pragma once
#ifndef __EMBER_TIMER_H
#define __EMBER_TIMER_H

/*
 * @file EmberTimer.h
 * @author PJ O Halloran
 * @date 14/12/2016
 */

#include "EmberTypes.h"

namespace ember
{
	namespace core
	{
		class EmberTimer
		{
			private:
			
				F64 _start;
				F64 _end;
				bool _running;
				
			public:
			
				EmberTimer() : _running( false ), _start( -1.0 ), _end( -1.0 ) { }
				
				~EmberTimer() { }
				
				inline F64 Duration() const
				{
					return _end - _start;
				}
				
				inline bool Running() const
				{
					return _running;
				}
				
				inline void Reset()
				{
					_running = false;
					_start = _end = -1.0;
				}
				
				void Start();
				
				void Stop();
		};
	}
}
#endif
