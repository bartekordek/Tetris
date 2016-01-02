#include "Singleton.h"

//template<typename Type>
//Singleton<Type>::~Singleton()
//{
//
//}

template<typename Type>
Type& Singleton<Type>::Instance()
{
	static Type mInstance;
	return mInstance;
}

template<typename Type>
Singleton<Type>::Singleton()
{

}
