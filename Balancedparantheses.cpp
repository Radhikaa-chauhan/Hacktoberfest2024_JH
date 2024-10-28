#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        // Push opening brackets to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Check for matching closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;  // Unmatched closing bracket
            char top = s.top();
            s.pop();
            // Ensure that the type of bracket matches
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    // Check if any unmatched opening brackets remain
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}
