#pragma once

#include <memory>

#include "Node.h"
#include "FileSystem.h"


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
		ObjectNode( const Path& filePath );
		~ObjectNode();

		const std::shared_ptr<SDL_Surface> GetContent()const;

	private:
		void FreeContent() override;
		std::shared_ptr<SDL_Surface> surface;

	};

}