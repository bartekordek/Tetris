#include "IKeyConcrete.hpp"

using namespace Moge;

IKeyConcrete::IKeyConcrete()
{

}

IKeyConcrete::~IKeyConcrete()
{

}

void IKeyConcrete::setKeyName( const std::string& keyName )
{
    m_key->setKeyName( keyName );
}

const std::string& IKeyConcrete::getKeyName()const
{
    return m_key->getKeyName();
}

const bool IKeyConcrete::getKeyIsDown()const
{
    return m_key->getKeyIsDown();
}

void IKeyConcrete::setKeyIsDown( const bool isDown )
{
    m_key->setKeyIsDown( isDown );
}

void IKeyConcrete::setSDLKey( SDL2W::IKey* key )
{
    this->m_key = key;
}