#pragma once
#include "List.h"
#include "IteratorListLinked.h"
#include <memory>
namespace Moge
{
	template<typename Type>
	class ListVector: public IList<Type>
	{
	public:
		ListVector<Type>()
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

		const unsigned int size()const override
		{
			return static_cast<unsigned int>( this->values.size() );
		}

		void pushBack( const Type& element ) override
		{
			this->values.push_back( element );
			*this->first.get() = this->values.begin();
			*this->last.get() = this->values.end();
		}

		void remove( const IIterator<Type>& it ) override
		{
			const Type& val = it.getVal();
			auto newIt = std::find( this->values.begin(), this->values.end(), val );
			if( newIt != this->values.end() )
			{
				this->values.erase( newIt );
			}
		}

	protected:
	private:
		std::list<Type> values;
		std::unique_ptr<IteratorListLinked<Type>> iterator;
		std::unique_ptr<IteratorListLinked<Type>> first;
		std::unique_ptr<IteratorListLinked<Type>> last;
	};
}