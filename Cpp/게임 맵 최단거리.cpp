#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MAX 101
int visited[MAX][MAX] = { 0 , };
int dist[MAX][MAX] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int solution(vector<vector<int>> maps)
// maps �ȿ� 
// 1 0 1 1 1     0,0  0,1  0,2  0,3  0,4
// 1 0 1 0 1     1,0  1,1  2,1  3,1  4,1
// 1 0 1 1 1     2,0  1,2  2,2  3,2  4,2
// 1 1 1 0 1     ...
// 0 0 0 0 1
//�� ��� �ִ�.
{
	int N = maps.size();  //���� ����
	int M = maps[0].size(); // ���� ����
	visited[0][0] = 1;  //�湮 ó��
	q.push(make_pair(0, 0));  //0,0�� ť�� ����
	dist[0][0] = 1;      // dist[0][0]�� �Ÿ� ���� 1�� ����

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];

			if ((0 <= mx && mx < N) && (0 <= my && my < M) && !visited[mx][my] && maps[mx][my] == 1) 
			//�� �� �־���ϰ� (1), �湮�ߴ� ���� �ƴϾ����
			{
				visited[mx][my] = 1;
				q.push(make_pair(mx, my));
				dist[mx][my] = dist[x][y] + 1;
			}
		}
	}
	int answer = dist[N-1][M-1];
	if (answer == 0)
	{
		return -1;
	}
	return answer;
}
int main()
{
	int N = 5, M = 5;
	vector<vector<int>> maps1 = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} };
	cout << solution(maps1) << endl;
	//vector<vector<int>> maps2 = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 0},{0,0,0,0,1} };
	//cout << solution(maps2) << endl;
}