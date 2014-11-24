#include "Actor.h"

Actor::Actor() : speed(0), friction(0), pos(XVec2f(0, 0))
{

}

Actor::Actor(float speed_in, float friction_in, float pos_x_in, float pos_y_in) :
speed(speed_in),
friction(friction_in),
pos(XVec2f(pos_x_in, pos_y_in))
{

}

void Actor::accerate(float dt, XVec2f movement)
{
	this->acc += speed*dt*movement;
}

void Actor::move()
{
	acc *= friction;
	pos += acc;
}

//helper function for edgeCollideBounce
void reflect(XVec2f& vec, char direct, float value)
{
	switch (direct)
	{
		case 'x':
			vec.x() = 2*value - vec.x();
			break;
		case 'y':
			vec.y() = 2*value - vec.y();
			break;
		default:
			break;
	}
}

int Actor::edgeCollideBounce(int x_max, int y_max, int x_min, int y_min)
{
	if (pos.x() > x_max)
	{
		reflect(pos, 'x', x_max);
		acc.x() *= -1;
		return 1;
	}
	if (pos.x() < x_min)
	{
		reflect(pos, 'x', x_min);
		acc.x() *= -1;
		return 1;
	}
	if (pos.y() > y_max)
	{
		reflect(pos, 'y', y_max);
		acc.y() *= -1;
		return 1;
	}
	if (pos.y() < y_min)
	{
		reflect(pos, 'y', y_min);
		acc.y() *= -1;
		return 1;
	}

	return 0;
}

void Actor::updateParticle(float dt)
{
	par->info.nEmission = (int)(acc.dot()) * 2;
	par->MoveTo(pos.x(), pos.y());
	par->Update(dt);
}

Actor::~Actor()
{

}