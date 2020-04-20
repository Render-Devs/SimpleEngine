#pragma once

#include "IAllocator.h"
#include "SimpleEngine/Core/Core.h"

#include <cstddef>

namespace SimpleEngine::Core::Memory
{
    class SE_API LinearAllocator final : public IAllocator
    {
    protected:
        void* m_current = nullptr;

    public:
        LinearAllocator(std::size_t size);
        LinearAllocator(const LinearAllocator&) = delete;
        ~LinearAllocator();

        void    Init() override;
        void*   Allocate(std::size_t size, u8 alignment) override;
        void    Free(void* p) override;
        void    Reset() override;
    };
}