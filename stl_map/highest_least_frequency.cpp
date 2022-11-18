/*
*Problem: Given an array, find the difference between 
*highest occurrence and least occurrence of any number in an array
*
*solution: used map to count the frequncy of elements and find min and max for second element of map
* T(n) -> O(n)
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++)
        cin >> v[i];
    map<int, int> m;
    for (int i = 0; i < n;i++)
        m[v[i]]++;
    int s = INT_MAX;
    int g = INT_MIN;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if(i->second >= g)
            g = i->second;
        if(i->second <= s)
            s = i->second;
    }
    cout << "difference between highest and least frequency is: " << g - s<<endl;
}