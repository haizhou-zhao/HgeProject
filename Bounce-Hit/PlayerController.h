#pragma once

#include "hge.h"
#include "xvec.h"
#include <stdio.h>
#define DEFAULT_SPEED		90
#define DEFAULT_FRICTION	0.98

class Actor;

class PlayerController
{
	public:

	float dt;
	Actor* actor;

	PlayerController();

	PlayerController(Actor* , float );

	bool processInput(HGE*);

};