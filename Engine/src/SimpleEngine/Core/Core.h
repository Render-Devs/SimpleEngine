#pragma once

#include <cstdint>

#ifdef SE_BUILD_DLL
    #define SE_API _declspec(dllexport)
#else
    #define SE_API _declspec(dllimport)
#endif

using u8            = uint8_t;
using u32           = uint32_t;
using u64           = uint64_t;
using uptr          = uintptr_t;