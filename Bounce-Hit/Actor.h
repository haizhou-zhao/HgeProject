#pragma once

#include "xvec.h"
#include "hge.h"
#include "hgesprite.h"
#include "hgeparticle.h"

class Actor
{
	public:

	float speed;
	float friction;

	XVec2f pos;
	XVec2f acc;

	// the appearance of the actor
	hgeSprite* spr;
	hgeSprite* spt;
	hgeParticleSystem* par;
	
	Actor();

	Actor(float speed_in, float friction_in, float pos_x_in, float pos_y_in);

	~Actor();

	void accerate(float dt, XVec2f movement);

	void move();

	int edgeCollideBounce(int x_max, int y_max, int x_min, int y_min);

	void updateParticle(float dt);
};