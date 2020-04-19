#pragma once

#include <cstddef>

namespace SimpleEngine::Core::Memory
{
    class Allocator
    {
    protected:
        std::size_t m_size;
        std::size_t m_used;
        std::size_t m_peak;

    public:
        Allocator(const std::size_t size);
        virtual ~Allocator();

        virtual void Init() = 0;
        virtual void* Allocate(const std::size_t chunkSize, const std::size_t alignment = 0) = 0;
        virtual void Free(void* ptr) = 0;        
    };
}