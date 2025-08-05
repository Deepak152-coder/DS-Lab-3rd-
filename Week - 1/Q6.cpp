#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToPrefix(string exp)
{
    stack<string> st;
    for (char c : exp)
    {
        if (isspace(c))
            continue;
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = c + op2 + op1;
            st.push(temp);
        }
    }
    return st.top();
}

string prefixToPostfix(string exp)
{
    stack<string> st;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char c = exp[i];
        if (isspace(c))
            continue;
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = op1 + op2 + c;
            st.push(temp);
        }
    }
    return st.top();
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix;

    for (char c : infix)
    {
        if (isspace(c))
            continue;
        if (isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    stack<int> st;
    for (char c : postfix)
    {
        if (isspace(c))
            continue;
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else if (isOperator(c))
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (c == '+')
                st.push(a + b);
            else if (c == '-')
                st.push(a - b);
            else if (c == '*')
                st.push(a * b);
            else if (c == '/')
                st.push(a / b);
        }
    }
    return st.top();
}

int main()
{
    cout << "Choose:\n1. Postfix to Prefix\n2. Prefix to Postfix\n3. Infix to Postfix & Evaluate\n";
    int choice;
    getline(cin, *(new string));
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        string postfix;
        cout << "Enter Postfix Expression: ";
        getline(cin, postfix);
        cout << "Prefix: " << postfixToPrefix(postfix) << endl;
    }
    else if (choice == 2)
    {
        string prefix;
        cout << "Enter Prefix Expression: ";
        getline(cin, prefix);
        cout << "Postfix: " << prefixToPostfix(prefix) << endl;
    }
    else if (choice == 3)
    {
        string infix;
        cout << "Enter Infix Expression (single-digit numbers): ";
        getline(cin, infix);
        string postfix = infixToPostfix(infix);
        cout << "Postfix: " << postfix << endl;
        cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
