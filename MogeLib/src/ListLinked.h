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
		}

		IIterator<Type>& begin() override
		{
			return this->first;
		}

		IIterator<Type>& end() override
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
			this->values.erase( *it );
		}

	protected:
	private:
		std::list<Type> values;
		std::unique_ptr<IIterator<Type>> iterator;
		std::unique_ptr<IIterator<Type>> first;
		std::unique_ptr<IIterator<Type>> last;
	};
}