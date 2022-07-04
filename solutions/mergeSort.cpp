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

    vector<int> merge(vector<int> a, vector<int> b)
    {
        vector<int> merged;

        while(a.size() > 0 && b.size() > 0)
        {
            if (a[0] > b[0])
            {
                merged.emplace_back(b[0]);
                b.erase(b.begin());
            }
            else{
                merged.emplace_back(a[0]);
                a.erase(a.begin());
            }
        }

        while(a.size() > 0)
        {
            merged.emplace_back(a[0]);
            a.erase(a.begin());
        }

        while(b.size() > 0)
        {
            merged.emplace_back(b[0]);
            b.erase(b.begin());
        }

        return merged;
    }

    vector<int> mergeSort(vector<int> v)
    {
        if (v.size() == 1)
            return v;

        vector<int> a = vector<int>(v.begin(), v.end() - v.size()/2);
        vector<int> b = vector<int>(v.end() - v.size()/2, v.end());

        a = mergeSort(a);
        b = mergeSort(b);

        return merge(a, b);
    }
};

int main()
{
    Solution sol;

    vector<int> input = {3,4,2,3,2,1,7};
    vector<int> ans = sol.mergeSort(input);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "ans: " << ans[i] << endl;
    };

    return 0;
}