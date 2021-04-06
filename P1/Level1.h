#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include<d3d9.h>
#include<d3dx9.h>
class Level1 : public GameState
{
private:
	D3DXVECTOR3 vPosition;
	LPDIRECT3DTEXTURE9 background_texture;
	LPDIRECT3DTEXTURE9 blurbg_texture;
	LPDIRECT3DTEXTURE9 finish_texture;
	LPDIRECT3DTEXTURE9 texture_car;
	LPDIRECT3DTEXTURE9 texture_rock;
	LPDIRECT3DTEXTURE9 texture_block;
	LPDIRECT3DTEXTURE9 texture_countdownTimer;
	LPDIRECT3DTEXTURE9 coin_texture;
	LPDIRECT3DTEXTURE9 clock_texture;
	LPDIRECT3DTEXTURE9 level1_texture;
	LPDIRECT3DTEXTURE9 coinIcon_texture;
	LPDIRECT3DTEXTURE9 takumi_texture;
	LPD3DXFONT timeRemaining_font;
	LPD3DXFONT coinCollected_font;
	LPD3DXFONT time_font;
	LPD3DXFONT end_font;
	LPD3DXFONT coinCount_font;
	LPD3DXFONT driver_font;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	RECT finishRect;
	RECT timeRect;
	RECT endRect;
	RECT rock_rect;
	RECT truck_rect;
	RECT block_rect;
	RECT timer_rect;
	RECT coin_rect;
	RECT clock_rect;
	RECT level1_rect;
	RECT car_spriteRect;
	RECT takumiRect;
	D3DXVECTOR2 rock_position[12];
	D3DXVECTOR2 block_position[10];
	D3DXVECTOR2 background_position[2];
	D3DXVECTOR2 blurbg_position;
	D3DXVECTOR2 mainCar_position;
	D3DXVECTOR2 finish_position;
	D3DXVECTOR2 timer_position;
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 coinScaling;
	D3DXVECTOR2 clockScaling;
	D3DXVECTOR2 level1Scaling;
	D3DXVECTOR2 coinIconScaling;
	D3DXVECTOR2 direction;
	D3DXVECTOR2 mainCarSize;
	D3DXVECTOR2 rockSize;
	D3DXVECTOR2 finishSize;
	D3DXVECTOR2 blockSize;
	D3DXVECTOR2 countdownTimer_position;
	D3DXVECTOR2 timeRemaining_position;
	D3DXVECTOR2 coinCollected_position;
	D3DXVECTOR2 coin_position[9];
	D3DXVECTOR2 coinCount_position;
	D3DXVECTOR2 clock_position;
	D3DXVECTOR2 level1_position;
	D3DXVECTOR2 coinIcon_position;
	D3DXVECTOR2 takumi_position;
	D3DXVECTOR2 driverFont_position;

	int mainCarCurrentFrame;
	float animationRate;
	float animationTimer;
	int animationRow;
	bool isMainCarMoving;
	float speed;
	float countDownTimer;
	int distance;
	bool coinCrash = false;
	bool startCount = false;
	bool startDrawing = true;
	float bgLength;
	float coin_animation_rate;
	int coin_frame;
	float coin_timer;
	int coinCollectScore;



public: 
	Level1();
	~Level1();
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
	
};


