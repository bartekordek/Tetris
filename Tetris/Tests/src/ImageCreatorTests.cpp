#include "ImageCreatorTests.h"

#include "NodeImageCreator.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	MOGE::ImageSurface imageSurface = MOGE::ImageCreator::CreateSurfaceFromImage( genericWindowsImagePath );
	ASSERT_NE( nullptr, imageSurface.get() );
}