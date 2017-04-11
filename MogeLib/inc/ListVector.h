#pragma once
#include "IList.h"
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
			auto ptr = static_cast<IteratorListVector<Type>*>( this->first.get() );
			std::shared_ptr<IIterator<Type>> result( new IteratorListVector<Type>( *ptr ) );
			while( result->hasNext() )
			{
				if( result.get()->getVal() == type  )
				{
					return result;
				}
				++*result.get();

			}
			return result;
		}

	protected:
	private:
		std::vector<Type> values;
		std::unique_ptr<IIterator<Type>> iterator;
		std::unique_ptr<IIterator<Type>> first;
		std::unique_ptr<IIterator<Type>> last;
	};
}
