#include "DXUT.h"
#include "Include.h"

Player::Player()
{
	_layer = 10;
	_rotation = 0;
	length = 1;
	tail = new Tail[500];
	speed = 0.1;
	tick_speed = 0;
	dir = 0;
	que = 0;

	_position = { 48,176 };
	_color = color(1, 0, 0, 1);
	SetTexture(L"Head.png");
}

void Player::Update()
{
	//¾öÁØ½Ä
	if (DXUTWasKeyPressed('Z')) length++;
	if (DXUTWasKeyPressed('X')) ItemMNG::GetIns()->SpawnItem();
	
	if (DXUTWasKeyPressed('W') && dir != 3) dir = 1;
	if (DXUTWasKeyPressed('S') && dir != 1) dir = 3;
	if (DXUTWasKeyPressed('A') && dir != 0) dir = 2;
	if (DXUTWasKeyPressed('D') && dir != 2) dir = 0;

	if (tick_speed > -1) tick_speed += TIME::delta;
	else Stage::GetIns()->GameOver->_visible = true;

	if (tick_speed > speed)
	{
		switch (dir)
		{
		case 0:
			_position.x += 32;
			_rotation = 0;
			break;
		case 1:
			_position.y -= 32;
			_rotation = D3DXToRadian(270);
			break;
		case 2:
			_position.x -= 32;
			_rotation = D3DXToRadian(180);
			break;
		case 3:
			_position.y += 32;
			_rotation = D3DXToRadian(90);
			break;
		}

		if (_position.x > Camera::GetIns()->_camPos.x + 640 || _position.x < Camera::GetIns()->_camPos.x - 640
			|| _position.y < Camera::GetIns()->_camPos.y - 360 + 160 || _position.y > Camera::GetIns()->_camPos.y + 360 - 96)
		{
			tick_speed = -2;
			return;
		}

		que++;
		que %= 500;

		PlayerMNG::GetIns()->save[que].pos = _position;
		PlayerMNG::GetIns()->save[que].dir = dir;

		tick_speed = 0;
		for (int i = 0, o = que; i < length; i++, o--)
		{
			int t = o -1;
			if (t < 0) t += 500;

			int collisionx = PlayerMNG::GetIns()->save[t].pos.x;
			int collisiony = PlayerMNG::GetIns()->save[t].pos.y;

			if (collisionx == _position.x && collisiony == _position.y) tick_speed = -1;

			tail[i]._position = vec2(collisionx, collisiony);
			tail[i]._visible = true;
		}
	}
}

void PlayerMNG::CreatePlayer()
{
	_player = new Player();
}

void PlayerMNG::DeletePlayer()
{
	SAFE_DELETE_ARRAY(_player->tail);
	SAFE_DELETE(_player);
}

Tail::Tail()
{
	_visible = false;
	_layer = 10;
	SetTexture(L"Tile.png");
}
