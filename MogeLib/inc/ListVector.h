#pragma once
#include "List.h"
#include "IteratorListVector.h"
#include <memory>
namespace Moge
{
	template<typename Type>
	class ListVector: public IList<Type>
	{
	public:
		ListVector<Type>()
		{
			this->iterator.reset( new IteratorListVector<Type>( this->values ) );
			this->first.reset( new IteratorListVector<Type>( this->values ) );
			this->last.reset( new IteratorListVector<Type>( this->values ) );
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
			++this->last;
		}

		void remove( const IIterator<Type>& it ) override
		{
			this->values.erase( *it );
			--this->last;
		}

	protected:
	private:
		std::vector<Type> values;
		std::unique_ptr<IIterator<Type>> iterator;
		std::unique_ptr<IIterator<Type>> first;
		std::unique_ptr<IIterator<Type>> last;
	};
}