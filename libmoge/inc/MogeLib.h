#pragma once

#if _WIN32
#define MOGE_WINDOWS
#define MOGE_EXPORT
#else
#define MOGE_LINUX
#endif

#if defined MOGE_EXPORT && defined MOGE_WINDOWS
#define MogeLib_API __declspec(dllexport)
#define MogeLib_API_TEMPLATE
#elif MOGE_EXPORT && defined MOGE_LINUX
#define MogeLib_API
#define MogeLib_API_TEMPLATE
#else
#define MogeLib_API __declspec(dllimport)
#define MogeLib_API_TEMPLATE extern
#endif
/*TODO: Find a way to tell library name.
#ifdef _MSC_VER && SDL2Wrapper_DYNAMIC
#pragma comment(lib, "SDL2WrapperDynamic.lib")
#elif  MSC_VER
#pragma comment(lib, "SDL2WrapperStatic.lib")
#else
#pragma comment(lib, "libsdl2wrapper.a")
#endif
*/