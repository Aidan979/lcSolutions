#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Solution sol;

    //smallest on top
    priority_queue<int, vector<int>, greater<int>> sq;

    // largest on top
    priority_queue<int, vector<int>, less<int>> lq;

    lq.push(9);
    lq.push(43);
    lq.push(54);
    lq.push(42);

    sq.push(3);
    sq.push(5);
    sq.push(0);
    sq.push(4);

    while(!lq.empty())
    {
        cout << lq.top() << endl;
        lq.pop();
    }

    while(!sq.empty())
    {
        cout << sq.top() << endl;
        sq.pop();
    }

    return 0;
}