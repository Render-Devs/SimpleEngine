#pragma once

#include "Allocator.h"

namespace SimpleEngine::Core::Memory
{
    class StackAllocator: public Allocator
    {
    public:
        StackAllocator(const std::size_t size);
        StackAllocator(StackAllocator&) = delete;
        ~StackAllocator();

        void* Allocate(const std::size_t chunkSize, const std::size_t alignment) override;
        void Free(void* ptr) override;
        void Init() override;
        void Reset() override;

    private:
    };
}