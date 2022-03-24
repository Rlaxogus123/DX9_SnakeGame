#pragma once


class Stage : public Singleton<Stage>
{
public:
	Sprite* GameOver;
	Sprite* Panel;
	Sprite* Panel2;
	Sprite* Arrow;

	Font* tail;
	Font* speed;
	Font* timer;

	float camSpeed;

	int direction;
	int warning;
	int stack;

	void StageInit();
	void StageUpdate();
	void StageExit();
};

