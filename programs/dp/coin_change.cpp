#include <iostream>
#include <vector>

using namespace std;

int coinChangeWays(int amount, const vector<int>& coins) {
    int n = coins.size();
	vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amount; ++j) {

            dp[i][j] = dp[i - 1][j];
            if (coins[i - 1] <= j) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][amount];
}

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int numCoins;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    vector<int> coins(numCoins);
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }

    int ways = coinChangeWays(amount, coins);

    cout << "Number of ways to make change for " << amount << " using the given coins: " << ways << endl;

    return 0;
}

