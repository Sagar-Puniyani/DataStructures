#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

// Map of number words to digits
unordered_map<string, int> wordToNum = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3},
    {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
    {"eight", 8}, {"nine", 9}
};

// Map of operations
unordered_map<string, char> operations = {
    {"add", '+'}, {"sub", '-'}, {"mul", '*'},
    {"div", '/'}, {"rem", '%'}, {"pow", '^'}
};

// Function to parse a number from the word format (e.g., "oneczero" -> 10)
int parseWordNumber(string word) {
    stringstream ss(word);
    string numWord;
    int result = 0;

    while (getline(ss, numWord, 'c')) {
        if (wordToNum.find(numWord) == wordToNum.end()) {
            return -1;  // Invalid word in the number
        }
        result = result * 10 + wordToNum[numWord];  // Construct the number digit by digit
    }

    return result;
}

// Function to evaluate an expression
int evaluateExpression(vector<string>& tokens) {
    vector<int> operands;
    char currentOp = 0;

    for (const string& token : tokens) {
        // Check if the token is an operation
        if (operations.find(token) != operations.end()) {
            if (currentOp != 0) {
                // More than one operation before operands, incomplete expression
                return -1;
            }
            currentOp = operations[token];
        } 
        // Otherwise, check if it's a number
        else {
            int number = parseWordNumber(token);
            if (number == -1) {
                // Invalid number
                return -2;
            }
            operands.push_back(number);

            // Perform the operation if we have enough operands
            if (currentOp != 0 && operands.size() >= 2) {
                int b = operands.back(); operands.pop_back();
                int a = operands.back(); operands.pop_back();
                int result;

                switch (currentOp) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': if (b == 0) return -3; result = a / b; break;  // Division by zero check
                    case '%': result = a % b; break;
                    case '^': result = pow(a, b); break;
                    default: return -4;  // Invalid operation
                }

                operands.push_back(result);  // Push result back for further evaluation
                currentOp = 0;  // Reset current operation
            }
        }
    }

    // If there are leftover operands or an incomplete expression
    if (operands.size() != 1 || currentOp != 0) {
        return -5;  // Expression incomplete or invalid
    }

    return operands.back();  // Return the final result
}

int main() {
    string input;
    getline(cin, input);  // Read the input expression
    cout << "input expression : " << input  << endl;

    // Split input into tokens (space-separated words)
    stringstream ss(input);
    string token;
    vector<string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    // Check and evaluate the expression
    int result = evaluateExpression(tokens);

    if (result == -1 || result == -2) {
        cout << "expression evaluation stopped invalid words present" << endl;
    } else if (result == -3) {
        cout << "division by zero error" << endl;
    } else if (result < 0) {
        cout << "expression is not complete or invalid" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
