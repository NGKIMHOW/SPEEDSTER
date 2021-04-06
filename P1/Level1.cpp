#include "Level1.h"
#include"GInput.h"
#include"physic.h"
#include <string>
#include<iostream>
#include "GameStateManager.h"
#include<d3d9.h>
#include<d3dx9.h>

using namespace std;

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::init()
{
	//	Create sprite. Study the documentation. 	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);

	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	   
	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/newroadbg.png", &background_texture);

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/oricoin.png", &coin_texture);

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/takumi.png", &takumi_texture);

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/clock.png", &clock_texture);

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/coinIcon.png", &coinIcon_texture);

	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/level1font.png", &level1_texture);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/blurbg.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &blurbg_texture);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/Maincar.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_car);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/rock.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_rock);

	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "img/block.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255),
		NULL, NULL, &texture_block);


	D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "img/finish.jpg", &finish_texture);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 20, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &timeRemaining_font);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 20, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &coinCollected_font);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 35, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &time_font);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 21, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &driver_font);

	D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 35, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &coinCount_font);

	rockSize.x = 30;
	rockSize.y = 30;

	rock_rect.top = 0;
	rock_rect.left = 0;
	rock_rect.bottom = 30;
	rock_rect.right = 30;

	finishSize.x = 240;
	finishSize.y = 110;

	finishRect.top = 0;
	finishRect.left = 0;
	finishRect.bottom = finishRect.top + finishSize.y;
	finishRect.right = finishRect.left + finishSize.x;

	finish_position.x = 30;
	finish_position.y = -30000;

	timeRect.left = 0;
	timeRect.top = 0;
	timeRect.right = 20;
	timeRect.bottom = 100;

	rock_position[0].x = 100;
	rock_position[0].y = -1000;

	rock_position[1].x = 190;
	rock_position[1].y = -1500;

	rock_position[2].x = 100;
	rock_position[2].y = -1800;

	rock_position[3].x = 190;
	rock_position[3].y = -2300;

	rock_position[4].x = 100;
	rock_position[4].y = -3000;

	rock_position[5].x = 190;
	rock_position[5].y = -3500;

	rock_position[6].x = 190;
	rock_position[6].y = -5000;

	rock_position[7].x = 100;
	rock_position[7].y = -7000;

	rock_position[8].x = 190;
	rock_position[8].y = -9000;

	rock_position[9].x = 190;
	rock_position[9].y = -11000;

	rock_position[10].x = 100;
	rock_position[10].y = -13000;

	rock_position[11].x = 100;
	rock_position[11].y = -15000;

	blockSize.x = 30;
	blockSize.y = 30;

	block_rect.top = 0;
	block_rect.left = 0;
	block_rect.bottom = 35;
	block_rect.right = 75;

	block_position[0].x = 65;
	block_position[0].y = -4000;

	block_position[1].x = 180;
	block_position[1].y = -6000;

	block_position[2].x = 65;
	block_position[2].y = -8000;

	block_position[3].x = 180;
	block_position[3].y = -10000;

	block_position[4].x = 180;
	block_position[4].y = -12000;

	block_position[5].x = 65;
	block_position[5].y = -14000;

	block_position[6].x = 65;
	block_position[6].y = -18000;

	block_position[7].x = 180;
	block_position[7].y = -21000;

	block_position[8].x = 180;
	block_position[8].y = -24000;

	block_position[9].x = 65;
	block_position[9].y = -28000;

	//block_position[10].x = 70;
	//block_position[10].y = -40000;

	//block_position[11].x = 175;
	//block_position[11].y = -45000;

	//width = 400/ 4 = 100
	//Height = 450 / 3 = 150

	mainCarSize.x = 100;
	mainCarSize.y = 150;

	mainCarCurrentFrame = 0;

	car_spriteRect.top = 7;
	car_spriteRect.left = 14;
	car_spriteRect.bottom = car_spriteRect.top + mainCarSize.y; 
	car_spriteRect.right = car_spriteRect.left + mainCarSize.x; 

	animationTimer = 0;
	animationRate = 0.3f / 4;
	animationRow = 0;
	
	scaling.x = 0.8f;
	scaling.y = 0.8f;

	mainCar_position.x = 110;
	mainCar_position.y = 300;

	background_position[0].x = 0;
	background_position[0].y = -1024 + 600;

	background_position[1].x = 0;
	background_position[1].y = -1024 + 600 - 1024;

	blurbg_position.x = 23;
	blurbg_position.y = 190;

	countdownTimer_position.x = 355;
	countdownTimer_position.y = 185;

	coin_rect.left = 0;
	coin_rect.top = 0;
	coin_rect.right = 26 ;
	coin_rect.bottom = 130 ;
	
	coin_position[2].x = 100;
	coin_position[2].y = -26000;

	coin_position[3].x = 100;
	coin_position[3].y = -3800;

	coin_position[4].x = 200;
	coin_position[4].y = -27500;

	coin_position[5].x = 200;
	coin_position[5].y = -5200;

	coin_position[6].x = 200;
	coin_position[6].y = -8000;

	coin_position[7].x = 200;
	coin_position[7].y = -10100;

	coin_position[1].x = 200;
	coin_position[1].y = -16000;

    coin_position[0].x = 100;
	coin_position[0].y = -17500;

	coin_position[8].x = 200;
	coin_position[8].y = -20500;

	coin_animation_rate = (1 / 6.0);
	coin_frame = 0;
	coin_timer = 0;

	coinCount_position.x = 370;
	coinCount_position.y = 330;

	coinCollectScore = 0;

	coinScaling.x = 0.3f;
	coinScaling.y = 0.3f;

	coinIcon_position.x = 318;
	coinIcon_position.y = 290;

	coinIconScaling.x = 0.45f;
	coinIconScaling.y = 0.5f;

	clock_rect.left = 127;
	clock_rect.top = 97;
	clock_rect.right = 384;
	clock_rect.bottom = 4120;

	clockScaling.x = 0.07f;
	clockScaling.y = 0.08f;

	clock_position.x = 313;
	clock_position.y = 140;

	level1_rect.left = 0;
	level1_rect.top = 0;
	level1_rect.right = 124;
	level1_rect.bottom = 60;

	level1_position.x = 315;
	level1_position.y = 1;

	level1Scaling.x = 0.9f;
	level1Scaling.y = 0.6f;

	timeRemaining_position.x = 350;
	timeRemaining_position.y = 143;

	coinCollected_position.x = 350;
	coinCollected_position.y = 287;

	takumiRect.left = 0;
	takumiRect.top = 0;
	takumiRect.right = 120;
	takumiRect.bottom = 128;

	takumi_position.x = 315;
	takumi_position.y = 480;

	driverFont_position.x = 315;
	driverFont_position.y = 460;

	isMainCarMoving = false;
	speed = (0.9f / animationRate) * 60;
	direction.x = 0;
	direction.y = 1;

	countDownTimer = 60;

	bgLength = 30000;
}

