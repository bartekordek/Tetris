#ifndef __CSLAB__
#define __CSLAB__

#include "Picture.h"

class CSlab
{
public:
	CSlab( const CPicture& picture );
	CSlab( const CSlab& slab );
	void Draw();

private:
	bool m_hasBorder;
	CPicture m_picture;

};

#endif