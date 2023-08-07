#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int count = 0;
    int sz = prices.size();
    for (int i = 0; i < sz; i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        answer[s.top()] = sz - 1 - s.top();
        s.pop();
    }
    return answer;
}
int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };
    vector<int> answer = solution(prices);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}