#include "postfixinfix/postfix_infix.h"
#include "stack/stack.h"
#include <string.h>

bool isOperand(char x) {
    if (
        x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'
    ) {
        return 0;
    }
    return 1;
}

int precedenceInsideStack(char x) {
    if (x == '+' || x == '-') {
        return 2;
    } else if (x == '*' || x == '/') {
        return 4;
    } else if (x == '^') {
        return 5;
    } else if (x == '(') {
        return 0;
    }

    return -1;
}

int precedenceOutsideStack(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 3;
    } else if (x == '^') {
        return 6;
    } else if (x == '(') {
        return 7;
    } else if (x == ')') {
        return 0;
    }

    return -1;
}

char* InfixToPostfix(char* infix) {
    StackArray<char> stack = StackArray<char>(strlen(infix) + 1);
    char* postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (stack.IsEmpty() || precedenceOutsideStack(infix[i]) > precedenceInsideStack(stack.Peek())) {
                stack.Push(infix[i++]);
            } else if (precedenceOutsideStack(infix[i]) == precedenceInsideStack(stack.Peek())) {
                stack.Pop();
                i++;
            } else {
                postfix[j++] = stack.Pop();
            }
        }
    }

    while (!stack.IsEmpty() && stack.Peek() != ')') {
        postfix[j++] = stack.Pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int Eval(char* infix) {
    char* postfix = InfixToPostfix(infix);
    StackArray<int> stack = StackArray<int>(strlen(postfix) + 1);
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            stack.Push(postfix[i]-'0');
        } else {
            x2 = stack.Pop();
            x1 = stack.Pop();
            switch (postfix[i]) {
                case '+':
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1 * x2;
                    break;
                case '/':
                    r = x1 / x2;
                    break;
                case '^':
                    r = 1;
                    for (int j = 0; j < x2; j++) {
                        r *= x1;
                    }
                    break;
            }
            stack.Push(r);
        }
    }

    return stack.Pop();
}
