#include <iostream>
#include <vector>
using namespace std;

    int numDistrictUtil(string s, string t, int si, int ti, vector<vector<int>>& dp) {
        if (ti == t.size()) {
            if (s[si - 1] == t[ti - 1]) {
                dp[si][ti] = 1;
            }
            else {
                dp[si][ti] = 0;
            }
            return dp[si][ti];
        }
        if (si == s.size()) {
            dp[si][ti] = 0;
            return dp[si][ti];
        }
        if (dp[si][ti] != -1) return dp[si][ti];

        int choice1 = 0;
        int choice2 = 0;
        if (s[si] == t[ti]) {
            choice2 = numDistrictUtil(s, t, si + 1, ti + 1, dp);
        }
        choice1 = numDistrictUtil(s, t, si + 1, ti, dp);
        dp[si][ti] = choice1 + choice2;
        return dp[si][ti];
    }
    int numDistinct(string s, string t) {
        if (s == "" || t == "") {
            return 0;
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        int countRes = numDistrictUtil(s, t, 0, 0, dp);
        return countRes;
    }
int main() {
    string s = "";
    string t = "";
    cout<<numDistinct(s, t);
}