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

		Type& operator*() override
		{
			return this->elements[this->index];
		}

		const bool hasNext() override
		{
			if( this->index + 1 < this->elements.size() )
			{
				return true;
			}
			return false;
		}

		Type& next() override
		{
			++this->index;
			return this->elements[this->index];
		}

		const bool hasPrevious() override
		{
			if( this->index - 1 >= 0 )
			{
				return true;
			}
			return false;
		}

		IIterator<Type>& previous() override
		{
			--this->index;
			return this->elements[this->index];
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
		std::vector<Type>& elements;
		unsigned int index = 0;
	};
}