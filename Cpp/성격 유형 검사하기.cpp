#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int num[8] = { 0, 3, 2, 1, 0, 1, 2, 3 };
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    for (int i = 0; i < survey.size(); i++)
    {
        string line = survey[i];
        int n = choices[i];
        //4���� ũ�� ù��° ���ڿ� 4���� ������ �ι�° ���ڿ� ���� ����
        if (n == 4)
        {
            continue;
        }
        if (n > 4)
        {
            m[line[1]] += num[n];
        }
        if (n < 4)
        {
            m[line[0]] += num[n];
        }
    }
        (m['R'] >= m['T']) ? answer += "R" : answer += "T";
        (m['C'] >= m['F']) ? answer += "C" : answer += "F";
        (m['J'] >= m['M']) ? answer += "J" : answer += "M";
        (m['A'] >= m['N']) ? answer += "A" : answer += "N";
    
    return answer;
}
int main()
{

    vector<string> survey;
    vector<int> choices;
    survey = {"AN", "CF", "MJ", "RT", "NA"};
    choices = { 5, 3, 2, 7, 5 };
    cout << solution(survey, choices) << endl;
    
}