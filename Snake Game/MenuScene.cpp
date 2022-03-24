#include "DXUT.h"
#include "Include.h"

void MenuScene::Create()
{
	test = new Sprite(L"Title.png");
	test->_pivot = { 0,0 };

	mouse = new Sprite(L"tail.png");

	button1 = new Sprite(L"Start.png");
	button2 = new Sprite(L"End.png");
	button3 = new Sprite(L"scoree.png");
	pannel = new Sprite(L"Panel.png");

	button1->_position = { 1000,450 };
	button2->_position = { 1000,600 };
	button3->_position = { 300,600 };
	pannel ->_position = { ScreenWidth/2,ScreenHeight/2 };

	button1->_scale = { 0.5,0.5 };
	button2->_scale = { 0.5,0.5 };
	button3->_scale = { 0.5,0.5 };
	pannel->_scale = { 1,4 };

	pannel->_visible = false;
	pannel->_color = color(0, 0, 0, 1);
	button3->_layer = 3;

	RankMNG::GetIns()->AddRank();
	RankMNG::GetIns()->Disable();
}

void MenuScene::sUpdate()
{
	RankMNG::GetIns()->LoadRank();
	mouse->_position = Director::GetIns()->GetMousePos();
		
	RECT r;
	if (Director::GetIns()->MouseDown())
	{
		if (IntersectRect(&r, &mouse->GetRect(), &button1->GetRect()))
		{
			Director::GetIns()->ChangeScene(new GameScene);
			return;
		}

		if (IntersectRect(&r, &mouse->GetRect(), &button2->GetRect()))
		{
			exit(0);
			return;
		}

		if (IntersectRect(&r, &mouse->GetRect(), &button3->GetRect()))
		{
			if (pannel->_visible == false)
			{
				pannel->_visible = true;
				RankMNG::GetIns()->Enable();
			}
			else
			{
				RankMNG::GetIns()->Disable();
				pannel->_visible = false;
			}
		}
	}
}

void MenuScene::Delete()
{
	delete test;
	delete mouse;
	delete button1;
	delete button2;
	delete button3;
	delete pannel;
	RankMNG::GetIns()->DeleteRank();
}

float MenuScene::SquareRoot(int n)
{
	float x = n;
	for(int i = 0 ; i < 2 ; i++)
	{
		x = (x + n / x) / 2.0f;
	}
	return x;
}

void MenuScene::Init()
{
	cout << "¸Þ´º¾À" << endl;

	Create();
}

void MenuScene::Update()
{
	sUpdate();
	if (DXUTWasKeyPressed('P')) Director::GetIns()->ChangeScene(new GameScene);
}

void MenuScene::OnExit()
{
	Delete();
}
