#pragma once

#include "GeneralUtilities.h"
#include "SDL/SDL.h"
#include "Node.h"
#include <unordered_map>

namespace MOGE
{
	class MOGE: public Singleton<MOGE>
	{
	public:
		virtual ~MOGE();
	protected:
	private:
		std::unordered_map< String, Node* > mObjects;
	};
}