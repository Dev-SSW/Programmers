#include <string>
#include <vector>   
#include <algorithm>
using namespace std;
vector<long long> num;
vector<char> opr;
vector<char> f = { '*','+','-' };
long long getRes(long long a, char o, long long b) {
    if (o == '+') return a + b;
    if (o == '-') return a - b;
    return a * b;
}
long long solution(string expression) {
    long long answer = 0;
    string tmp;
    for (auto a : expression)
    {
        if (a == '+' || a == '-' || a == '*')
        {
            opr.push_back(a);
            num.push_back(stoll(tmp));
            tmp = "";
        }
        else tmp += a;
    }
    num.push_back(stoll(tmp));
    vector<char> opr2;
    vector<long long> num2;
    do
    {
        num2 = num;
        opr2 = opr;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < opr2.size(); j++)
            {
                if (f[i] == opr2[j])
                {
                    long long res = getRes(num2[j], opr2[j], num2[j + 1]);
                    num2.erase(num2.begin() + j);
                    opr2.erase(opr2.begin() + j);
                    num2[j] = res;
                    j--;
                }
            }
        }
        answer = max(answer, abs(num2[0]));
    } while (next_permutation(f.begin(), f.end()));

    return answer;
}