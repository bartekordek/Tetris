#ifndef _BTN_
#define _BTN_
#include "Utils.h"
#include "Point.h"

class CButton: public CPoint
{
public:
	CButton( CUInt x, CUInt y, const String& buttonName = "dummy", const Path& buttonLocation = "" );
	String GetPath()const;

private:
	Path m_imagePath;
	String m_buttonName;
};

#endif