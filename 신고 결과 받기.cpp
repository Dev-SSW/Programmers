#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
using namespace std;
map<string, set<string>> m;
map<string, int> result;
void Slice(vector<string> report)
{
    for (auto s : report) {
        stringstream ss(s);
        string reporter, reported;
        ss >> reporter >> reported;
        m[reported].insert(reporter);
    }
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    for (auto i = 0; i < id_list.size(); ++i)
    {
        result[id_list[i]] = i;
    }
    Slice(report);
    for (auto a : m)
    {
        if (a.second.size() >= k)
        {
            int i = 0;
            for (auto b : a.second)
            {
                answer[result[b]]++;
            }
        }
    }
    return answer;
}