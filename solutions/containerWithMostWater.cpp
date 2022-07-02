#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution
{
public:
    int maxArea(vector<int>& height) {

        int leftSideIndex = 0;
        int rightSideIndex = height.size() - 1;

        int maxArea = min(height[leftSideIndex], height[rightSideIndex])*(rightSideIndex - leftSideIndex);

        while (leftSideIndex != rightSideIndex)
        {
            int area = min(height[leftSideIndex], height[rightSideIndex])*(rightSideIndex - leftSideIndex);
            if(area > maxArea)
            {
                maxArea = area;
            }
            if (height[leftSideIndex] < height[rightSideIndex])
            {
                leftSideIndex++;
            }
            else
            {
                rightSideIndex--;
            }

        }
        return maxArea;
    }
};

int main()
{
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    //vector<int> height = {8,20,1,2,3,4,5,6};

    int ans = sol.maxArea(height);

    cout << ans << endl;

    return 0;
}