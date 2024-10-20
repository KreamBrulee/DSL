// Assignment 8: infix to postfix and evaluation
#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to perform arithmetic operations
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";
    for (int i = 0; i < infix.length(); ++i) {
        // If the character is a digit, read the full number.
        if (isdigit(infix[i])) {
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' '; // Add a space to separate numbers
            i--; // Adjust for the increment in the loop
        }
        // If the character is '(', push it to the stack.
        else if (infix[i] == '(') {
            operators.push(infix[i]);
        }
        // If the character is ')', pop and output from the stack until an '(' is encountered.
        else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop(); // Remove the '('
        }
        // If an operator is encountered
        else if (precedence(infix[i]) > 0) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }
    // Pop all the remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack<int> values;
    string number = "";
    for (int i = 0; i < postfix.length(); ++i) {
        // If the character is a digit, read the full number.
        if (isdigit(postfix[i])) {
            while (i < postfix.length() && isdigit(postfix[i])) {
                number += postfix[i];
                i++;
            }
            values.push(stoi(number)); // Convert the number string to integer and push it onto the stack.
            number = ""; // Reset the number string.
        }
        // If the character is an operator, pop two elements from the stack, apply the operator, and push the result back.
        else if (postfix[i] != ' ') { // Ignore spaces
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            int result = applyOperation(a, b, postfix[i]);
            values.push(result);
        }
    }
    // The final result will be the last element in the stack.
    return values.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}
