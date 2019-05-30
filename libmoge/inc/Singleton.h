#pragma once

template<typename Type> 
class Singleton
{
public:
    Singleton()
    {
    }

    virtual ~Singleton()
    {
    }

    static Type& Instance()
    {
        if( nullptr == singletonInstance )
        {
            singletonInstance = new Type();
        }
        return *singletonInstance;
    }

    static Type* instancePtr()
    {
        if( nullptr == singletonInstance )
        {
            singletonInstance = new Type();
        }
        return singletonInstance;
    }

    static void destroy()
    {
        delete singletonInstance;
        singletonInstance = nullptr;
    }

protected:

private:
    Singleton( const Singleton& singleton ) = delete;
    void operator=( const Singleton& singleton ) = delete;
    static Type* singletonInstance;
};

template<typename Type>
Type* Singleton<Type>::singletonInstance = nullptr;