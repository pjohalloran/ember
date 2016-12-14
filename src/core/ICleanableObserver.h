#pragma once
#ifndef __EMBER_I_CLEANABLE_OBSERVER_H
#define __EMBER_I_CLEANABLE_OBSERVER_H

/*
 * @file ICleanableObserver.h
 * @author PJ O Halloran
 * @date 14/12/2016
 */

#include "ICleanable.h"

namespace ember
{
	namespace core
	{
		class ICleanableObserver
		{
			public:
				virtual ~ICleanableObserver() {};
				
				virtual void VNotifyDirty( ICleanable *ptr ) = 0;
		};
	}
}


#endif
