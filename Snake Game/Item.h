#pragma once
class Item : public Sprite
{
public:
	Item();
	~Item() {};

	void Update() override;
};

class ItemMNG : public Singleton<ItemMNG>
{
public:
	Item* _item;
	list<Item*> _itemlist;

	void CreateItem() { for (int i = 0; i < 5; i++) { _item = new Item(); _itemlist.push_back(_item); } };
	void SpawnItem();
	void DeleteItem() { for (auto it : _itemlist) SAFE_DELETE(it); _itemlist.clear(); };
};

class Enemy : public Sprite
{
public:
	Enemy();
	~Enemy() {};

	void Update() override;
};

class EnemyMNG : public Singleton<ItemMNG>
{
public:
	Item* _item;
	list<Item*> _itemlist;

	void CreateItem() { for (int i = 0; i < 5; i++) { _item = new Item(); _itemlist.push_back(_item); } };
	void SpawnItem();
	void DeleteItem() { for (auto it : _itemlist) SAFE_DELETE(it); _itemlist.clear(); };
};