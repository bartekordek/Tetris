#include "ImageCreatorTests.h"

#include "NodeImageCreator.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	std::shared_ptr<MOGE::SurfaceWrapper> imageSurface = MOGE::ImageCreator::CreateSurfaceFromImage( testBmpFile );
	ASSERT_NE( nullptr, imageSurface.get() );
}

MOGE::Path ImageCreatorTests::testBmpFile;