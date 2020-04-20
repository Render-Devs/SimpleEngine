#include "Allocator.h"

SimpleEngine::Core::Memory::Allocator::Allocator(const std::size_t totalSize)
{
    m_totalSize = totalSize;
}

SimpleEngine::Core::Memory::Allocator::~Allocator()
{
    if(m_allocations_num != 0 || m_used != 0)
    {
        // TODO (Nikita): Show some logs about memory leaks.
    }

    m_start = nullptr;
    m_totalSize = 0;
}