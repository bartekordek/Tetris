#ifndef __EVNT_NHDLR_
#define __EVNT_NHDLR_
#include <functional>
class CEventHandler
{
public:
	void AddQuitActionHandler( std::function<void()> callback );

	//void AddHandler( std::function<void( int )> callback )
	//{
	//	callback( 1 );
	//}
	void MainEventLoop();
private:
	std::function<void()> quitCallback;
};

#endif