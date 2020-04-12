//#pragma once
//#ifndef __EXPLOSION_MANAGER__
//#define __EXPLOSION_MANAGER__
//#include <list>
//#include "Explosion.h"
//
///* Singleton */
//class ExplosionManager
//{
//public:
//	static ExplosionManager* Instance()
//	{
//		if (s_pInstance == nullptr)
//		{
//			s_pInstance = new ExplosionManager();
//			return s_pInstance;
//		}
//		return s_pInstance;
//	}
//
//	Explosion* getExplosion();
//
//	void update();
//	void draw();
//
//private:
//	ExplosionManager();
//	~ExplosionManager();
//
//	void m_buildExplosionPool();
//
//	int m_explosionNumber;
//	std::list<Explosion*> m_pExplosionPool;
//
//	static ExplosionManager* s_pInstance;
//};
//
//#endif /* defined (__EXPLOSION_MANAGER__) */