#include "DXUT.h"
#include "Include.h"

void GameScene::Init()
{
	cout << "°ÔÀÓ¾À" << endl;
	Stage::GetIns()->StageInit();
	PlayerMNG::GetIns()->CreatePlayer();
	ItemMNG::GetIns()->CreateItem();
	TIME::score = 0;
}

void GameScene::Update()
{
	Stage::GetIns()->StageUpdate();
}

void GameScene::OnExit()
{
	Stage::GetIns()->StageExit();
	PlayerMNG::GetIns()->DeletePlayer();
	ItemMNG::GetIns()->DeleteItem();
}
