#include <string>
#include <vector>
using namespace std;
vector<int> solution(int n) {
    int temp[1000][1000];
    int x = 0, y = 0;
    int state = 0;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        switch (state)
        {
        case 0:
            for (int j = i; j < n; j++)
            {
                temp[x++][y] = num++;
            }
            x--; y++;
            state = 1;
            break;
        case 1:
            for (int j = i; j < n; j++)
            {
                temp[x][y++] = num++;
            }
            y = y - 2;
            x--;
            state = 2;
            break;
        case 2:
            for (int j = i; j < n; j++)
            {
                temp[x--][y--] = num++;
            }
            x = x + 2;
            y++;
            state = 0;
            break;
        }
    }
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(temp[i][j]);
        }
    }

    return answer;
}