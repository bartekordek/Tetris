#ifndef __EVNT_NHDLR_
#define __EVNT_NHDLR_
#include <functional>

/*
 * @brief Event handler class.
 */
class CEventHandler
{
public:
	/*
	 * @brief Adds function / method to manage quit functionality. 
	 * @param[in] std::function call back function name. 
	 */
	void AddQuitActionHandler( std::function<void()> callback );
	void MainEventLoop();
private:
	std::function<void()> quitCallback;
};

#endif
