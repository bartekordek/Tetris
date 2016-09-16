#pragma once

#include <memory>
#include <set>

#include "Node.h"
#include "Visible.h"
#include "FileSystem.h"
#include "SurfaceWrapper.h"

namespace MogeLib
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	class MOGE_API ObjectNodeContent: public Node, public Visible
	{
	public:
		ObjectNodeContent();
		ObjectNodeContent( const Path& filePath );
		~ObjectNodeContent();

		const ImageSurface& GetSurface()const;

		const Path& GetPath()const;

		void SetSurface( const ImageSurface& surface );
	protected:
		virtual void UpdateImplementation();

	private:
		void FreeContent() override;
		std::shared_ptr<SurfaceWrapper> surface;
		Path mFilePath;

	};
	
	using ObjectNode = std::shared_ptr<ObjectNodeContent>;
}