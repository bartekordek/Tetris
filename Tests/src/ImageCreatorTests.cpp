#include "ImageCreatorTests.h"
#include "SurfaceFactory.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	auto imageSurface = Moge::SurfaceFactory::CreateSurfaceFromImage( testBmpFile );
	ASSERT_NE( nullptr, imageSurface.get() );
}
void ImageCreatorTests::SetUpTestCase()
{
	testBmpFile = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
}

Moge::Path ImageCreatorTests::testBmpFile;