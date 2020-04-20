#pragma once

#include "SimpleEngine/Core/Core.h"

#include <cstddef>

namespace SimpleEngine::Core::Memory
{
    class Allocator
    {
    public:
        static const u8 DEFAULT_WORD_SIZE = 4;

    protected:
        void*       m_start             = nullptr;
        std::size_t m_totalSize         = 0;
        std::size_t m_used              = 0;
        int         m_allocations_num   = 0;

    public:
        Allocator(const std::size_t totalSize);
        virtual ~Allocator();

        virtual void    Init() = 0;
        virtual void*   Allocate(const std::size_t size, const u8 alignment = DEFAULT_WORD_SIZE) = 0;
        virtual void    Free(void* p) = 0;

        void*       getStart() const { return m_start; }
        std::size_t getSize() const { return m_totalSize; }
        std::size_t getUsedMemory() const { return m_used; }
        std::size_t getAllocationsNum() const { return m_allocations_num; }
    };

    inline void* alignForward(const void* address, u8 alignment)
    {
        return (void*) (
            (reinterpret_cast<uptr>(address) + static_cast<uptr>(alignment - 1)) &
            (static_cast<uptr>(~(alignment - 1)))
            );
    }

    inline u8 alignForwardAdjustment(const void* address, u8 alignment)
    {
        u8 adjustment = alignment - (reinterpret_cast<uptr>(address) & static_cast<uptr>(alignment - 1));

        if(adjustment == alignment)
        {
            return 0;
        }

        return adjustment;
    }
}