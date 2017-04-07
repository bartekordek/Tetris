#pragma once
#include "MogeLib.h"
#include "List.h"
#include "ListLinked.h"
#include "ListVector.h"

namespace Moge
{
	template<typename Type>
	class MogeLib_API ListFactory
	{
	public:
		static IList<Type>* createVectorListPtr()
		{
			return new ListVector<Type>();
		}
		
		static IList<Type>* createLinkedListPtr()
		{
			return new ListLinked<Type>();
		}
		
	private:

	};
}