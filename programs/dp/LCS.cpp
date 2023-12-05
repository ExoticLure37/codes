#include <iostream>
#include <vector>

using namespace std;

// Function to find the Longest Common Subsequence
string printLCS(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D array to store the lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS
    int i = m, j = n;
    string lcs;

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string str1 = "ABCBDAB";
    string str2 = "BDCAB";
    string lcs = printLCS(str1, str2);
    int length = lcs.length();


    cout << "Length of Longest Common Subsequence: " << length << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
