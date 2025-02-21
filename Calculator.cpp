//Coded and debugged by Rieley Dechenne as a personal project while being a student at Gonzaga University.
// Rieley Dechenne 2/18/25

#include <iostream>
#include <cmath>

using namespace std;

double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double exponentiation(double base, double exponent);
double mod(int a, int b);

int main() {
    double a, b, calc_result;
    char operation;

    cout << "***********************************" << endl;
    cout << "Welcome to a simple C++ Calculator!" << endl;
    cout << "***********************************" << endl;
    
    cout << "Please enter your first number: " << endl;
    cin >> a;
    
    cout << "Please enter the operator you would like to use: (+, -, *, /, ^, %)" << endl;
    cin >> operation;

    cout << "Please enter your second number: " << endl;
    cin >> b;

    switch(operation) {
        case '+':
            calc_result = addition(a, b);
            break;
        case '-':
            calc_result = subtraction(a, b);
            break;
        case '*':
            calc_result = multiplication(a, b);
            break;
        case '/':
            if(b != 0)
                calc_result = division(a, b);
            else{
                cout << "Cannot divide by 0!" << endl;
                return 0;
            }
            break;
        case '^':
            calc_result = exponentiation(a, b);
            break;
        case '%':
            if (b != 0)
                calc_result = mod(a, b);
            else{
                cout << "Cannot compute modulus with a zero!" << endl;
                return 0;
            }
            break;
        default:
            cout << "Invalid Operator!" << endl;
            return 0;
    }

    cout << "Result: " << calc_result << endl;
    return 0;
}
double addition(double a, double b){
    return a + b;
}
double subtraction(double a, double b){
    return a - b;
}
double multiplication(double a, double b){
    return a * b;
}
double division(double a, double b){
    return a / b;
}
double exponentiation(double base, double exponent){
    return pow(base, exponent);
}
double mod(int a, int b){
    return a % b;
}