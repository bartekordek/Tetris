#pragma once

#include "Node.h"
#include <memory>

namespace MOGE
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	template class MOGE_API std::shared_ptr<SDL_Surface>;

	class MOGE_API ObjectNode: public Node
	{
	public:
		ObjectNode();
		~ObjectNode();

	private:
		void FreeContent() override;
		std::shared_ptr<SDL_Surface> surface;

	};

}