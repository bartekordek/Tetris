#pragma once
#include "IList.h"
#include "IteratorListLinked.h"
#include <memory>
#include <algorithm>
namespace Moge
{
	template<typename Type>
	class ListLinked: public IList<Type>
	{
	public:
		ListLinked<Type>()
		{
			this->iterator.reset( new IteratorListLinked<Type>( this->values ) );
			this->first.reset( new IteratorListLinked<Type>( this->values ) );
			this->last.reset( new IteratorListLinked<Type>( this->values ) );
		}

		const IIterator<Type>& begin() const override
		{
			return *this->first.get();
		}

		const IIterator<Type>& end() const override
		{
			return *this->last.get();
		}

		IIterator<Type>* getRandomIteratorPtr()override
		{
			return this->iterator.get();
		}

		IIterator<Type>& getRandomIterator()override
		{
			return *this->iterator.get();
		}

		const unsigned int size()const override
		{
			return static_cast<unsigned int>( this->values.size() );
		}

		void pushBack( const Type& element ) override
		{
			this->values.push_back( element );
		}

		void remove( const IIterator<Type>& it ) override
		{
			const Type& val = it.getVal();
			remove( val );
		}
		
		void remove( const Type& element ) override
		{
			auto newIt = std::find( this->values.begin(), this->values.end(), element );
			if( newIt != this->values.end() )
			{
				this->values.erase( newIt );
				--*this->last.get();
			}
		}

		const std::shared_ptr<IIterator<Type>> find( const Type& type ) const override
		{
			std::shared_ptr<IIterator<Type>> result( new IteratorListLinked<Type>( *this->first ) );
			while( result->hasNext() )
			{
				if( result.get()->getVal() == type )
				{
					return result;
				}
				++*result;
			}
			return result;
		}

	protected:
	private:
		std::list<Type> values;
		std::unique_ptr<IteratorListLinked<Type>> iterator;
		std::unique_ptr<IteratorListLinked<Type>> first;
		std::unique_ptr<IteratorListLinked<Type>> last;
	};
}
