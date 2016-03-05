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

	static void Destroy()
	{
		delete mInstance;
	}

protected:

private:
	Singleton( const Singleton& singleton ) = delete;
	void operator=( const Singleton& singleton ) = delete;

};