#pragma once

#include <map>
#include <memory>

namespace Moge
{
	class IKey;
	class IKeyFactory
	{
	public:
		IKeyFactory();
		virtual ~IKeyFactory();
		virtual const std::map<unsigned int, std::shared_ptr<IKey>> createKeys()const = 0;
	protected:
	private:
	};
}