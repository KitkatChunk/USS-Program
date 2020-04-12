//#include "ExplosionManager.h"
//
//ExplosionManager* ExplosionManager::s_pInstance = nullptr;
//
//Explosion* ExplosionManager::getExplosion()
//{
//	const auto explosion = m_pExplosionPool.front();
//	explosion->setActive();
//	m_pExplosionPool.pop_front();
//	m_pExplosionPool.push_back(explosion);
//	return explosion;
//}
//
//void ExplosionManager::update()
//{
//	for (auto explosion : m_pExplosionPool)
//	{
//		if (explosion->isActive())
//		{
//			explosion->update();
//		}
//	}
//}
//
//void ExplosionManager::draw()
//{
//	for (auto explosion : m_pExplosionPool)
//	{
//		if (explosion->isActive())
//		{
//			explosion->draw();
//		}
//	}
//}
//
//ExplosionManager::ExplosionManager() :m_explosionNumber(20)
//{
//	m_buildExplosionPool();
//}
//
//ExplosionManager::~ExplosionManager()
//= default;
//
//void ExplosionManager::m_buildExplosionPool()
//{
//	// create the empty object pool structure
//	m_pExplosionPool = std::list<Explosion*>();
//
//	for (int count = 0; count < m_explosionNumber; ++count)
//	{
//		m_pExplosionPool.push_back(new Explosion());
//	}
//}
