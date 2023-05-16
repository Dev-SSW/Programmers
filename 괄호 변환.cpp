#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string p) {

    string u = "";
    string v = ""; 
    //u 균형잡힌 문자열 , v 나머지 문자열

    if (p == "")  //p가 빈 문자열일 때 빈 문자열 반환
    {
        return "";
    }
    int count = 0 , i = 0;
    for (char s : p)
    {
        if (s == '('){count++;}
        else{count--;}
        i++;
        if (count == 0)
        {
            u = p.substr(0, i);  //균형잡힌 문자열
            if (i<p.length()) v = p.substr(i);   //나머지를 담는 문자열  (i부터 끝까지)
            break;
        }
    }
    bool right = true;
    for (char s : u)
    {
        if (s == '(') { break; }
        else { right = false; } // s == ')'
    }
    if (right == true)  //균형잡힌 올바른 문자열이면
    {
        u += solution(v);
        return u;
    }
    else
    {
        string a = "(";
        a += solution(v); //균형잡힌 올바른 문자열이 될 때 까지 재귀되어서 결국 균형잡힌 올바른 문자열이 리턴되어 들어감 (u가 계속 들어감)
        a += ")";
        u.erase(u.begin()); u.erase(u.end()-1);
        for (char s : u)
        {
            if (s == '(') { a += ")"; }
            else if (s == ')') { a += "("; }
        }
        return a;
    }
}
int main()
{
    string test;
    cin >> test;
    string result;
    result = solution(test);
    cout << result << endl;
}
//균형잡힌 문자열 = ( 과 ) 의 짝의 개수가 맞음
//올바른 문자열 = ( 과 ) 의 짝의 개수가 맞고 짝도 모두 맞음