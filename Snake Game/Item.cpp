#include "DXUT.h"
#include "Include.h"

Item::Item()
{
	_visible = false;
	SetTexture(L"Tile.png");
	_color = color(0, 1, 0, 1);
}

void Item::Update()
{
	if (!_visible) return;
	
	if (_position.x > Camera::GetIns()->_camPos.x + 640 || _position.x < Camera::GetIns()->_camPos.x - 640
		|| _position.y < Camera::GetIns()->_camPos.y - 360 + 160 || _position.y > Camera::GetIns()->_camPos.y + 360 - 96)
	{
		_visible = false;
		return;
	}

	RECT r;
	if (IntersectRect(&r, &GetRect(), &PlayerMNG::GetIns()->_player->GetRect()))
	{
		PlayerMNG::GetIns()->_player->length++;
		TIME::score += 100;
		_visible = false;
		return;
	}
}

void ItemMNG::SpawnItem()
{
	for (auto it : _itemlist)
	{
		if (!it->_visible)
		{
			it->_visible = true;
			float posX = + Camera::GetIns()->_camPos.x + (rand() % 39 * 32) - 640;
			float posY = + Camera::GetIns()->_camPos.y + 176 + (rand() % 14 * 32) - 360;

			posX -= (int)posX % 32;
			posY -= (int)posY % 32;
			it->_position = vec2(posX + 16,posY + 16);
			return;
		}
	}
}
