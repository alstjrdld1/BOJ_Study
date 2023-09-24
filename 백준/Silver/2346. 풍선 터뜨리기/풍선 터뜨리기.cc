#include <iostream>
#include <deque>
using namespace std;

int main() 
{
	int N;
	cin >> N;

	deque<int> dQ;
	deque<int> balloons;

	for (int i = 0; i < N; i++) 
	{
		int balloonNum;
		cin >> balloonNum;
		dQ.push_back(balloonNum);
		balloons.push_back(i + 1);
	}

	while (!balloons.empty())
	{
		int moveNum = dQ.front();
		int curBalloon = balloons.front();
		cout << curBalloon << " ";

		dQ.pop_front();
		balloons.pop_front();

		if (balloons.empty())
		{
			break;
		}

		if (moveNum > 0) // 오른쪽으로 넘기는 case 
		{
			for (int i = 0; i < moveNum-1; i++)
			{
				int dQfront = dQ.front();
				dQ.pop_front();
				int balloonfront = balloons.front();
				balloons.pop_front();

				dQ.push_back(dQfront);
				balloons.push_back(balloonfront);
			}
		}
		else // 왼쪽으로 넘기는 case
		{
			for (int i = moveNum; i < 0; i++)
			{
				int dQback = dQ.back();
				dQ.pop_back();
				int balloonback = balloons.back();
				balloons.pop_back();

				dQ.push_front(dQback);
				balloons.push_front(balloonback);
			}
		}
	}

	return 0;
}