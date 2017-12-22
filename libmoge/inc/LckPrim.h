#pragma once
#include "MogeLib.h"
#include <mutex>
namespace Moge
{
    template <typename Type>
    class MogeLib_API LckPrim
    {
    public:
        LckPrim( void )
        {

        }

        explicit LckPrim( const Type& val )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            this->value = val;
        }

        LckPrim( const LckPrim<Type>& rvalue )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            this->value = rvalue.value;
        }

        virtual ~LckPrim()
        {
        }

        const Type& getVal()const
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            return this->value;
        }

        void setVal( const Type& val )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            this->value = val;
        }

        Type& operator++()
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            ++this->value;
            return this->value;
        }

        Type operator++( int )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            Type copy = this->value;
            ++this->value;
            return copy;
        }

        Type& operator--()
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            --this->value;
            return this->value;
        }

        Type operator--( int )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            Type copy = this->value;
            --this->value;
            return copy;
        }

        const bool operator==( const LckPrim<Type>& val )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            return this->value == val.value;
        }

        const bool operator==( const Type& val )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            return this->value == val;
        }

        operator Type()
        {
            return this->value;
        }

        LckPrim<Type>& operator=( const LckPrim<Type>& rvalue )
        {
            if( this != &rvalue )
            {
                std::lock_guard<std::mutex> lock( this->mtx );
                this->value = rvalue.value;
            }
            return *this;
        }

        LckPrim<Type>& operator=( const Type& right )
        {
            std::lock_guard<std::mutex> lock( this->mtx );
            this->value = right;
            return *this;
        }

    protected:
    private:
        std::mutex mtx;
        Type value = static_cast<Type>( 0 );
    };

    template <typename Type>
    const bool operator==( const Type& r, LckPrim<Type>&l )
    {
        return l == r;
    }
}