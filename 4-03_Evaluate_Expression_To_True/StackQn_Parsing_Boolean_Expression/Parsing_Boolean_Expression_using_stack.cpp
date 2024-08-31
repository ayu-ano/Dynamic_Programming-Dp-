


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' || c == '(') {
                continue;  // Ignore commas and opening parentheses.
            } else if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push(c);  // Push operators and boolean values onto the stack.
            } else if (c == ')') {
                // Evaluate the sub-expression.
                vector<char> subExpr;
                while (st.top() == 't' || st.top() == 'f') {
                    subExpr.push_back(st.top());
                    st.pop();
                }
                
                // Get the operator.
                char op = st.top();
                st.pop();  // Remove the operator.
                
                // Evaluate based on the operator.
                bool result;
                if (op == '!') {
                    result = evaluateNot(subExpr[0]);
                } else if (op == '&') {
                    result = evaluateAnd(subExpr);
                } else if (op == '|') {
                    result = evaluateOr(subExpr);
                }

                // Push the result back onto the stack.
                st.push(result ? 't' : 'f');
            }
        }

        // The final result is at the top of the stack.
        return st.top() == 't';
    }

    // Helper functions.
    bool evaluateNot(char val) {
        return val == 'f';
    }

    bool evaluateAnd(const vector<char>& subExpr) {
        for (char val : subExpr) {
            if (val == 'f') {
                return false;
            }
        }
        return true;
    }

    bool evaluateOr(const vector<char>& subExpr) {
        for (char val : subExpr) {
            if (val == 't') {
                return true;
            }
        }
        return false;
    }
};

// Test the solution with hardcoded values.
int main() {
    Solution solution;

    // Test case 1: &(|(f))
    string expression1 = "&(|(f))";
    bool result1 = solution.parseBoolExpr(expression1);
    cout << "Expression: " << expression1 << ", Result: " << (result1 ? "true" : "false") << endl;

    // Test case 2: |(f,f,f,t)
    string expression2 = "|(f,f,f,t)";
    bool result2 = solution.parseBoolExpr(expression2);
    cout << "Expression: " << expression2 << ", Result: " << (result2 ? "true" : "false") << endl;

    // Test case 3: !(f)
    string expression3 = "!(f)";
    bool result3 = solution.parseBoolExpr(expression3);
    cout << "Expression: " << expression3 << ", Result: " << (result3 ? "true" : "false") << endl;

    // Test case 4: !(&(f,t))
    string expression4 = "!(&(f,t))";
    bool result4 = solution.parseBoolExpr(expression4);
    cout << "Expression: " << expression4 << ", Result: " << (result4 ? "true" : "false") << endl;

    return 0;
}
