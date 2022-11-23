#include <iostream>
#include <random>
#include <stdexcept>

using namespace std;
#define LEN	3


class BaseballGame
{
public:
	BaseballGame()
	{
		cout << "���� �߱� ������ �����մϴ�.\n";
		init();
	}

	~BaseballGame() {}

	void Play()
	{
		while (true)
		{
			input();
			if (scoring() == LEN)
				break;
		}

		cout << "3���� ���ڸ� ��� �����̽��ϴ�! ���� ����\n";
	}


private:
	void init()
	{
		setRandomAns();
	}

	void input()
	{
		cout << "���ڸ� �Է����ּ��� : ";
		cin >> mNums;

		try
		{

		}
		catch (const exception& e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		}
		// strlen(mNums) == LEN�� �ƴ� ���, ���� �ٸ� 3���� ���� �ƴ� ��� invalid_argument �߻� �� ����(��������, �ߺ�����)
	}

	int scoring()
	{
		int ball = 0,
			strike = 0;

		for (size_t i = 0; i < LEN; i++)
		{
			for (size_t j = 0; j < LEN; j++)
			{
				if (mNums[i] == mAns[j])
				{
					if (i == j)
						strike++;
					else
						ball++;
				}
			}
		}

		printScore(ball, strike);
		return strike;
	}

	void printScore(int ball, int strike)
	{
		if (ball == 0)
		{
			if (strike == 0)
				cout << "����\n";
			else
				cout << strike << "��Ʈ����ũ\n";
		}
		else if (strike == 0)
			cout << ball << "��\n";
		else
			cout << ball << "�� " << strike << "��Ʈ����ũ\n";
	}

	void setRandomAns()
	{
		random_device						rd;
		mt19937								gen(rd());
		uniform_int_distribution<size_t>	dis(1, 9);

		char	randomNum;
		size_t	idx = 0;
		while (idx < LEN)
		{
			randomNum = char(dis(gen) + '0');

			bool dup = false;
			for (size_t i = 0; i < idx; i++)
			{
				if (randomNum == mAns[i])
				{
					dup = true;
					break;
				}
			}

			if (!dup)
				mAns[idx++] = randomNum;
		}
	}


private:
	string	mNums;
	char	mAns[LEN + 1];

};


int main()
{
	BaseballGame game;
	game.Play();

	return 0;
}