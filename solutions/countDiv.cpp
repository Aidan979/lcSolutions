#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include<bits/stdc++.h>

/*
Given a range of numbers from A to B, find the number of times an integer K 
can be divided evenly into numbers within the range A to B
Ex: A = 6, B = 11, K = 2
6, 7, 8, 9, 10, 11
K divides evenly into three numbers within the range, ie 6, 8, 10
return 3;
*/

using namespace std;

int main()
{
    int A = 4;
    int B = 15;
    int K = 3;
    int M = 0;

    if (A % K == 0 || B % K == 0)
    {
        M = (B - A)/K + 1; 
    } else {
        M = (B - A)/K;
    }


    cout << M << endl;

    return 0;
}