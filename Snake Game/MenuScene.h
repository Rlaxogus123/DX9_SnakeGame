#pragma once
class MenuScene : public Scene
{
public:
	Sprite* test;
	Sprite* button1;
	Sprite* button2;
	Sprite* button3;
	Sprite* pannel;
	Sprite* mouse;

	void Create();
	void sUpdate();
	void Delete();

	float SquareRoot(int n);

	void Init() override;
	void Update() override;
	void OnExit() override;
};

