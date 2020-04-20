#include "IAllocator.h"

#include <cstdlib>

SimpleEngine::Core::Memory::IAllocator::IAllocator(const std::size_t totalSize)
{
    m_totalSize = totalSize;
}

SimpleEngine::Core::Memory::IAllocator::~IAllocator()
{
    if(m_allocations_num != 0 || m_used != 0)
    {
        // TODO (Nikita): Show some logs about memory leaks.
    }

    if(m_start != nullptr)
    {
        free(m_start);
        m_start = nullptr;
    }

    m_totalSize = 0;
}