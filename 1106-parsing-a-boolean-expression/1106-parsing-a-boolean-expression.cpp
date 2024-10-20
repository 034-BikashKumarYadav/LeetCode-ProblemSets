class Solution {
public:
    // Optimal solution using stack
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char ch : expression) {
            if (ch == ')') {
                // Evaluate the expression inside the parentheses
                unordered_set<char> seen;
                while (stk.top() != '(') {
                    seen.insert(stk.top());
                    stk.pop();
                }
                stk.pop(); // pop the '('
                char operatorChar = stk.top();
                stk.pop();

                // Evaluate result based on the operator
                if (operatorChar == '&') {
                    stk.push(seen.count('f') ? 'f' : 't');
                } else if (operatorChar == '|') {
                    stk.push(seen.count('t') ? 't' : 'f');
                } else if (operatorChar == '!') {
                    stk.push(seen.count('t') ? 'f' : 't');
                }
            } else if (ch != ',') {
                stk.push(ch);
            }
        }
        return stk.top() == 't';
    }
};