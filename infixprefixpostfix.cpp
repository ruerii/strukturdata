//nama Septike Utari Nurrani
//nim 20220801335

#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPriority(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPrefix(string expression) {
    stack<char> operators;
    stack<string> operands;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (isalpha(ch) || isdigit(ch)) {
            string operand(1, ch);
            operands.push(operand);
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                string temp = op + operand1 + operand2;
                operands.push(temp);
            }

            // Menghapus tanda kurung buka '('
            operators.pop();
        }
        else if (isOperator(ch)) {
            while (!operators.empty() && getPriority(ch) <= getPriority(operators.top())) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                string temp = op + operand1 + operand2;
                operands.push(temp);
            }

            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        string temp = op + operand1 + operand2;
        operands.push(temp);
    }

    return operands.top();
}


string infixToPostfix(string expression) {
    stack<char> operators;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (isalpha(ch) || isdigit(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }


            operators.pop();
        }
        else if (isOperator(ch)) {
            while (!operators.empty() && operators.top() != '(' && getPriority(ch) <= getPriority(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }

            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    cout << "Masukkan notasi infix: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Notasi prefix  : " << prefixExpression << endl;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Notasi postfix : " << postfixExpression << endl;

    return 0;
}
