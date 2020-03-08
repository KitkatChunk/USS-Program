#pragma once
#ifndef __SPLASH_SCENE__
#define __SPLASH_SCENE__

#include "Scene.h"
#include "Label.h"

class SplashScene : public Scene
{
	public:
	SplashScene();
	~SplashScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	void transition();

	glm::vec2 getMousePosition();

	private:
	int count;
	double seconds;

	glm::vec2 m_mousePosition;
};
#endif /* defined (__WIN_SCENE__) */
