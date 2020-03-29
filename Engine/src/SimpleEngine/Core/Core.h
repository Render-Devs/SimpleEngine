#pragma once

#ifdef SE_BUILD_DLL
    #define SE_API _declspec(dllexport)
#else
    #define SE_API _declspec(dllimport)
#endif