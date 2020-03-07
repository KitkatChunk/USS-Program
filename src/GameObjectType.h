#pragma once
#ifndef __GAME_OBJECT_TYPE__
#define __GAME_OBJECT_TYPE__

enum GameObjectType {
	NONE = -1,
	MINE,
	PLAYER,
	BULLET,
	ENEMY,
	BACKGROUND,
	START_BUTTON,
	RESET_BUTTON,
	QUIT_BUTTON,
	NUM_OF_TYPES
};
#endif /* defined (__GAME_OBJECT_TYPE__)*/
