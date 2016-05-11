#include "ImageCreatorTests.h"

#include "NodeImageCreator.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	MOGE::ImageSurface imageSurface = MOGE::ImageCreator::CreateSurfaceFromImage( testBmpFile );
	ASSERT_NE( nullptr, imageSurface.get() );
}

MOGE::Path ImageCreatorTests::testBmpFile;