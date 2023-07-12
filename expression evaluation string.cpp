#include <stdio.h>

int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

int evaluateExpression(char *expression) {
    int operandStack[100];
    char operatorStack[100];
    int operandTop = -1;
    int operatorTop = -1;

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        if (expression[i] >= '0' && expression[i] <= '9') {
            int operand = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            operandStack[++operandTop] = operand;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (operatorTop >= 0 && (operatorStack[operatorTop] == '*' || operatorStack[operatorTop] == '/')) {
                int operand2 = operandStack[operandTop--];
                int operand1 = operandStack[operandTop--];
                char operator = operatorStack[operatorTop--];
                int result = performOperation(operand1, operand2, operator);
                operandStack[++operandTop] = result;
            }
            operatorStack[++operatorTop] = expression[i];
            i++;
        } else {
            printf("Invalid character in expression\n");
            return 0;
        }
    }

    while (operatorTop >= 0) {
        int operand2 = operandStack[operandTop--];
        int operand1 = operandStack[operandTop--];
        char operator = operatorStack[operatorTop--];
        int result = performOperation(operand1, operand2, operator);
        operandStack[++operandTop] = result;
    }

    return operandStack[operandTop];
}

int main() {
    char expression[100];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression);

    printf("Result: %d\n", result);

    	return 0;
}

