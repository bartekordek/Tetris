#include "ImageCreatorTests.h"

#include "NodeImageCreator.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	Moge::ImageSurface imageSurface = Moge::ImageCreator::CreateSurfaceFromImage( testBmpFile );
	ASSERT_NE( nullptr, imageSurface.get() );
}

Moge::Path ImageCreatorTests::testBmpFile;
