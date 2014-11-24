#include "PlayerController.h"
#include "Actor.h"

PlayerController::PlayerController() : dt(0), actor(nullptr)
{

}

PlayerController::PlayerController(Actor* actor_in, float dt_in) :
	actor(actor_in),
	dt(dt_in)
{

}

bool PlayerController::processInput(HGE* hge)
{
#define MOVE_UP_VEC		XVec2f(0, -1)
#define MOVE_DOWN_VEC	XVec2f(0, 1)
#define MOVE_LEFT_VEC	XVec2f(-1, 0)
#define MOVE_RIGHT_VEC	XVec2f(1, 0)

	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		return true;
	}
	if (hge->Input_GetKeyState(HGEK_W))
	{
		actor->accerate(dt, MOVE_UP_VEC);
	}
	if (hge->Input_GetKeyState(HGEK_A))
	{
		actor->accerate(dt, MOVE_LEFT_VEC);
	}
	if (hge->Input_GetKeyState(HGEK_S))
	{
		actor->accerate(dt, MOVE_DOWN_VEC);
	}
	if (hge->Input_GetKeyState(HGEK_D))
	{
		actor->accerate(dt, MOVE_RIGHT_VEC);
	}
	if (hge->Input_GetKeyState(HGEK_UP))
	{
		actor->speed += 10;
	}
	if (hge->Input_GetKeyState(HGEK_DOWN))
	{
		actor->speed -= 10;
	}

	return false;
}