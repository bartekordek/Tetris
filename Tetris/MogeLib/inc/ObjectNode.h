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

	template class MOGE_API std::shared_ptr<SurfaceWrapper>;

	class MOGE_API ObjectNodeContent: public Node
	{
	public:
		ObjectNodeContent();
		ObjectNodeContent( const Path& filePath );
		~ObjectNodeContent();

		const ImageSurface& GetContent()const;

		const Path& GetPath()const;

		void SetSurface( const ImageSurface& surface );

	private:
		void FreeContent() override;
		std::shared_ptr<SurfaceWrapper> surface;
		Path mFilePath;

	};
	template class MOGE_API std::shared_ptr<ObjectNodeContent>;
	using ObjectNode = std::shared_ptr<ObjectNodeContent>;
}