#pragma once
class Director : public Singleton<Director>
{
public:
	Scene* cur;
	POINT p;
	void DirectorInit();
	void DirectorUpdate();
	void ChangeScene(Scene* s);

	int ClickNum;

	bool MouseDown();
	bool Mouse();
	bool MouseUp();

	vec2 GetMousePos() { return vec2((float)p.x, (float)p.y); };
};

