#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(vector<int> &vec)
    {
        int lowerSum = 0;
        int higherSum = 0;

        for (int i = 1; i < vec.size(); ++i)
        {
            higherSum += vec[i];
        }

        for (int i = 0; i < vec.size(); ++i)
        {
            if (lowerSum == higherSum)
            {
                return i;
            }

            lowerSum += vec[i];
            if (i < vec.size() - 1){                
                higherSum -= vec[i+1];
            } else {
                higherSum = 0;
            }
        }
        return -1;
    }
};



int main()
{
    Solution sol;
    vector<int> v = {-1,-1,1};
    int ans = sol.solve(v);
    cout << ans << endl;

    return 0;
}