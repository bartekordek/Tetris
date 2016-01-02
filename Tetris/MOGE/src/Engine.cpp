#include "Engine.h"
namespace MOGE
{
	MOGE::~MOGE()
	{
		//for each ( auto object in mObjects )
		//{
		//	delete object.second;
		//}

		for( std::unordered_map< String, Node* >::iterator it = mObjects.begin(); it != mObjects.end(); ++it )
		{
			delete it->second;
		}
	}
}