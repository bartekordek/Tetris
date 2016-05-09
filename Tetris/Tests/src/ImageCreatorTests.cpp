#include "ImageCreatorTests.h"

#include "NodeImageCreator.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	std::shared_ptr<MOGE::SurfaceWrapper> imageSurface = MOGE::ImageCreator::CreateSurfaceFromImage( genericWindowsImagePath );
	ASSERT_NE( nullptr, imageSurface.get() );
}