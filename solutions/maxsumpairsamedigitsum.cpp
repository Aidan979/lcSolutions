#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <queue>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int sumDigits(int n)
{
    int sum = 0;
    while (n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
};

// Input:  arr[]={55, 19, 23, 32, 46, 88}
// Output:  46 55 101

// [51,71,17,42]
// 93

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, int> sumset;
    int maxsum = -1;

    for (int i = 0; i < A.size(); ++i)
    {
        int digitsum = sumDigits(A[i]);
        if (sumset.find(digitsum) != sumset.end())
        { 
            if (A[i] + sumset.at(digitsum) > maxsum)
                maxsum = A[i] + sumset.at(digitsum);

            if (A[i] > sumset.at(digitsum))
                sumset.at(digitsum) = A[i];
        } else {
            sumset.insert({digitsum, A[i]});
        }
    }

    return maxsum;
};



int main()
{

    vector<int> v = {1434, 54, 3, 14, 11, 1000, 929};

    int ans = solution(v);

    cout << "ans: " << ans << endl;
    return 0;
}