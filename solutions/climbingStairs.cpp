#include <iostream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

class Solution {
public:
    int climbStairs(int n) {

        if (n <= 1)
            return n;

        int b = 2;
        int prevOnes = 1;
        int perm = 2;
        while (b != n)
        {
            perm = perm + prevOnes;
            prevOnes = perm - prevOnes;
            b++;
        }
        return perm;
    }
};

int main()
{
    Solution sol;

    int n = 3;
    int ans = sol.climbStairs(1);

    cout << "ans: " << ans << endl;

    return 0;
}