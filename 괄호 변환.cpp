#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string p) {

    string u = "";
    string v = ""; 
    //u �������� ���ڿ� , v ������ ���ڿ�

    if (p == "")  //p�� �� ���ڿ��� �� �� ���ڿ� ��ȯ
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
            u = p.substr(0, i);  //�������� ���ڿ�
            if (i<p.length()) v = p.substr(i);   //�������� ��� ���ڿ�  (i���� ������)
            break;
        }
    }
    bool right = true;
    for (char s : u)
    {
        if (s == '(') { break; }
        else { right = false; } // s == ')'
    }
    if (right == true)  //�������� �ùٸ� ���ڿ��̸�
    {
        u += solution(v);
        return u;
    }
    else
    {
        string a = "(";
        a += solution(v); //�������� �ùٸ� ���ڿ��� �� �� ���� ��͵Ǿ �ᱹ �������� �ùٸ� ���ڿ��� ���ϵǾ� �� (u�� ��� ��)
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
//�������� ���ڿ� = ( �� ) �� ¦�� ������ ����
//�ùٸ� ���ڿ� = ( �� ) �� ¦�� ������ �°� ¦�� ��� ����