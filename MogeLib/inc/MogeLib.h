#pragma once

#ifdef MogeLib_EXPORT
#define MogeLib_API __declspec(dllexport)
#define MogeLib_API_TEMPLATE
#else
#define MogeLib_API __declspec(dllimport)
#define MogeLib_API_TEMPLATE extern
#endif