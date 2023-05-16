#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
bool check(long long n)   //에라토스테네스의 체 (소수 찾기)
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
    while (n > 0) {   //10진수 n진수로 만들기
        num += to_string(n % k);  
        n /= k;
    }
    reverse(num.begin(), num.end());   // num 안의 값 reverse로 변환  num 안엔 n진수로 변환된 값이 들어있다. ex) 11010110
    
    int answer = 0;
    string str = "";
    for (auto s : num)
    {
        if (s == '0')
        {
            if (str.length() == 0) continue;
            if (check(stol(str)) == true)  //소수면 true 아니면 false
            {
                answer++;  //소수면 count++
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