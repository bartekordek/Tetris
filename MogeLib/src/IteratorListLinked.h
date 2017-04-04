#pragma once
#include "IIterator.h"
#include <list>
namespace Moge
{
	template<typename Type>
	class IteratorListLinked: public IIterator<Type>
	{
	public:
		IteratorListLinked( const std::list<Type>& elements ): 
			elements( elements ), 
			it( elements.begin() )
		{
		}

		Type* operator->() override
		{
			return *this->it;
		}

		const bool hasNext() override
		{
			return this->elements.end() != this->it;
		}

		Type& next() override
		{
			++this->it;
			return *this->it;
		}

		const bool hasPrevious() override
		{
			return this->elements.begin() != this->it;
		}

		IIterator<Type>& previous() override
		{
			--this->it;
			return *this->it;
		}

		const bool isEmpty()override
		{
			return this->elements.empty();
		}

		Type& first() override
		{
			return this->elements.begin();
		}

		Type& last() override
		{
			return this->elements.end();
		}

	protected:
	private:
		std::list<Type>& elements;
		typename std::list<Type>::iterator it;
	};
}