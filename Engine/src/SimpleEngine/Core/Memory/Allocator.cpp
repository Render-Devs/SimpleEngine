#include "Allocator.h"

SimpleEngine::Core::Memory::Allocator::Allocator(const std::size_t totalSize)
{
    m_totalSize = totalSize;
    m_used = 0;
    m_peak = 0;
}

SimpleEngine::Core::Memory::Allocator::~Allocator()
{
    m_totalSize = 0;
}