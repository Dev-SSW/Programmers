#include <iostream>
#include <string>
#include <vector>
using namespace std;
int result;
void slice(string s)
{
    for (int i = 1; i <= s.size()/2; i++) // 1부터 s.size()의 크기 단위까지
    {
        int count = 1;
        string token = s.substr(0, i);
        string word;
        for (int j = i; j < s.size(); j = j+i)  // 계속해서 비교
        {
            if (token == s.substr(j, i))  //같은 단어의 연속이라면 count 개수를 늘림
            {
                count++;
            }
            else   //같은 단어의 연속이 아니게 될 때,
            {
                if (count > 1)  // count가 2 이상이면 word에 count 값을 넣어줌
                {
                    word += to_string(count);
                }
                word += token;  //잘랐던 문자열 넣어주고,
                token = s.substr(j, i); //다음 단위 문자열을 다시 token에 넣자
                count = 1; //count도 원래대로 돌려놓기
            }
        }
        //for문이 다 끝나고 남은 문자열이 있으면?
        if (count > 1) word += to_string(count);
        word += token;
        if (result > word.size()) result = word.size();
    }
}
int solution(string s) {
    result = s.size();
    slice(s);
    return result;
}
int main()
{
    int result = solution("xababcdcdababcdcd");
    cout << result << endl;
}