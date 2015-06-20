#ifndef __EVNT_NHDLR_
#define __EVNT_NHDLR_

#include <functional>
class CEventHandler
{
public:
	void AddHandler( std::function<void( int )> callback )
	{
		callback( 1 );
	}
private:

};

#endif