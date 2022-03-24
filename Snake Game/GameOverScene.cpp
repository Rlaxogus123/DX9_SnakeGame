#include "DXUT.h"
#include "Include.h"

void GameOverScene::GameInit()
{
	RankMNG::GetIns()->LoadRank();
	isEnter = false;

	next = new Font();
	next->CreateMyfont(1.5, 700);
	next->SetString("계속하려면 한번더 엔터 입력...");
	next->_color.a = 0;

	name[0] = ' ';
	name[1] = ' ';
	name[2] = ' ';
	name[3] = '\0';
	curName = new Font();
	curName->CreateMyfont(1.5, 800);
	curName->_position = { 100,100 };
}

void GameOverScene::GameUpdate()
{
	if(DXUTWasKeyPressed(VK_F1))
		RankMNG::GetIns()->LoadRank();

	if (!isEnter)
	{
		for (int i = 0; i < 26; i++)
		{
			if (DXUTWasKeyPressed('A' + i))
			{
				for (int j = 0; j < sizeof(name); j++)
				{
					if (name[j] == ' ')
					{
						name[j] = 'A' + i;
						break;
					}
				}
			}
		}

		if (DXUTWasKeyPressed(VK_BACK))
		{
			name[0] = ' ';
			name[1] = ' ';
			name[2] = ' ';
			name[3] = '\0';
		}

		char buff[100];
		sprintf(buff, "키보드로 이름 입력후 엔터 : %s", name);
		curName->SetString(buff);

		if (DXUTWasKeyPressed(VK_RETURN))
		{
			if (name[0] != ' ' && name[1] != ' ' && name[2] != ' ')
			{
				Rank r;
				r.name[0] = name[0];
				r.name[1] = name[1];
				r.name[2] = name[2];
				r.name[3] = '\0';
				r.score = TIME::score;

				name[0] = ' ';
				name[1] = ' ';
				name[2] = ' ';
				name[3] = '\0';

				RankMNG::GetIns()->_ranklist.push_back(r);
				RankMNG::GetIns()->SaveRank();
				RankMNG::GetIns()->LoadRank();
				isEnter = true;
			}
		}
	}
	else
	{
		next->_color.a = 1;
		if (DXUTWasKeyPressed(VK_RETURN))
		{
			Director::GetIns()->ChangeScene(new MenuScene);
		}
	}
}

void GameOverScene::GameExit()
{
	delete next;
	delete curName;
}

void GameOverScene::Init()
{
	RankMNG::GetIns()->AddRank();
	GameInit();
}

void GameOverScene::Update()
{
	GameUpdate();
}

void GameOverScene::OnExit()
{
	RankMNG::GetIns()->DeleteRank();
	GameExit();
}

void RankMNG::AddRank()
{
	for (int i = 0; i < 10; i++)
	{
		_rank[i] = new Font();
		_rank[i]->_color = color(1,1,1,1);
		_rank[i]->CreateMyfont(1.2, 800);
		_rank[i]->_position = { 800,100 + ((float)i * 50) };
		_rank[i]->SetString("점수 미등록");
	}
}

void RankMNG::DeleteRank()
{
	for (int i = 0; i < 10; i++)
	{
		delete _rank[i];
	}
}

void RankMNG::LoadRank()
{
	ifstream file("res/score.txt");
	if (file.is_open())
	{
		_ranklist.clear();
		char buff[256];
		file.getline(buff, 256);
		ranksize = atoi(buff);

		for (int i = 0; i < ranksize; i++)
		{
			Rank r;
			file.read(r.name, 4);
			file.getline(buff, 256);
			r.name[3] = '\0';
			r.score = atoi(buff);
			_ranklist.push_back(r);
		}
	}
	else
	{
		cout << "파일 찾기 실패!" << endl;
	}

	sort(_ranklist.begin(), _ranklist.end(), Comp);
	for (int i = 0; i < 10; i++)
	{
		if (_ranklist.size() <= i)
		{
			_rank[i]->SetString("점수 미등록");
			continue;
		}
		char buff[100];
		sprintf(buff, "%d.%s : %d", i + 1, _ranklist[i].name, _ranklist[i].score);
		_rank[i]->SetString(buff);
	}
}

void RankMNG::SaveRank()
{
	ofstream out("res/score.txt");

	if (out.is_open())
	{
		out << ranksize + 1 << endl;
		for (int i = 0; i < ranksize + 1; i++)
		{
			out << _ranklist[i].name << " ";
			out << _ranklist[i].score << endl;
		}
	}
}
