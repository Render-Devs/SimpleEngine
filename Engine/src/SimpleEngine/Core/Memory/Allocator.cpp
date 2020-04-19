#include "Allocator.h"

SimpleEngine::Core::Memory::Allocator::Allocator(const std::size_t size)
{
    m_size = size;
    m_used = 0;
}

SimpleEngine::Core::Memory::Allocator::~Allocator()
{
    m_size = 0;
}