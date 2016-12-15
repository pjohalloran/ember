/*
 * @file Timer.cpp
 * @author PJ O Halloran
 * @date 14/12/2016
 */

#include "EmberTimer.h"

namespace ember
{
	namespace core
	{
		void Timer::Start()
		{
			m_started = true;
			m_paused = false;
			m_startTicks = GetTicks();
		}
		
		void Timer::Stop()
		{
			m_started = false;
			m_paused = false;
		}
		
		void Timer::Pause()
		{
			if ( ( m_started ) && ( !m_paused ) )
			{
				m_paused = true;
				m_pausedTicks = GetTicks() - m_startTicks;
			}
		}
		
		void Timer::UnPause()
		{
			if ( m_paused )
			{
				m_paused = false;
				m_startTicks = GetTicks() - m_pausedTicks;
				m_pausedTicks = 0;
			}
		}
		
		F64 Timer::GetTime()
		{
			if ( m_started )
			{
				if ( m_paused )
				{
					return m_pausedTicks;
				}
				else
				{
					F64 currTime = GetTicks();
					return currTime - m_startTicks;
				}
			}
			
			// The timer is not currently running
			return 0.0;
		}
		
		bool Timer::IsStarted() const
		{
			return m_started;
		}
		
		bool Timer::IsPaused() const
		{
			return m_paused;
		}
	}
}
