#pragma once
#include "IIterator.h"
#include <list>
namespace Moge
{
	template<typename Type>
	class IteratorListLinked: public IIterator<Type>
	{
	public:
		explicit IteratorListLinked<Type>( std::list<Type>& elements ) :
			elements( elements )
		{
		}

		explicit IteratorListLinked<Type>( IteratorListLinked<Type>& arg ) :
			elements( arg.elements )
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
			//if( nullptr == this->it )
			//{
			//	return false;
			//}

			if( this->it == this->elements.end() )
			{
				return false;
			}

			if( this->elements.size() == 1 && this->it == this->elements.begin() )
			{
				return true;
			}
			auto tempIt = this->it;
			++tempIt;
			const bool result = this->elements.end() != tempIt;
			return result;
		}

		Type& next() override
		{
			// Fix for std:: the first element always contains first value, but last does not.
			return *( this->it++ );
			//if( this->it == this->elements.begin() )
			//{
			//	return * (this->it++);
			//}
			//return *(++this->it);
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

		void setIterator( const typename std::list<Type>::iterator& inIt )
		{
			this->it = inIt;
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

		Type& operator--() override
		{
			--this->it;
			return *this->it;
		}

		Type operator--( int ) override
		{
			Type temp = *this->it;
			--this->it;
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
			const IteratorListLinked<Type>* rightPtr = static_cast<const IteratorListLinked<Type>*>( &right );
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
