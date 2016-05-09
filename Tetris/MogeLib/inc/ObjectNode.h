#pragma once

#include <memory>

#include "Node.h"
#include "FileSystem.h"
#include "SurfaceWrapper.h"

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

		const std::shared_ptr<SurfaceWrapper> GetContent()const;

		const Path& GetPath()const;

	private:
		void FreeContent() override;
		std::shared_ptr<SurfaceWrapper> surface;
		Path mFilePath;

	};
}