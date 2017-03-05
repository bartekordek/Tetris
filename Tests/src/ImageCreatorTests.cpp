#include "ImageCreatorTests.h"
#include "SurfaceFactory.h"
#include "Engine.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{
	auto imageSurface = engine->getSurfaceFactory()->CreateSurfaceFromImage( testBmpFile );
	ASSERT_NE( nullptr, imageSurface.get() );
}
void ImageCreatorTests::SetUpTestCase()
{
	testBmpFile = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
}

Moge::Path ImageCreatorTests::testBmpFile;