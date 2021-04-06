#include "Menu.h"
#include"GInput.h"
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>
Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &spriteMenu);
	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/Racing background.jpg", &texture_menu);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 35, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Mv Boli", &menu_font);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Mv Boli", &enter_font);

	menuPosition = {0,0,0 };

	menuRect.left = 380;
	menuRect.top = 360;
	menuRect.right = 100;
	menuRect.bottom = 100;

	enterRect.left = 638;
	enterRect.top = 363;
	enterRect.right = 100;
	enterRect.bottom = 100;

}

void Menu::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_RETURN)) {
		GameStateManager::getInstance()->changeGameState(GameStateManager::USERGUIDE);
	}

}

void Menu::fixedUpdate()
{
}

void Menu::draw()
{
	spriteMenu->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMatrixTransformation2D(&matMenu, NULL, 0.0, NULL, NULL, NULL, NULL);
	spriteMenu->SetTransform(&matMenu);
	spriteMenu->Draw(texture_menu, NULL, NULL, &menuPosition, D3DCOLOR_XRGB(255, 255, 255));

	menu_font->DrawText(spriteMenu, "Start Game", -1, &menuRect, DT_NOCLIP | DT_CENTER , D3DCOLOR_XRGB(255, 145, 1));
	enter_font->DrawText(spriteMenu, "[ENTER]", -1, &enterRect, DT_NOCLIP | DT_CENTER, D3DCOLOR_XRGB(255, 95, 0));

	spriteMenu->End();
}

void Menu::release()
{
	texture_menu->Release();
	texture_menu = NULL;

	menu_font->Release();
	menu_font = NULL;

	enter_font->Release();
	enter_font = NULL;
}
