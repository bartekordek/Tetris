#include "ILogUtil.h"
#include "LOgUtilConcrete.h"

using namespace Moge;

ILogUtil* LogFactory::getConcrete()
{
	return new LOgUtilConcrete();
}