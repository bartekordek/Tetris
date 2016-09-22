#pragma once

#include <memory>
#include <set>

#ifdef MogeLib_EXPORT
#define MogeLib_API __declspec(dllexport)
#define MogeLib_API_TEMPLATE
#else
#define MogeLib_API __declspec(dllimport)
#define MogeLib_API_TEMPLATE extern
#endif

namespace Moge
{
	class ObjectNodeContent;
	//MogeLib_API_TEMPLATE template class MogeLib_API std::set<std::shared_ptr<ObjectNodeContent>>;
}