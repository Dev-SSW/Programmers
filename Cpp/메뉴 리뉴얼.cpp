#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std; //조합을 사용하는 문제이다.
map<string, int> m;

void DFS(string order, int count, string word, int index) {
    if (word.length() == count) {  //만들어진 string word가 count의 개수와 같으면 map m[word]++ 을 해주어 2번 이상 나오는지 체크 m[AC] = 1 이런 식
        m[word]++;
        return;
    }
    for (int i = index; i < order.length(); i++) { //모든 조합이 생성 (겹치지 않도록)
        DFS(order, count, word + order[i], i + 1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //시작 시 orders의 문자열들을 오름차순으로 정렬 시킨다. (주어진 문자열이 오름차순이 아니니까)
    //모든 orders 배열의 내용 문자열들이 조합을 계속 만들어낸다.
    for (int count : course) { //course 배열의 길이만큼 반복
        for (string order : orders) { //orders 배열의 길이만큼 반복
            sort(order.begin(), order.end());
            DFS(order, count, "", 0);
        }
        int maxCount = 0; //최다 주문 횟수
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