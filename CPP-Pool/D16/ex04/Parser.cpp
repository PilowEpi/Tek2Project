#include "Parser.hpp"

Parser::Parser()
{
    _result = 0;
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9') ? true : false;
}

bool isOp(char c)
{
    if (c == '+' || c == '-' || c == '(' || c == ')' || c == '*' || c == '/' || c == '%')
        return true;
    return false;
}

int makeDigit(int value, char c)
{
    return ((value * 10) + (c - '0'));
}

int makeOperation(int first, int second, char op)
{
    switch (op) {
        case '+': return (first + second);
        case '-': return (first - second);
        case '*': return (first * second);
        case '%': return (first % second);
    }
    if (second == 0)
        return (0);
    return (first / second);
}

std::string makePostfix(const std::string &calcul)
{
    char c;
    std::ostringstream exp;
    std::stack<char> op;

    for (int i = 0; i < calcul.length(); i++) {
        c = calcul[i];
        if (isDigit(c)) {
            exp << c;
        } else if (isOp(c)) {
            if (c == ')') {
                while (op.top() != '(' && op.size() != 0) {
                    exp << ' ' << op.top();
                    op.pop();
                }
                if (op.size() == 0)
                    return "";
                if (op.top() == '(')
                    op.pop();
            } else if ( c == '(') {
                op.push(c);
            } else {
                op.push(c);
                exp << ' ';
            }
        }
    }
    return (exp.str());
}

void Parser::feed(const std::string&calcul)
{
    int stock = 0;
    int first = 0;
    int second = 0;
    char c;

    std::string postfix = makePostfix(calcul);
    if (postfix == "")
        return;
    for (int i = 0; i < postfix.length(); i++) {
        c = postfix[i];
        if (isDigit(c)) {
            stock = makeDigit(stock, c);
        }
        if (c == ' ' && stock != 0) {
            _operands.push(stock);
            stock = 0;
        }
        if (isOp(c)) {
            first = _operands.top();
            _operands.pop();
            second = _operands.top();
            _operands.pop();
            _operands.push(makeOperation(second, first, c));
        }
    }
    _result += _operands.top();
    _operands.pop();
}
