#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
bool check(long long n)   //�����佺�׳׽��� ü (�Ҽ� ã��)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int solution(int n, int k) {
    string num;
    while (n > 0) {   //10���� n������ �����
        num += to_string(n % k);  
        n /= k;
    }
    reverse(num.begin(), num.end());   // num ���� �� reverse�� ��ȯ  num �ȿ� n������ ��ȯ�� ���� ����ִ�. ex) 11010110
    
    int answer = 0;
    string str = "";
    for (auto s : num)
    {
        if (s == '0')
        {
            if (str.length() == 0) continue;
            if (check(stol(str)) == true)  //�Ҽ��� true �ƴϸ� false
            {
                answer++;  //�Ҽ��� count++
            }
            str = "";
        }
        else
        {
            str += s;
        }
    }
    if (str.length() != 0)
    {
        if (check(stol(str)) == true)
        {
            answer++;
        }
    }
    return answer;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << solution(n, k);
}