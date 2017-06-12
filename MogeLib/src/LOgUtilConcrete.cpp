#include "LOgUtilConcrete.h"
#include "TimerChrono.h"
#include <iostream>
#include <boost/format.hpp>
using namespace Moge;
LOgUtilConcrete::LOgUtilConcrete(): timer( new TimerChrono )
{
	this->timer->start();
}

LOgUtilConcrete::~LOgUtilConcrete()
{
}

void LOgUtilConcrete::showMessage( const char* message, const LogType type )
{
	const auto ms = this->timer->getElapsed().getMs();
	const std::string chuj;
	std::lock_guard<std::mutex> lock( this->msgLock );
	boost::format formatobject( "t = %12d" );
	formatobject % ms;
	std::cout << formatobject;
	switch( type )
	{
		case LogType::DEBUG:
		{
			std::cout << ":[DEBUG]: ";
			break;
		}
		case LogType::WARNING:
		{
			std::cout << ":[WARNING]: ";
			break;
		}
		case LogType::ERROR:
		{
			std::cout << ":[ERROR]: ";
			break;
		}
		default:
		{
			std::cout << ":[INFO]: ";
			break;
		}
	}
	
	std::cout << message;
	std::cout << "\n";
}