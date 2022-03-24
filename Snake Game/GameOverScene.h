#pragma once
struct Rank
{
	char name[4];
	int score;
};
class GameOverScene : public Scene
{
public:
	char name[4];
	Font* curName;
	Font* next;

	bool isEnter;

	void GameInit();
	void GameUpdate();
	void GameExit();

	void Init() override;
	void Update() override;
	void OnExit() override;
};

class RankMNG : public Singleton<RankMNG>
{
public:
	int ranksize;
	
	bool visible;

	Font* _rank[10];
	vector<Rank> _ranklist;

	static bool Comp(Rank a, Rank b) { return a.score > b.score; };

	void AddRank();
	void DeleteRank();

	void Disable() { for (int i = 0; i < 10; i++) _rank[i]->_position = { -999,-999 }; };
	void Enable() {
		for (int i = 0; i < 10; i++)
			_rank[i]->_position = { 800,100 + ((float)i * 50) };
	}

	void LoadRank();
	void SaveRank();
};

