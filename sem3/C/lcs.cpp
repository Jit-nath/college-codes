#include <iostream>
#include <string>
#include <vector>

int lcs(std::string X, std::string Y, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}
int main() {
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length();

    std::cout << "LCS is :" << lcs(X, Y, m, n);

    return 0;
}