#ifndef __GAME_Z__
#define __GAME_Z__

class CGame
{
public:
	static CGame* Instance();
	static void Destroy();

	void Initialize();
	void MainLoop();

private:
	CGame();
	
	bool m_roundInProgress;

	static CGame* s_instance;

};

#endif