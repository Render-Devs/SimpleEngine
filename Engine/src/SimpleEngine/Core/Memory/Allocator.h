#pragma once

#include <cstddef>

namespace SimpleEngine::Core::Memory
{
    using word_t = intptr_t;

    class Allocator
    {
    protected:
        std::size_t m_totalSize;
        std::size_t m_used;
        std::size_t m_peak;

    public:
        Allocator(const std::size_t totalSize);
        virtual ~Allocator();

        virtual void Init() = 0;
        virtual void* Allocate(const std::size_t chunkSize, const std::size_t alignment = 0) = 0;
        virtual void Free(void* ptr) = 0;
        virtual void Reset() = 0;

    protected:
        static size_t align(size_t n)
        {            
            return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
        }
    };
}