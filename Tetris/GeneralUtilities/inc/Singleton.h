#pragma once

template<typename Type> class Singleton
{
public:
	static Type& Instance();
protected:
private:
	Singleton();
	Singleton( const Singleton& singleton ) = delete;
	void operator=( const Singleton& singleton ) = delete;
};