#pragma once

struct saveNode
{
	vec2 pos;
	int dir;
};

class Tail : public Sprite
{
public:
	explicit Tail();
	~Tail() {};
};

class Player : public Sprite
{
public:
	explicit Player();
	~Player() {};

	Tail* tail;

	int length;
	int que;

	int dir;
	float tick_speed;
	float speed;

	void Update() override;
};

class PlayerMNG : public Singleton<PlayerMNG>
{
public:
	saveNode save[500];
	Player* _player;
	void CreatePlayer();
	void DeletePlayer();
};

