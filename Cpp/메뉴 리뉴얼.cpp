#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std; //������ ����ϴ� �����̴�.
map<string, int> m;

void DFS(string order, int count, string word, int index) {
    if (word.length() == count) {  //������� string word�� count�� ������ ������ map m[word]++ �� ���־� 2�� �̻� �������� üũ m[AC] = 1 �̷� ��
        m[word]++;
        return;
    }
    for (int i = index; i < order.length(); i++) { //��� ������ ���� (��ġ�� �ʵ���)
        DFS(order, count, word + order[i], i + 1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //���� �� orders�� ���ڿ����� ������������ ���� ��Ų��. (�־��� ���ڿ��� ���������� �ƴϴϱ�)
    //��� orders �迭�� ���� ���ڿ����� ������ ��� ������.
    for (int count : course) { //course �迭�� ���̸�ŭ �ݺ�
        for (string order : orders) { //orders �迭�� ���̸�ŭ �ݺ�
            sort(order.begin(), order.end());
            DFS(order, count, "", 0);
        }
        int maxCount = 0; //�ִ� �ֹ� Ƚ��
        for (auto a : m) {
            maxCount = max(maxCount, a.second);
        }

        for (auto b : m) {
            if (maxCount < 2) break;
            else if (m[b.first] == maxCount) {
                answer.push_back(b.first);
            }
        }
        m.clear();
    }

    sort(answer.begin(), answer.end());
    return answer;
}