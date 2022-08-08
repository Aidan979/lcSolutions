#include <iostream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

// Input: s = "babas"
// "sabab"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

class Solution {
public:
    string longestPalindrome(string s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
                
        int palLen = 0;
        int startIndex = 0;
        for (int l = 0; l < 2*s.length() - 1; ++l)
        {
            int currentPalLen = 0;
            for (int i = 0; i < s.length() - startIndex; ++i)
            {
                if (s[i] == reversed[startIndex + i])
                {
                    currentPalLen++;
                }
                else{
                    //break;
                }
            }
            if (currentPalLen > palLen)
            {
                palLen = currentPalLen;
            }
            startIndex++;
        }

        cout << "Pal len: " << palLen << endl;
        return reversed;        
    }
};

int main()
{
    Solution sol;

    string s = "dffhffds";
    string ans = sol.longestPalindrome(s);

    cout << ans << endl;

    return 0;
}