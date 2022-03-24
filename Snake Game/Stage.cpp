#include "DXUT.h"
#include "Include.h"

void Stage::StageInit()
{
	Camera::GetIns()->_camPos = { ScreenWidth / 2, ScreenHeight / 2 };
	TIME::scale = 1;

	direction = 0;
	warning = 0;

	GameOver = new Sprite(L"GameOver2.png");
	GameOver->_layer = 200;
	GameOver->_isUI = true;
	GameOver->_position = { ScreenWidth / 2, ScreenHeight / 2 };
	GameOver->_visible = false;

	Panel = new Sprite(L"Panel.png");
	Panel->_layer = 100;
	Panel->_isUI = true;
	Panel->_pivot = { 0,0 };

	Panel2 = new Sprite(L"Panel.png");
	Panel2->_layer = 100;
	Panel2->_position = { 0,624 + 16 };
	Panel2->_isUI = true;
	Panel2->_pivot = { 0,0 };

	Arrow = new Sprite(L"Arrow.png");
	Arrow->_layer = 100;
	Arrow->_color.a = 0;
	Arrow->_position = {ScreenWidth/2, ScreenHeight/2};
	Arrow->_isUI = true;

	tail = new Font;
	tail->CreateMyfont(1.5, 800);
	tail->_position = { 10,10 };
	tail->_color = color(0, 0, 0, 1);

	speed = new Font;
	speed->CreateMyfont(1.5, 800);
	speed->_position = { 10,60 };
	speed->_color = color(0, 0, 0, 1);

	timer = new Font;
	timer->CreateMyfont(1.5, 800);
	timer->_position = { 400,10 };
	timer->_color = color(0, 0, 0, 1);

	stack = 1000;
}

void Stage::StageUpdate()
{
	if (PlayerMNG::GetIns()->_player == nullptr) return;

	char buff[200];

	sprintf(buff, " Tail : %d", PlayerMNG::GetIns()->_player->length);
	tail->SetString(buff);
	sprintf(buff, " Speed : %.3fге / 3.5ге", TIME::scale);
	speed->SetString(buff);
	sprintf(buff, " Change Directions : %d", stack);
	timer->SetString(buff);

	ItemMNG::GetIns()->SpawnItem();

	switch (direction)
	{
	case 0:
		Camera::GetIns()->_camPos.x += TIME::delta * 100;
		break;
	case 1:
		Camera::GetIns()->_camPos.x += TIME::delta * 100;
		Camera::GetIns()->_camPos.y += TIME::delta * 100;
		break;
	case 2:
		Camera::GetIns()->_camPos.y += TIME::delta * 100;
		break;
	case 3:
		Camera::GetIns()->_camPos.x -= TIME::delta * 100;
		Camera::GetIns()->_camPos.y += TIME::delta * 100;
		break;
	case 4:
		Camera::GetIns()->_camPos.x -= TIME::delta * 100;
		break;
	case 5:
		Camera::GetIns()->_camPos.x -= TIME::delta * 100;
		Camera::GetIns()->_camPos.y -= TIME::delta * 100;
		break;
	case 6:
		Camera::GetIns()->_camPos.y -= TIME::delta * 100;
		break;
	case 7:
		Camera::GetIns()->_camPos.x += TIME::delta * 100;
		Camera::GetIns()->_camPos.y -= TIME::delta * 100;
		break;
	};
	
	stack--;
	if (Arrow->_color.a > 0) Arrow->_color.a -= TIME::delta;
	else Arrow->_color.a = 0;
	if (stack == 300)
	{
		warning = rand() % 8;
		Arrow->_color.a = 1;
		Arrow->_rotation = D3DXToRadian(warning * 45);
		cout << warning << endl;
	}
	if (stack == 0)
	{
		stack = rand() % 500 + 1000;
		direction = warning;
		cout << direction << endl;
	}
	if (TIME::scale < 3.5) TIME::scale += 0.00025;
	else TIME::scale = 3.5;

	if (DXUTWasKeyPressed(VK_RETURN))
	{
		if (GameOver->_visible == true)
		{
			Director::GetIns()->ChangeScene(new GameOverScene);
		}
	}
}

void Stage::StageExit()
{
	Camera::GetIns()->_camPos = { ScreenWidth / 2, ScreenHeight / 2 };
	TIME::scale = 1;

	SAFE_DELETE(GameOver);
	SAFE_DELETE(Arrow);
	SAFE_DELETE(Panel);
	SAFE_DELETE(Panel2);
	SAFE_DELETE(tail);
	SAFE_DELETE(speed);
	SAFE_DELETE(timer);
}
