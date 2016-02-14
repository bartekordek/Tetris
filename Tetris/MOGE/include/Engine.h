#pragma once

#include "GeneralUtilities.h"
#include "SDL/SDL.h"
#include "Node.h"
#include <unordered_map>

namespace MOGE
{

	class MOGE: public Singleton<MOGE>
	{
	public:
		MOGE( void );
		static void Initialize( const Size& size = Size( 800, 600 ) );
		virtual ~MOGE();

		void AddObject( const Path& filePath, const Position& position = Position() );
		void AddObject( NodePtr& node );

	protected:
	private:
		void CreateScreen( const Size& size );
		void StartMainLoop();
		void StopMainLoop();
		void QueueFrame();
		void Render( Node& node );

		NodePtr mScreenBuffor;
		UnorderedMap< std::string, NodePtr> mRenderableObjects;
		Mutex mListMutex;
		Thread mainLoop;
	};
}