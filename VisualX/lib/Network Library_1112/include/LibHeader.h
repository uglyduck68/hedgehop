#if defined(_MSC_VER) &&  (_MSC_VER >= 1200)
#pragma once
#endif
#ifndef LibHeader_H
#define LibHeader_H
#define EnLib
#ifdef EnLib
#define LIBEXPORT __declspec(dllexport)
#else
#define LIBEXPORT __declspec(dllimport)
#endif
#endif