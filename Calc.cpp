/*File: CS112_A2_T3_S7_20230305_20230127_20230138.cpp
Purpose: program that deal with rational numbers and perform simple operations on it
 authors
     name: Hamza Omar Saad Ahmad
     ID : 20230127
     work done :addition and subtraction ,pesoudo code
     email : Hamzaaomar2005@gmail.com

    name: Radwan Fouad Ahmad Fouad
    ID : 20230138
    work done :division and multiplication
     email :radwanfouad12345@gmail.com

    name: Mario Saber Shawqy Michael
    ID : 20230305
    work done : input handling and validation , menu , Output handling
     email :sabermario160@gmail.com


 section : S7
 pesoudo code is found below
 */

#include <iostream>
#include <string>
#include <regex>
#include <limits>

using namespace std;

// Function to parse input and extract operands, operator, and denominators
bool parseInput(const string &input, long long &nom1, long long &denom1, char &op, long long &nom2, long long &denom2)
{
    // Regular expression pattern to match rational number expressions
    regex pattern("\\s*(\\+?-?\\d+)(?:/(\\+?-?\\d*))?\\s+([-+*/])\\s+(\\+?-?\\d+)(?:/(\\+?-?\\d*))?\\s*");

    smatch matches; // Container for matched results

    // If input matches the pattern
    if (regex_match(input, matches, pattern))
    {
        // Extracting operands and operator from the matched groups
        nom1 = stoi(matches[1]); // Numerator of the first operand
        denom1 = matches[2].matched ? stoi(matches[2]) : 1; // Denominator of the first operand (defaulted to 1 if not provided)
        op = matches[3].str()[0]; // Operator
        nom2 = stoi(matches[4]); // Numerator of the second operand
        denom2 = matches[5].matched ? stoi(matches[5]) : 1; // Denominator of the second operand (defaulted to 1 if not provided)

        // Checking for division by zero scenarios
        if (denom1 == 0 && denom2 == 0)
        {
            cout << "Error: Division by zero in both operands." << endl;
            return false;
        }
        else if (denom1 == 0 || denom2 == 0)
        {
            cout << "Error: Division by zero." << endl;
            return false;
        }
        else if (op == '/' && nom2 == 0)
        {
            cout << "Error: Division by zero." << endl;
            return false;
        }
        return true;
    }
    else
    {
        cout << "Error: Invalid input format or operator. An example for a valid format: x/y (+,-,*,/) z/w " << endl << endl;
        return false;
    }
}

void calculateSum(long long nom1, long long denom1, long long nom2, long long denom2)
{
    // Calculating the numerator and denominator of the result
    long long nom_res = nom1 * denom2 + denom1 * nom2;
    long long denom_res = denom1 * denom2;

    cout << "The sum is: ";

    // Displaying the result in the reduced form
    if (nom_res % denom_res == 0)
        cout << nom_res / denom_res << endl; // Output whole number if result is an integer
    else if (nom_res < 0 && denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as positive fraction if both numerator and denominator are negative
    else if (denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as negative fraction if denominator is negative
    else
        cout << nom_res << "/" << denom_res << endl; // Output as positive fraction
}

// Function to calculate the subtraction of two rational numbers
void calculateSubtraction(long long nom1, long long denom1, long long nom2, long long denom2)
{
    // Calculating the numerator and denominator of the result
    long long nom_res = (nom1 * denom2) - (denom1 * nom2);
    long long denom_res = denom1 * denom2;

    cout << "The subtraction is: "; // Output message

    // Displaying the result in the reduced form
    if (nom_res % denom_res == 0)
        cout << nom_res / denom_res << endl; // Output whole number if result is an integer
    else if (nom_res < 0 && denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as positive fraction if both numerator and denominator are negative
    else if (denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as negative fraction if denominator is negative
    else
        cout << nom_res << "/" << denom_res << endl; // Output as positive fraction
}

// Function to calculate the multiplication of two rational numbers
void calculateMultiplication(long long nom1, long long denom1, long long nom2, long long denom2)
{
    // Calculating the numerator and denominator of the result
    long long nom_res = nom1 * nom2;
    long long denom_res = denom1 * denom2;

    cout << "The multiplication is: "; // Output message

    // Displaying the result in the reduced form
    if (nom_res % denom_res == 0)
        cout << nom_res / denom_res << endl; // Output whole number if result is an integer
    else if (nom_res < 0 && denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as positive fraction if both numerator and denominator are negative
    else if (denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as negative fraction if denominator is negative
    else
        cout << nom_res << "/" << denom_res << endl; // Output as positive fraction
}

// Function to calculate the division of two rational numbers
void calculateDivision(long long nom1, long long denom1, long long nom2, long long denom2)
{
    // Calculating the numerator and denominator of the result
    long long nom_res = nom1 * denom2;
    long long denom_res = denom1 * nom2;

    cout << "The division is: "; // Output message

    // Displaying the result in the reduced form
    if (nom_res % denom_res == 0)
        cout << nom_res / denom_res << endl; // Output whole number if result is an integer
    else if (nom_res < 0 && denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as positive fraction if both numerator and denominator are negative
    else if (denom_res < 0)
        cout << - nom_res << "/" << - denom_res << endl; // Output as negative fraction if denominator is negative
    else
        cout << nom_res << "/" << denom_res << endl; // Output as positive fraction
}

int main()
{
    string input;
    long long nom1, denom1, nom2, denom2;
    char op;

    cout << "Welcome to the Rational Number Calculator!" << endl;

    // Main loop to continuously accept input until 'E' or 'e' is entered
    while (true)
    {
        cout << "Please enter a rational number operation (or 'E' to exit): ";
        getline(cin, input);
        cout << endl;

        if (input == "e" || input == "E")
        {
            cout << "Thank you for using the Rational Number Calculator!" << endl;
            break;
        }
        else
        {
            if (parseInput(input, nom1, denom1, op, nom2, denom2))
            {
                // Performing the corresponding operation based on the operator
                switch (op)
                {
                case '+':
                    calculateSum(nom1, denom1, nom2, denom2);
                    break;
                case '-':
                    calculateSubtraction(nom1, denom1, nom2, denom2);
                    break;
                case '*':
                    calculateMultiplication(nom1, denom1, nom2, denom2);
                    break;
                case '/':
                    calculateDivision(nom1, denom1, nom2, denom2);
                    break;
                default:
                    cout << "Error: Invalid operator. Please enter a valid operator (+, -, *, /)." << endl; // Error message
                    break;
                }
            }
        }
    }

    return 0;
}


