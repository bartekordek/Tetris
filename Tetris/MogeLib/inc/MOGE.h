#pragma once

#ifdef MOGE_EXPORT
#define MOGE_API __declspec(dllexport)
#else
#define MOGE_API __declspec(dllimport)
#endif