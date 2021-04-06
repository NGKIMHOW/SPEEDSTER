#include "GameOver.h"
#include"GInput.h"
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &spriteGameOver);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Game Over.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_GameOver);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "MV Boli", &GameOver_font);

	GameOverPosition = { -50,0,0 };

	GameOverRect.left = 50;
	GameOverRect.top = 290;
	GameOverRect.right = 100;
	GameOverRect.bottom = 100;
}

void GameOver::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_R)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::USERGUIDE);
	}

	else if (GInput::getInstance()->isKeyDown(DIK_M)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::MENU);
	}
	
}

void GameOver::fixedUpdate()
{
	
}

void GameOver::draw()
{
	spriteGameOver->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMatrixTransformation2D(&matGameOver, NULL, 0.0, NULL, NULL, NULL, NULL);
	spriteGameOver->SetTransform(&matGameOver);
	spriteGameOver->Draw(texture_GameOver, NULL, NULL, &GameOverPosition, D3DCOLOR_XRGB(255, 255, 255));

	GameOver_font->DrawText(spriteGameOver, "DID NOT REACH ON TIME !!", -1, &GameOverRect, DT_NOCLIP, D3DCOLOR_XRGB(250, 0, 0));

	spriteGameOver->End();
}

void GameOver::release()
{
	texture_GameOver->Release();
	texture_GameOver = NULL;

	GameOver_font->Release();
	GameOver_font = NULL;
}
