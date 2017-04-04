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
			iterator.reset( new IteratorListLinked<Type>( this->values ) );
			this->first.reset( new IteratorListLinked<Type>( this->values ) );
			this->last.reset( new IteratorListLinked<Type>( this->values ) );
		}

		const IIterator<Type>& begin() const override
		{
			return this->first;
		}

		const IIterator<Type>& end() const override
		{
			return this->last;
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
            Type& wut = *it;
           /* auto ptr = std::find( this->values.begin(), this->values.end(), *it );
			this->values.erase( ptr );*/
		}

	protected:
	private:
		std::list<Type> values;
		std::unique_ptr<IIterator<Type>> iterator;
		std::unique_ptr<IIterator<Type>> first;
		std::unique_ptr<IIterator<Type>> last;
	};
}