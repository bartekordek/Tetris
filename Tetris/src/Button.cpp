#include "Button.h"

CButton::CButton( 
	CUInt x, CUInt y, 
	const String& buttonName, 
	const Path& buttonLocation ):
		CPoint( x, y ), m_buttonName( buttonName ),
		m_imagePath( buttonLocation )
{

}

String CButton::GetPath()const
{
	return m_imagePath.string();
}