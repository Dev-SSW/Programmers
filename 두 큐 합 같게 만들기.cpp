#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;

    int sz = queue1.size();
    for (int i = 0; i < sz; i++)
    {
        sum1 += queue1[i];
        q1.push(queue1[i]);

        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    int range = q1.size() * 2;
    int sz1 = 0 , sz2 =0;
    
    while (sz1 < range && sz2 < range)
    {
        if (sum1 == sum2)
        {
            return answer;
        }
        answer++;
        if (sum1 < sum2)
        {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum1 += tmp;
            sum2 -= tmp;
            sz1++;
        }
        else
        {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
            sz2++;
        }
    }
    return -1;
}
int main()
{
    vector<int> queue1 = { 3, 2, 7, 2 };
    vector<int> queue2 = { 4, 6, 5, 1 };
    int a = 0;
    a= solution(queue1, queue2);
    cout << a;
}