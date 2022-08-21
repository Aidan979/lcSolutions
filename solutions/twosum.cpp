#include <iostream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers and target return indicies
of two numbers such that they add up to target

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

nums = [8,7,11,2,15]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indicies;
        
        unordered_map<int, int> indexmap;

        int diff = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            
            diff = target - nums[i];
            if (indexmap.find(diff) != indexmap.end())
            {
                if (i == indexmap.at(diff))
                    continue;

                indicies.emplace_back(indexmap[diff]);
                indicies.emplace_back(i);
                break;
            }
            indexmap[nums[i]] = i;

        }

        return indicies;
    }
};

int main()
{
    Solution sol;

    vector<int> n = {2,24,3,6,3};
    vector<int> ans = sol.twoSum(n, 6);

    for (auto n : ans){
    cout << "ans: " << n << endl;

    }

    return 0;
}