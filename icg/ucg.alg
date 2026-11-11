Algorithm: Generation of Three Address Code
Step 1: Start the program.

Step 2: Declare an operator stack to store operators and a value stack to store operands and temporary variables.

Step 3: Read the result variable and arithmetic expression from the user. Initialize top = -1, vtop = -1 and temp = 1.

Step 4: Define the precedence() function:
- Check the given operator.
- If the operator is * or /, return 2.
- If the operator is + or -, return 1.
- Otherwise, return 0.
Step 5: Define the generate() function:
- Pop the top operator from the operator stack.
- Pop the second operand and store it in b.
- Pop the first operand and store it in a.
- Create a new temporary variable using the temp counter.
- Generate and print the instruction t = a operator b.
- Push the generated temporary variable back into the value stack.
Step 6: Start a loop to scan the arithmetic expression character by character until the end of the expression is reached.

Step 7: Check whether the current character is an operand using isalnum().
- If it is an operand, push it into the value stack.
- Add the null character '\0' to mark the end of the stored string.
Step 8: If the current character is an operator, check whether the operator stack is empty.
- If the stack is not empty, compare the precedence of the top operator with the current operator.
- If the top operator has higher or equal precedence, call the generate() function.
- Repeat this until the condition becomes false.
- Push the current operator into the operator stack.
Step 9: After scanning the complete expression, check whether the operator stack is empty.
- If it is not empty, call the generate() function.
- Repeat until all operators are processed and the operator stack becomes empty.
Step 10: Take the final value from the value stack and print the final assignment in the form result = final_value.

Step 11: Stop the program.