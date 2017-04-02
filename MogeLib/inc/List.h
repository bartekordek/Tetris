#pragma once
#include "IIterator.h"
namespace Moge
{
	template<typename Type>
	class MogeLib_API IList
	{
	public:
		IList() = default;
		virtual ~IList() = default;

		virtual IIterator<Type>& begin() = 0;
		virtual IIterator<Type>& end() = 0;

		virtual const unsigned int size()const = 0;

		virtual void pushBack( const Type& element ) = 0;
		virtual void remove( const IIterator<Type>& it ) = 0;


	protected:
	private:
	};
}