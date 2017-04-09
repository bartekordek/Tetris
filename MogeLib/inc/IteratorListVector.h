#pragma once
#include "IIterator.h"
#include <vector>
namespace Moge
{
	template<typename Type>
	class IteratorListVector: public IIterator<Type>
	{
	public:
		IteratorListVector( const std::vector<Type>& elements ): elements( elements )
		{
		}

		const bool hasNext() const override
		{
			return this->index + 1 < this->elements.size();
		}

		Type& next() override
		{
			++this->index;
			return this->elements[this->index];
		}

		const bool hasPrevious()const override
		{
			return this->index - 1 >= 0;
		}

		IIterator<Type>& previous() override
		{
			--this->index;
			return this->elements[this->index];
		}

		const bool isEmpty() const override
		{
			return this->elements.empty();
		}

		IteratorListVector<Type>& first() override
		{
			return this->elements.begin();
		}

		IteratorListVector<Type>& last() override
		{
			return this->elements.end();
		}

		IteratorListVector<Type>& operator++()
		{
			++this->index;
			return *this;
		}

		IteratorListVector<Type> operator++( int )
		{
			IteratorListVector<Type> temp = *this;
			++index;
			return temp;
		}

		IteratorListVector<Type>& operator--()
		{
			--this->index;
		}

		IteratorListVector<Type> operator--( int )
		{
			IteratorListVector<Type> temp = *this;
			--index;
			return temp;
		}

		IteratorListVector<Type>& operator=( const IteratorListVector<Type>& right )
		{
			if( this != &right )
			{
				this->elements = right.elements;
				this->index = right.index;
			}
			return *this;
		}

	protected:
	private:
		std::vector<Type>& elements;
		unsigned int index = 0;
	};
}