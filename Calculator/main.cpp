#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <limits>

char transform(char in) {
    if (in <= 'Z'&& in >= 'A')
        return in - ('Z' - 'z');
}

void flushBuffer() {
    std::cin.clear();
    std::cin.sync();
}

enum opcode {
    null = 0,
    add = 1,
    subtract = 2,
    divide = 3,
    modulus = 4,
    multiply = 5
};

int eval() {
    long long int value1, value2;
    std::string tmp_type;
    opcode type = opcode::null;
    flushBuffer();

    std::cout << "Masukan operasi matematika (add|subtract|multiply|divide|modulus): "; std::getline(std::cin, tmp_type);
    std::transform(tmp_type.begin(), tmp_type.end(), tmp_type.begin(), transform);
    if (tmp_type == "add") type = opcode::add;
    if (tmp_type == "subtract") type = opcode::subtract;
    if (tmp_type == "divide") type = opcode::divide;
    if (tmp_type == "modulus") type = opcode::modulus;
    if (tmp_type == "multiply") type = opcode::multiply;
    if (tmp_type == "exit") {
        std::cout << "Quiting..." << std::endl;
        flushBuffer();
        return 69;
    }

    if (type == opcode::null) {
        std::cout << "Tipe operasi matematika yang anda masukan salah!" << std::endl;
        flushBuffer();
        return 1;
    }

    std::cout << "Masukan angka ke pertama: "; std::cin >> value1;
    if (std::cin.fail()) {
        std::cout << "Invalid long long int value!" << std::endl;
        flushBuffer();
        return 69;
    }

    std::cout << "Masukan angka ke kedua: "; std::cin >> value2;
    if (std::cin.fail()) {
        std::cout << "Invalid long long int value!" << std::endl;
        flushBuffer();
        return 69;
    }

    long long int result;
    switch (type) {
        case opcode::add: {
            result = value1 + value2;
            break;
        }

        case opcode::subtract: {
            result = value1 - value2;
            break;
        }

        case opcode::divide: {
            if (value1 == 0 || value2 == 0) {
                std::cout << "Tidak dapat membagi dengan 0!" << std::endl;
                flushBuffer();
                return 1;
            }

            result = value1 / value2;
            break;
        }

        case opcode::modulus: {
            result = value1 % value2;
            break;
        }

        case opcode::multiply: {
            result = value1 * value2;
            break;
        }
    }

    std::cout << "Hasil operasi " << tmp_type << " yaitu: " << result << std::endl;
    std::cout << std::endl;
    flushBuffer();
    return 0;
}

int main() {
    int result;

    while (true) {
        result = eval();

        // Exit code
        if (result == 69) {
            break;
        }
    }

    return result;
}