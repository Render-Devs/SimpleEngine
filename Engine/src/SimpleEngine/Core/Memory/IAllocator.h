#pragma once

#include "SimpleEngine/Core/Core.h"

#include <cstddef>

namespace SimpleEngine::Core::Memory
{
    const u8 DEFAULT_WORD_SIZE = 4;

    class IAllocator
    {
    protected:
        void* m_start                   = nullptr;
        std::size_t m_totalSize         = 0;
        std::size_t m_used              = 0;
        u64         m_allocations_num   = 0;

    public:
        IAllocator(const std::size_t totalSize);
        virtual ~IAllocator();

        virtual void    Init() = 0;
        virtual void*   Allocate(const std::size_t size, const u8 alignment = DEFAULT_WORD_SIZE) = 0;
        virtual void    Free(void* p) = 0;
        virtual void    Reset() = 0;

        const void*     GetStart()          const { return m_start; }
        std::size_t     GetSize()           const { return m_totalSize; }
        std::size_t     GetUsedMemory()     const { return m_used; }
        std::size_t     GetAllocationsNum() const { return m_allocations_num; }
    };

    inline void* AlignForward(const void* address, u8 alignment)
    {
        return (void*) (
            (reinterpret_cast<uptr>(address) + static_cast<uptr>(alignment - 1)) &
            (static_cast<uptr>(~(alignment - 1)))
            );
    }

    inline u8 AlignForwardAdjustment(const void* address, u8 alignment)
    {
        u8 adjustment = alignment - (reinterpret_cast<uptr>(address) & static_cast<uptr>(alignment - 1));

        if(adjustment == alignment)
        {
            return 0;
        }

        return adjustment;
    }

    inline u8 AlignForwardAdjustmentWithHeader(const void* address, u8 alignment, u8 headerSize)
    {
        u8 adjustment = AlignForwardAdjustment(address, alignment);
        u8 neededSpace = headerSize;

        if(adjustment < headerSize)
        {
            neededSpace -= adjustment;

            adjustment += alignment * (neededSpace / alignment);

            if(neededSpace % alignment > 0)
            {
                adjustment += alignment;
            }
        }

        return adjustment;
    }
}