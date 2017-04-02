#pragma once
#include "MogeLib.h"
namespace Moge
{
	template<typename Type>
	class MogeLib_API IIterator
	{
	public:
		virtual Type& operator*() = 0;

		virtual const bool hasNext() = 0;
		virtual IIterator<Type>& next() = 0;

		virtual const bool hasPrevious() = 0;
		virtual IIterator<Type>& previous() = 0;

	protected:
	private:
	};
}