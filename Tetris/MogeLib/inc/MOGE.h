#pragma once

#include <memory>
#include <set>

#ifdef MOGE_EXPORT
#define MOGE_API __declspec(dllexport)
#define MOGE_API_TEMPLATE
#else
#define MOGE_API __declspec(dllimport)
#define MOGE_API_TEMPLATE extern
#endif

namespace MOGE
{
	class ObjectNodeContent;
	//MOGE_API_TEMPLATE template class MOGE_API std::set<std::shared_ptr<ObjectNodeContent>>;
}