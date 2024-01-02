#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second) ? true : false;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    string temp = "";
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '}' || s[i] == ',')
        {
            if (temp == "")continue;
            m[stoi(temp)]++;
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].first);
    }
    return answer;
}
int main()
{
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> answer = solution(s);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
    }
    return 0;
}