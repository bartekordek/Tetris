#pragma once

#ifdef MOGE_EXPORT
#define MOGE_API __declspec(dllexport)
#define MOGE_API_TEMPLATE
#else
#define MOGE_API __declspec(dllimport)
#define MOGE_API_TEMPLATE extern
#endif