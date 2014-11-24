#include <windows.h>
#include "hge.h"
#include "hgefont.h"
#include "Actor.h"
#include "PlayerController.h"

struct GameData
{
	HEFFECT snd;
	HTEXTURE tex;
	hgeFont* fnt;
};

HGE* hge;
GameData* data;
Actor myActor(90.0f, 0.98f, 100, 100);
PlayerController myController;

void boom(HGE* , HEFFECT& , XVec2f& , XVec2f& );

bool FrameFunc();

bool RenderFunc();


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{	
#pragma region startup
	// Get HGE interface
	hge = hgeCreate(HGE_VERSION);

	// Set up log file, frame function, render function and window title
	hge->System_SetState(HGE_LOGFILE, "HgeProject.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGEPROJECT: Hit-Bounce");

	// Set up video mode
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
#pragma endregion startup

	if (hge->System_Initiate())
	{
#pragma region loadResource
		data = new GameData;
		// Load sound and texture
		data->snd = hge->Effect_Load("menu.wav");
		data->tex = hge->Texture_Load("particles.png");
		data->fnt = new hgeFont("font1.fnt");
		if (!data->snd || !data->tex || !data->fnt)
		{
			// If one of the data files is not found, display
			// an error message and shutdown.
			MessageBox(NULL, "Can't load one of the following files:\nMENU.WAV, PARTICLES.PNG, FONT1.FNT, FONT1.PNG, TRAIL.PSI", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
			return 0;
		}
#pragma endregion loadResource

#pragma region initActorController
		myActor.spr = new hgeSprite(data->tex, 96, 64, 32, 32);
		myActor.spr->SetColor(0xFFFFA000);
		myActor.spr->SetHotSpot(16, 16);

		myActor.spt = new hgeSprite(data->tex, 32, 32, 32, 32);
		myActor.spt->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		myActor.spt->SetHotSpot(16, 16);
		myActor.par = new hgeParticleSystem("trail.psi", myActor.spt);
		myActor.par->Fire();

		myController.actor = &myActor;
		myController.dt = hge->Timer_GetDelta();
#pragma endregion initActorController

		hge->System_Start();

#pragma region cleanup
		delete myActor.par;
		delete data->fnt;
		delete myActor.spt;
		delete myActor.spr;
		hge->Texture_Free(data->tex);
		hge->Effect_Free(data->snd);
		delete data;
#pragma endregion cleanup
	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}

void boom(XVec2f& pos, XVec2f& acc)
{
	int pan = int((pos.x() - 400) / 4);
	float pitch = acc.dot()*0.0005f + 0.2f;
	hge->Effect_PlayEx(data->snd, 100, pan, pitch);
}

bool FrameFunc()
{
	// Process keys && movement
	if (myController.processInput(hge))
	{
		return true;
	}

	myActor.move();

	// Do some collision detection
	if (myActor.edgeCollideBounce(784, 584, 16, 16))
	{
		boom(myActor.pos, myActor.acc);
	}

	myActor.updateParticle(myController.dt);

	return false;
}

bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	myActor.par->Render();
	myActor.spr->Render(myActor.pos.x(), myActor.pos.y());
	data->fnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d (constant)", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	hge->Gfx_EndScene();

	return false;
}