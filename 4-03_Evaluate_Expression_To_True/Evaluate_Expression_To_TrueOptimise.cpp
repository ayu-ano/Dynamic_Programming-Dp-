#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N ^ 3)
    Space Complexity: O(N ^ 2)

    Where 'N' is the length of string.
*/

#define mod 1000000007

vector < vector < vector < long long int >>> memo;

int Evaluate_Expression_To_True(string & exp, int i, int j, int isTrue) {
    // Corner Cases.
    if (i > j) {
        return 0;
    }

    // If length of expression we need to evaluate is 1.
    if (i == j) {
        if (isTrue) {
            return exp[i] == 'T' ? 1 : 0;
        } else {
            return exp[i] == 'F' ? 1 : 0;
        }
    }

    if (memo[i][j][isTrue] != -1) {
        return memo[i][j][isTrue];
    }

    long long int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {

        if (memo[i][k - 1][1] == -1) {
            memo[i][k - 1][1] = (Evaluate_Expression_To_True(exp, i, k - 1, 1)) % mod;
        }

        if (memo[i][k - 1][0] == -1) {
            memo[i][k - 1][0] = (Evaluate_Expression_To_True(exp, i, k - 1, 0)) % mod;
        }

        if (memo[k + 1][j][1] == -1) {
            memo[k + 1][j][1] = (Evaluate_Expression_To_True(exp, k + 1, j, 1)) % mod;
        }

        if (memo[k + 1][j][0] == -1) {
            memo[k + 1][j][0] = (Evaluate_Expression_To_True(exp, k + 1, j, 0)) % mod;
        }

        // The number of ways expression left to 'K' will be true.
        long long int leftTrue = memo[i][k - 1][1];

        // The number of ways expression left to 'K' will be false.
        long long int leftFalse = memo[i][k - 1][0];

        // The number of ways expression right to 'K' will be true.
        long long int rightTrue = memo[k + 1][j][1];

        // The number of ways expression right to 'K' will be false.
        long long int rightFalse = memo[k + 1][j][0];

        if (exp[k] == '|') {
            // T|T=T, T|F=T, F|T=T , F|F=F. 
            if (isTrue) {
                ans += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                ans = ans % mod;
            } else {
                ans += leftFalse * rightFalse;
                ans = ans % mod;
            }
        } 
        else if (exp[k] == '&') {
            // T&T=T, T&F=F, F&T=F , F|F=F.
            if (isTrue) {
                ans += leftTrue * rightTrue;
                ans = ans % mod;

            } else {
                ans += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
                ans = ans % mod;
            }
        } 
        else {
            // T^T=F, T^F=T, F^T=T , F^F=F.
            if (isTrue) {
                ans += leftTrue * rightFalse + leftFalse * rightTrue;
                ans = ans % mod;
            } else {
                ans += leftTrue * rightTrue + leftFalse * rightFalse;
                ans = ans % mod;
            }
        }
    }
    
    return memo[i][j][isTrue] = ans;
}

int evaluateExp(string & exp) {
    int n = exp.size();

    // We need to evaluate the whole expression for true.
    memo = vector < vector < vector < long long int >>> (n, vector < vector < long long int >> 
        (n, vector < long long int > (2, -1)));
    
    return Evaluate_Expression_To_True(exp, 0, n - 1, 1);
}

int main() {
    // Hardcoded expression
    string expression = "T|F&T^F";  // You can modify this expression to test other cases.
    
    // Output the number of ways to evaluate the expression to true
    cout << "Number of ways to evaluate expression to True: " << evaluateExp(expression) << endl;

    return 0;
}
