#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> s;
    bool flag = 0;
    if(s == "ACE")
        flag = 1;
    if(s == "BDF")
        flag = 1;
    if(s == "CEG")
        flag = 1;
    if(s == "DFA")
        flag = 1;
    if(s == "EGB")
        flag = 1;
    if(s == "FAC")
        flag = 1;
    if(s == "GBD")
        flag = 1;
    if(flag)
        cout << "Yes" << '\n';
    else 
        cout << "No" << "\n";
}