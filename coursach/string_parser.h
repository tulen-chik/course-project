#pragma once
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <cmath>
#include <vector>
#include <regex>

std::string removeSpaces(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    return str;
}

std::vector<std::string> infixToRPN(const std::string& infix) {
    // �������� �������� �� ������� ������
    std::string noSpaces = removeSpaces(infix);

    // ����������� ���������� ��������
    std::map<std::string, int> precedence;
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = 2;
    precedence["^"] = 3;
    precedence["sin"] = precedence["cos"] = 4;

    std::stack<std::string> stack;
    std::vector<std::string> output;

    // ���������� ��������� ��� ���������� ������ �� ������
    std::regex re("([\\^+\\-*/()\\s]|sin|cos)|([^\\^+\\-*/()\\s]+)");
    std::sregex_token_iterator it(noSpaces.begin(), noSpaces.end(), re, { 1, 2 });
    std::sregex_token_iterator reg_end;

    for (; it != reg_end; ++it) {
        if (!it->str().empty()) {
            std::string token = it->str();

            // ���� ����� - ��� ��������
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos") {
                // ���� ���� �� ���� � ��������� �������� �� ������� ����� ������ ��� ����� ���������� �������� ������
                while (!stack.empty() && precedence.at(stack.top()) >= precedence.at(token)) {
                    // ��������� �������� �� ������� ����� � �������� ������
                    output.push_back(stack.top());
                    stack.pop();
                }
                // ��������� ������� ����� � ����
                stack.push(token);
            }
            // ���� ����� - ��� ����������� ������
            else if (token == "(") {
                stack.push(token);
            }
            // ���� ����� - ��� ����������� ������
            else if (token == ")") {
                // ���� �� ������� ����� �� ����������� ������
                while (stack.top() != "(") {
                    // ��������� �������� �� ������� ����� � �������� ������
                    output.push_back(stack.top());
                    stack.pop();
                }
                // ������� ����������� ������ �� �����
                stack.pop();
            }
            // ���� ����� - ��� �������
            else {
                // ��������� ������� � �������� ������
                output.push_back(token);
            }
        }
    }

    // ���� � ����� �������� ��������, ��������� �� � �������� ������
    while (!stack.empty()) {
        output.push_back(stack.top());
        stack.pop();
    }

    return output;
}

// ������� ��� ���������� ��������� � �������� �������� �������
double evaluateRPN(const std::vector<std::string>& rpn, std::map<std::string, double>& variables) {

    std::stack<double> stack;
    // ��������� ������� ������ � ���������
    for (const std::string& token : rpn) {
        // ���� ����� - ��� ��������
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos") {
            double operand2 = 0;
            // ���� �������� �� �������
            if (token != "sin" && token != "cos") {
                operand2 = stack.top();
                stack.pop();
            }
            double operand1 = stack.top();
            stack.pop();
            // ���������� ��������������� ��������
            if (token == "+") stack.push(operand1 + operand2);
            else if (token == "-") stack.push(operand1 - operand2);
            else if (token == "*") stack.push(operand1 * operand2);
            else if (token == "/") stack.push(operand1 / operand2);
            else if (token == "^") stack.push(std::pow(operand1, operand2));
            else if (token == "sin") stack.push(std::sin(operand1));
            else if (token == "cos") stack.push(std::cos(operand1));
        }
        // ���� ����� - ��� �������
        else {
            // ���� ������� - ��� ����������
            if (variables.find(token) != variables.end()) {
                stack.push(variables[token]);
            }
            // ���� ������� - ��� �����
            else {
                stack.push(std::stod(token));
            }
        }
    }

    // ���������� ��������� ���������� ���������
    return stack.top();

}

// ������� ��� �������� ���������� ������
bool isValid(const std::string& str) {
    // ����������� ���������� ��������
    const std::string validChars = "0123456789+-*/^()sincox ";

    // ���� ������ �����, ���������� false
    if (str.empty())
        return false;

    // �������� ������� ������� � ������
    for (char c : str) {
        if (validChars.find(c) == std::string::npos) {
            // ���� ������ �� ��������, ���������� false
            return false;
        }
    }

    // ���� ��� ������� ���������, ���������� true
    return true;
}

// ������� ��� �������������� ������ � ����� ���� double
double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double value;
    // ���� �������������� �������
    if (iss >> value) {
        return value;
    }
    // ���� �������������� �� �������
    else {
        std::cerr << "������ ��������������: ������ �� �������� ���������� �������������� ����� ���� double\n";
        return 0.0; // ���������� �������� �� ��������� ��� ������������ ������ �� �������������
    }
}

// ������� ��� ��������, �������� �� ������ ������
bool isNumeric(const std::string input) {
    // ���� ������ ������������� ����������� ��������� ��� �����
    if (std::regex_match(input, std::regex(R"([-+]?[0-9]*\.?[0-9]+)"))) {
        return true;
    }
    // ���� ������ �� ������������� ����������� ��������� ��� �����
    else {
        return false;
    }
}
