#include "ImageCreatorTests.h"

#include "NodeImageCreator.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	MogeLib::ImageSurface imageSurface = MogeLib::ImageCreator::CreateSurfaceFromImage( testBmpFile );
	ASSERT_NE( nullptr, imageSurface.get() );
}

MogeLib::Path ImageCreatorTests::testBmpFile;
