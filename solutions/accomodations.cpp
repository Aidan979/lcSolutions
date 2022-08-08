#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array A of N guests, the Kth guest wants to be in a room
of at most A[K] guests. Find the min number of required rooms.

ex A = [2,7,2,9,8]
return 2

[2,2,7,8,9]

*/

int solution(vector<int> &A)
{
    sort(A.begin(), A.end());

    int roomCount = 0;
    int index = 0;

    while(index < A.size())
    {
        index += A[index];
        ++roomCount;
    }

    return roomCount;
};

int main()
{
    vector<int> A = {4,4,4,2,1,4};
    int ans = solution(A);
    cout << ans << endl;
    
}