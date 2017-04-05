#pragma once
#include "IIterator.h"
#include <list>
namespace Moge
{
	template<typename Type>
	class IteratorListLinked: public IIterator<Type>
	{
	public:
		IteratorListLinked<Type>( std::list<Type>& elements ): 
			elements( elements )
		{
		}

		virtual ~IteratorListLinked()
		{
		}
		
		IteratorListLinked<Type>& operator=( const typename std::list<Type>::iterator& inIt )
		{
			if( this->it != inIt )
			{
				this->it = inIt;
			}
			return *this;
		}
			
		Type& getVal()override
		{
			return *this->it;
		}
		
		const Type& getVal()const override
		{
			return *this->it;
		}

		const bool hasNext()const override
		{
			return this->elements.end() != this->it;
		}

		Type& next() override
		{
			++this->it;
			return *this->it;
		}

		const bool hasPrevious()const override
		{
			return this->elements.begin() != this->it;
		}

		Type& previous() override
		{
			--this->it;
			return *this->it;
		}

		const bool isEmpty()const override
		{
			return this->elements.empty();
		}

		Type& first() override
		{
			return *this->it;
		}

		Type& last() override
		{
			return *this->it;
		}
		
		const Type& first()const override
		{
			return *this->it;
		}

		const Type& last()const override
		{
			return *this->it;
		}

	protected:
	private:
		std::list<Type>& elements;
		typename std::list<Type>::iterator it;
	};
}