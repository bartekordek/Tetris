#pragma once

template<typename Type> class Singleton
{
public:
	Singleton()
	{
		
	}

	static Type& Instance()
	{
		static Type mInstance;
		return mInstance;
	}

protected:
private:
	Singleton( const Singleton& singleton ) = delete;
	
	void operator=( const Singleton& singleton ) = delete;
};