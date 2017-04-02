#pragma once
#include "IIterator.h"
#include <vector>
namespace Moge
{
	template<typename Type>
	class IteratorListVector: public IIterator<Type>
	{
	public:
		IteratorListVector( const std::vector<Type>* elements ): elements( elements )
		{
		}

		Type& operator*() override
		{
		}

		const bool hasNext() override
		{
			if( this->listVectIt.ne )
			{
				
			}
		}

		IIterator<Type>& next() override
		{

		}

		const bool hasPrevious() override
		{
		}

		IIterator<Type>& previous() override
		{
		}

	protected:
	private:
		std::vector<Type>* elements = nullptr;
		std::vector<Type>::iterator listVectIt;

	};
}