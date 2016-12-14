#pragma once
#ifndef __EMBER_I_CLEANABLE_H
#define __EMBER_I_CLEANABLE_H

/*
 * @file ICleanable.h
 * @author PJ O Halloran
 * @date 14/12/2016
 */

namespace ember
{
	namespace core
	{
		class ICleanable
		{
			public:
				virtual ~ICleanable() {};
				
				virtual void VClean() = 0;
				
				bool IsDirty()
				{
					return false;
				};
		};
	}
}

#endif