void Level1::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_UP))
	{
		cout << "UP" << endl;
		startCount = true;
		animationRow = 0;
		isMainCarMoving = true;
		direction.x = 0;
		direction.y = -1;
		startDrawing = false;

	}
	
	else if (GInput::getInstance()->isKeyDown(DIK_LEFT)) {
		cout << "LEFT" << endl;
		animationRow = 1;
		isMainCarMoving = true;
		direction.x = -0.8;
		direction.y = 0;
	}

	else if (GInput::getInstance()->isKeyDown(DIK_RIGHT)) {
		cout << "RIGHT" << endl;
		animationRow = 2;
		isMainCarMoving = true;
		direction.x = 0.8;
		direction.y = 0;
	}
	else
	{
		isMainCarMoving = false;
	}
	
}

void Level1::fixedUpdate() 
{
	for (int i = 0; i < 12; i++) 
	{
		if (Physic::getInstance()->checkRockCollision(mainCar_position, car_spriteRect, rock_position[i], rock_rect)) {
			/*isMainCarMoving = false;*/
			D3DXVECTOR2 velocity = direction * (speed / 60.0f);
			mainCar_position -= velocity;
			velocity = -velocity;
			
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (Physic::getInstance()->checkCollision(mainCar_position, car_spriteRect, block_position[i], block_rect)) {
			/*isMainCarMoving = false;*/
			D3DXVECTOR2 velocity = direction * (speed / 60.0f);
			mainCar_position -= velocity;
			velocity = -velocity;
		}
	}

	if (startCount) {
		countDownTimer -= (1 / 60.0f);
	}

	for (int i = 0; i < 9; i++) {
		if (Physic::getInstance()->checkCollision(mainCar_position, car_spriteRect, coin_position[i], coin_rect)) {
			coinCrash == true;
			coin_position[i].x = -200;
			coinCollectScore++;
		}
	}
	

	if (isMainCarMoving) {
		animationTimer += 1 / 60.0f;
		D3DXVECTOR2 velocity = direction * (speed / 60.0f);
		mainCar_position += velocity;
	}
	

	if (animationTimer >= animationRate) {
		animationTimer -= animationRate;
		mainCarCurrentFrame++;
		mainCarCurrentFrame %= 4;
	}

	coin_timer += (1 / 60.0);
	if (coin_timer >= coin_animation_rate) {
		coin_timer -= coin_animation_rate;
		coin_frame++;
		coin_frame %= 6;

		coin_rect.left = coin_frame * 85;
		coin_rect.right = coin_rect.left + 85;
	}

	car_spriteRect.top = animationRow * mainCarSize.y;
	car_spriteRect.left = mainCarSize.x * mainCarCurrentFrame;
	car_spriteRect.bottom = car_spriteRect.top + mainCarSize.y;
	car_spriteRect.right = car_spriteRect.left + mainCarSize.x;
	
	if ((Physic::getInstance()->checkRockCollision(mainCar_position, car_spriteRect, finish_position, finishRect)))
	{
		if (coinCollectScore >= 6) {
			GameStateManager::getInstance()->changeGameState(GameStateManager::YOUWIN);
		}
		else
			GameStateManager::getInstance()->changeGameState(GameStateManager::GAMEOVERCOIN);
	}

}


void Level1::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	float backPos = (600 / 2) - mainCar_position.y;
	backPos = min(max(backPos, 300 - 150), bgLength);

	for (int i = 0; i < 2; i++) {
		D3DXVECTOR2 temp = background_position[i];
		temp.y += (backPos - 300 + 36);

		if (temp.y >= 600) {
			background_position[i].y -= 2048;
		}
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &temp);
		sprite->SetTransform(&mat);
		sprite->Draw(background_texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}
	D3DXVECTOR2 carOnScreen = mainCar_position;
	carOnScreen.y = (mainCar_position.y) + backPos;


	if (startDrawing == true) {
		D3DXVECTOR2 blurbg = blurbg_position;
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &blurbg);
		sprite->SetTransform(&mat);
		sprite->Draw(blurbg_texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &clockScaling, NULL, NULL, &clock_position);
	sprite->SetTransform(&mat);
	sprite->Draw(clock_texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &level1Scaling, NULL, NULL, &level1_position);
	sprite->SetTransform(&mat);
	sprite->Draw(level1_texture, &level1_rect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &timeRemaining_position);
	sprite->SetTransform(&mat);
	string timeRemain = "Time\nRemaining";
	timeRemaining_font->DrawText(sprite, timeRemain.c_str(), -1, NULL, DT_NOCLIP, D3DCOLOR_XRGB(250, 250, 250));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &coinCollected_position);
	sprite->SetTransform(&mat);
	string coinCollect = "Coin\nCollected";
	coinCollected_font->DrawText(sprite, coinCollect.c_str(), -1, NULL, DT_NOCLIP, D3DCOLOR_XRGB(250, 250, 250));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &driverFont_position);
	sprite->SetTransform(&mat);
	string driver = "The DRIVER";
	driver_font->DrawText(sprite, driver.c_str(), -1, NULL, DT_NOCLIP, D3DCOLOR_XRGB(250, 250, 250));

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &takumi_position);
	sprite->SetTransform(&mat);
	sprite->Draw(takumi_texture, &takumiRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &carOnScreen);
	sprite->SetTransform(&mat);
	sprite->Draw(texture_car, &car_spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	D3DXVECTOR2 timer = countdownTimer_position;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &timer);
	sprite->SetTransform(&mat);
	string timeStr = to_string(countDownTimer);

	if (countDownTimer > 0) {
		if (countDownTimer > 10) {
			time_font->DrawText(sprite, timeStr.c_str(), -1, &timeRect, DT_NOCLIP, D3DCOLOR_XRGB(250, 250, 250));
		}
		else
			time_font->DrawText(sprite, timeStr.c_str(), -1, &timeRect, DT_NOCLIP, D3DCOLOR_XRGB(250, 0, 0));
	}
	else 
	{
		GameStateManager::getInstance()->changeGameState(GameStateManager::GAMEOVER);
	}

	for (int i = 0; i < 10; i++) {
		D3DXVECTOR2 blockOnScreen = block_position[i];
		blockOnScreen.y = (block_position[i].y) + backPos;
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &blockOnScreen);
		sprite->SetTransform(&mat);
		sprite->Draw(texture_block, &block_rect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}

	for (int i = 0; i < 12; i++) {
		D3DXVECTOR2 rockOnScreen = rock_position[i];
		rockOnScreen.y = (rock_position[i].y) + backPos;
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &rockOnScreen);
		sprite->SetTransform(&mat);
		sprite->Draw(texture_rock, &rock_rect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}

	D3DXVECTOR2 OnScreen = finish_position;
	OnScreen.y = (finish_position.y) + backPos;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &OnScreen);
	sprite->SetTransform(&mat);
	sprite->Draw(finish_texture, &finishRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));


	if (coinCrash == false) {
		for (int i = 0; i < 9; i++) {
			D3DXVECTOR2 coinOnScreen = coin_position[i];
			coinOnScreen.y = (coin_position[i].y) + backPos;
			D3DXMatrixTransformation2D(&mat, NULL, 0.0, &coinScaling, NULL, NULL, &coinOnScreen);
			sprite->SetTransform(&mat);
			sprite->Draw(coin_texture, &coin_rect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
		}
	}

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &coinIconScaling, NULL, NULL, &coinIcon_position);
	sprite->SetTransform(&mat);
	sprite->Draw(coinIcon_texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	
	if (coinCollectScore >= 6) {
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &coinCount_position);
		sprite->SetTransform(&mat);
		string coinCount = to_string(coinCollectScore) + " / 6";
		coinCount_font->DrawText(sprite, coinCount.c_str(), -1, &timeRect, DT_NOCLIP, D3DCOLOR_XRGB(0, 250, 0));
	}
	else {
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &coinCount_position);
		sprite->SetTransform(&mat);
		string coinCount = to_string(coinCollectScore) + " / 6";
		coinCount_font->DrawText(sprite, coinCount.c_str(), -1, &timeRect, DT_NOCLIP, D3DCOLOR_XRGB(250, 250, 250));
	}


	sprite->End();
}
void Level1::release()
{
	sprite->Release();
	sprite = NULL;

	background_texture->Release();
	background_texture = NULL;

	blurbg_texture->Release();
	blurbg_texture = NULL;

	texture_car->Release();
	texture_car = NULL;

	texture_rock->Release();
	texture_rock = NULL;

	texture_block->Release();
	texture_block = NULL;

	finish_texture->Release();
	finish_texture = NULL;

	coin_texture->Release();
	coin_texture = NULL;

	coinCount_font->Release();
	coinCount_font = NULL;

	level1_texture->Release();
	level1_texture = NULL;

	timeRemaining_font->Release();
	timeRemaining_font = NULL;

	coinIcon_texture->Release();

	coinCollected_font->Release();

	takumi_texture->Release();

}
