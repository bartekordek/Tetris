#pragma once

#include "Node.h"

namespace MOGE
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	class MOGE_API ObjectNode: public Node
	{
	public:
		ObjectNode();
		~ObjectNode();

	private:
		void FreeContent() override;
	};

}