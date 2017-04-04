#pragma once
#include "MogeLib.h"
namespace Moge
{
	template<typename Type>
	class MogeLib_API IIterator
	{
	public:
		IIterator() = default;
		virtual ~IIterator() = default;
		virtual Type& operator*() = 0;

		virtual const bool hasNext() = 0;
		virtual Type& next() = 0;

		virtual const bool hasPrevious() = 0;
		virtual Type& previous() = 0;

		virtual const bool isEmpty() = 0;

		virtual Type& first() = 0;
		virtual Type& last() = 0;

	protected:
	private:
	};
}