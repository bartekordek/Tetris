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
		static Type sInstance;
		return sInstance;
	}

protected:

private:
	Singleton( const Singleton& singleton ) = delete;
	void operator=( const Singleton& singleton ) = delete;

};