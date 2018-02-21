#include "IKeyConcrete.hpp"

using namespace Moge;

IKeyConcrete::IKeyConcrete()
{

}

IKeyConcrete::IKeyConcrete( const IKeyConcrete& r ):
    m_key( r.m_key )
{

}

IKeyConcrete::~IKeyConcrete()
{

}

IKeyConcrete& IKeyConcrete::operator=( const IKeyConcrete& r )
{
    if( &r != this )
    {
        this->m_key = r.m_key;
    }
    return *this;
}

const std::string& IKeyConcrete::getKeyName()const
{
    return m_key->getKeyName();
}

const bool IKeyConcrete::getKeyIsDown()const
{
    return m_key->getKeyIsDown();
}

void IKeyConcrete::setSDLKey( SDL2W::IKey* key )
{
    this->m_key = key;
}