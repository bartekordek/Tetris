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
			elements( elements ), 
			it( elements.begin() )
		{
		}

		IteratorListLinked<Type>( IteratorListLinked<Type>& arg ) :
			elements( arg.elements ),
			it( arg.elements.begin() )
		{
		}

		virtual ~IteratorListLinked()
		{
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

		IIterator<Type>& operator=( const typename std::list<Type>::iterator& inIt )
		{
			if( this->it != inIt )
			{
				this->it = inIt;
			}
			return *this;
		}

		IteratorListLinked<Type>& operator=( const IteratorListLinked<Type>& right )
		{
			if( this != &right )
			{
				this->elements = right.elements;
				this->it = right.it;
			}
			return *this;
		}

		Type& operator++() override
		{
			++this->it;
			return *this->it;
		}

		Type operator++( int ) override
		{
			Type temp = *this->it;
			++this->it;
			return temp;
		}

		IIterator<Type>& operator=( const IIterator<Type>& right ) override
		{
			auto ptr = static_cast<const IteratorListLinked<Type>*>( &right );
			if( this != ptr )
			{
				this->elements = ptr->elements;
				this->it = ptr->it;
			}
			return *this;
		}

		const bool operator==( const IIterator<Type>& right )const override
		{
			const IteratorListLinked<Type>* rightPtr = static_cast<IteratorListLinked<Type>*>( &right );
			if( this != rightPtr )
			{
				if( this->elements != rightPtr->elements || this->it != rightPtr->it )
				{
					return false;
				}
			}
			return true;
		}

	protected:
	private:
		std::list<Type>& elements;
		typename std::list<Type>::iterator it;
	};
}