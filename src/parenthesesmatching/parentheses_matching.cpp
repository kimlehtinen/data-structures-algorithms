#include <string.h>
#include "parentheses_matching.h"
#include "stack/stack.h"

bool AreParenthesesBalanced(char* expression) {
    if (expression == nullptr) {
        return false;
    }

    StackArray<char> stack(strlen(expression));

    int i;
    for (i=0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            stack.Push(expression[i]);
        } else if (expression[i] == ')') {
            if (stack.IsEmpty()) {
                return false;
            }
            stack.Pop();
        }
    }

    return stack.IsEmpty();
}
