#include <iostream>
#include <vector>
#include <unordered_map>

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> elementMap;

        for (auto& num : nums)
        {
            elementMap[num]++;
        }
        
        int maxKey = 0;
        int maxVal = 0;
        for (auto& pair : elementMap)
        {
            if (pair.second > maxVal)
            {
                maxVal = pair.second;
                maxKey = pair.first;
            }
        }
        return maxKey;
    }
};

int main()
{
    Solution sol;
    vector<int> input = {3,3,2,2,2,1,1,1,1};

    int ans = sol.majorityElement(input);
    cout << "Ans: " << ans << endl;
    
    return 0;
}