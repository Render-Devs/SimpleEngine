#include "LinearAllocator.h"

#include <cstdlib>

SimpleEngine::Core::Memory::LinearAllocator::LinearAllocator(std::size_t size) : IAllocator(size)
{
}

SimpleEngine::Core::Memory::LinearAllocator::~LinearAllocator()
{
    if(m_start != nullptr)
    {
        free(m_start);
        m_start = nullptr;
    }
}

void SimpleEngine::Core::Memory::LinearAllocator::Init()
{
    if(m_start != nullptr)
    {
        free(m_start);
    }

    m_start = malloc(m_totalSize);
    m_current = m_start;
}

void* SimpleEngine::Core::Memory::LinearAllocator::Allocate(std::size_t size, u8 alignment)
{
    u8 adjustment = alignForwardAdjustment(m_current, alignment);

    if (m_used + adjustment + size > m_totalSize) return nullptr;

    uptr alignedAddress = (uptr)m_current + adjustment;
    m_current = (void*)(alignedAddress + size);
    m_used += size + adjustment;
    m_allocations_num++;

    return (void*)alignedAddress;
}

void SimpleEngine::Core::Memory::LinearAllocator::Free(void* p)
{
}

void SimpleEngine::Core::Memory::LinearAllocator::Reset()
{
    m_allocations_num = 0;
    m_used = 0;
    m_current = m_start;
}
