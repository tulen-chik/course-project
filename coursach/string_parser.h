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
    // Удаление пробелов из входной строки
    std::string noSpaces = removeSpaces(infix);

    // Определение приоритета операций
    std::map<std::string, int> precedence;
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = 2;
    precedence["^"] = 3;
    precedence["sin"] = precedence["cos"] = 4;

    std::stack<std::string> stack;
    std::vector<std::string> output;

    // Регулярное выражение для разделения строки на токены
    std::regex re("([\\^+\\-*/()\\s]|sin|cos)|([^\\^+\\-*/()\\s]+)");
    std::sregex_token_iterator it(noSpaces.begin(), noSpaces.end(), re, { 1, 2 });
    std::sregex_token_iterator reg_end;

    for (; it != reg_end; ++it) {
        if (!it->str().empty()) {
            std::string token = it->str();

            // Если токен - это оператор
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos") {
                // Пока стек не пуст и приоритет операции на вершине стека больше или равен приоритету текущего токена
                while (!stack.empty() && precedence.at(stack.top()) >= precedence.at(token)) {
                    // Добавляем операцию из вершины стека в выходной список
                    output.push_back(stack.top());
                    stack.pop();
                }
                // Добавляем текущий токен в стек
                stack.push(token);
            }
            // Если токен - это открывающая скобка
            else if (token == "(") {
                stack.push(token);
            }
            // Если токен - это закрывающая скобка
            else if (token == ")") {
                // Пока на вершине стека не открывающая скобка
                while (stack.top() != "(") {
                    // Добавляем операцию из вершины стека в выходной список
                    output.push_back(stack.top());
                    stack.pop();
                }
                // Удаляем открывающую скобку из стека
                stack.pop();
            }
            // Если токен - это операнд
            else {
                // Добавляем операнд в выходной список
                output.push_back(token);
            }
        }
    }

    // Если в стеке остались операции, добавляем их в выходной список
    while (!stack.empty()) {
        output.push_back(stack.top());
        stack.pop();
    }

    return output;
}

// Функция для вычисления выражения в обратной польской нотации
double evaluateRPN(const std::vector<std::string>& rpn, std::map<std::string, double>& variables) {

    std::stack<double> stack;
    // Обработка каждого токена в выражении
    for (const std::string& token : rpn) {
        // Если токен - это оператор
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos") {
            double operand2 = 0;
            // Если оператор не унарный
            if (token != "sin" && token != "cos") {
                operand2 = stack.top();
                stack.pop();
            }
            double operand1 = stack.top();
            stack.pop();
            // Выполнение соответствующей операции
            if (token == "+") stack.push(operand1 + operand2);
            else if (token == "-") stack.push(operand1 - operand2);
            else if (token == "*") stack.push(operand1 * operand2);
            else if (token == "/") stack.push(operand1 / operand2);
            else if (token == "^") stack.push(std::pow(operand1, operand2));
            else if (token == "sin") stack.push(std::sin(operand1));
            else if (token == "cos") stack.push(std::cos(operand1));
        }
        // Если токен - это операнд
        else {
            // Если операнд - это переменная
            if (variables.find(token) != variables.end()) {
                stack.push(variables[token]);
            }
            // Если операнд - это число
            else {
                stack.push(std::stod(token));
            }
        }
    }

    // Возвращаем результат вычисления выражения
    return stack.top();

}

// Функция для проверки валидности строки
bool isValid(const std::string& str) {
    // Определение допустимых символов
    const std::string validChars = "0123456789+-*/^()sincox ";

    // Если строка пуста, возвращаем false
    if (str.empty())
        return false;

    // Проверка каждого символа в строке
    for (char c : str) {
        if (validChars.find(c) == std::string::npos) {
            // Если символ не допустим, возвращаем false
            return false;
        }
    }

    // Если все символы допустимы, возвращаем true
    return true;
}

// Функция для преобразования строки в число типа double
double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double value;
    // Если преобразование успешно
    if (iss >> value) {
        return value;
    }
    // Если преобразование не удалось
    else {
        std::cerr << "Ошибка преобразования: строка не является корректным представлением числа типа double\n";
        return 0.0; // Возвращаем значение по умолчанию или обрабатываем ошибку по необходимости
    }
}

// Функция для проверки, является ли строка числом
bool isNumeric(const std::string input) {
    // Если строка соответствует регулярному выражению для числа
    if (std::regex_match(input, std::regex(R"([-+]?[0-9]*\.?[0-9]+)"))) {
        return true;
    }
    // Если строка не соответствует регулярному выражению для числа
    else {
        return false;
    }
}
