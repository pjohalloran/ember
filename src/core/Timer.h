#pragma once
#ifndef __EMBER_TIMER_H
#define __EMBER_TIMER_H

/*
 * @file Timer.h
 * @author PJ O Halloran
 * @date 14/12/2016
 */

// TODO used to be GameBase.h
#include "GameTypes.h"

namespace ember
{
	namespace core
	{
		class Timer
		{
			private:
			
				F64 m_startTicks;
				F64 m_pausedTicks;
				bool m_started;
				bool m_paused;
				
				F64 GetTicks()
				{
					// TODO fixme
					//return (F64)glfwGetTime();
					return 0;
				};
				
			protected:
			
				void SetStartTicks( const F64 st )
				{
					m_startTicks = st;
				};
				
				F64 GetStartTicks() const
				{
					return ( m_startTicks );
				};
				
				void SetPauseTicks( const F64 pt )
				{
					m_pausedTicks = pt;
				};
				
				F64 GetPauseTicks() const
				{
					return ( m_pausedTicks );
				};
				
			public:
			
				Timer() : m_startTicks( 0.0 ), m_pausedTicks( 0.0 ), m_paused( false ), m_started( false ) { };
				~Timer() { };
				
				void Start();
				
				void Stop();
				
				void Pause();
				
				void UnPause();
				
				F64 GetTime();
				
				bool IsStarted() const;
				
				bool IsPaused() const;
		};
	}
}

#endif
