#include "ImageCreatorTests.h"
#include "Engine.h"

TEST_F( ImageCreatorTests, BmpLoadTest )
{

}

void ImageCreatorTests::SetUpTestCase()
{
	testBmpFile = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
}

Moge::Path ImageCreatorTests::testBmpFile;