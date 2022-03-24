#pragma once
#include "DXUT.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef D3DXVECTOR3 vec3;
typedef D3DXVECTOR2 vec2;
typedef D3DXCOLOR color;

#define ScreenWidth 1280
#define ScreenHeight 720

#include "Scene.h"
#include "Singleton.h"
#include "Director.h"
#include "Node.h"
#include "Texture.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Camera.h"
#include "Font.h"

#include "MenuScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

#include "Player.h"
#include "Stage.h"
#include "Item.h"
