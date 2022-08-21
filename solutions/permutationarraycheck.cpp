#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*

*/

int solution(vector<int> &A)
{
    unordered_set<int> set;

    for (auto& n : A)
    {
        if (set.find(n) == set.end())
        {
            set.insert(n);
        } else {
            return 0;
        }
    }
    return 1;
};

int main()
{
    vector<int> A = {4,3,2,7,5,6,1};
    int ans = solution(A);
    cout << ans << endl;
    
}