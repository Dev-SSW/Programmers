#include <iostream>
#include <string>
#include <vector>
using namespace std;
int result;
void slice(string s)
{
    for (int i = 1; i <= s.size()/2; i++) // 1���� s.size()�� ũ�� ��������
    {
        int count = 1;
        string token = s.substr(0, i);
        string word;
        for (int j = i; j < s.size(); j = j+i)  // ����ؼ� ��
        {
            if (token == s.substr(j, i))  //���� �ܾ��� �����̶�� count ������ �ø�
            {
                count++;
            }
            else   //���� �ܾ��� ������ �ƴϰ� �� ��,
            {
                if (count > 1)  // count�� 2 �̻��̸� word�� count ���� �־���
                {
                    word += to_string(count);
                }
                word += token;  //�߶��� ���ڿ� �־��ְ�,
                token = s.substr(j, i); //���� ���� ���ڿ��� �ٽ� token�� ����
                count = 1; //count�� ������� ��������
            }
        }
        //for���� �� ������ ���� ���ڿ��� ������?
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