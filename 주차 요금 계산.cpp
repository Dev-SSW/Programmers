#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;
int make_minute(string in, string out)
{
    int hour = stoi(out.substr(0, 2)) - stoi(in.substr(0, 2));
    int minute = stoi(out.substr(3, 2)) - stoi(in.substr(3, 2));
    int result = hour * 60 + minute;
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> mp;
    map<string, int> res;
    for (int i = 0; i < records.size(); i++)
    {
        stringstream ss(records[i]);
        string tmp;
        vector<string> info;

        while (ss >> tmp) 
        {
            info.push_back(tmp);
        }
        if (info[2] == "IN")
        {
            mp[info[1]] = info[0];   // mp["0000"] = 06:00
        }
        else // "OUT"
        {
            string out = info[0];
            string in = mp[info[1]]; 
            mp[info[1]] = ""; //mp["0000"] »©³»±â
            res[info[1]] += abs(make_minute(in, out)); //res["0000"] = 360
        }   
    }
    for (auto a : mp)
    {
        if (!mp[a.first].empty())
        {
            res[a.first] += abs(make_minute(mp[a.first], "23:59"));
        }
    }
    vector<pair<string, int>> last;
    for (auto b : res)
    {
        int price = 0;
        if (b.second <= fees[0]) { price = fees[1]; }
        else
        {
            price = fees[1] + ceil(((double)(b.second - fees[0])) / fees[2]) * fees[3];
        }
        last.push_back({b.first, price});
    }
    sort(last.begin(), last.end());
    for (int i = 0; i < last.size(); i++)
    {
        answer.push_back(last[i].second);
    }
    return answer;

}
int main()
{
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
        "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT",
        "22:59 5961 IN", "23:00 5961 OUT" };
    vector<int> result = solution(fees, records);
    for (auto a : result)
    {
        cout << a << endl;
    }
}