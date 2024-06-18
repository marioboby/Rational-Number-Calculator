/*
pesoudo code :
Define a function parseInput(input, nom1, denom1, op, nom2, denom2):
    Define a regular expression pattern to match rational number expressions
    Use regex matching to extract numerators, denominator, and operator from the input string
    If regex match succeeds:s
        Set nom1 to the extracted numerator of the first operand
        Set denom1 to the extracted denominator of the first operand or 1 if not provided
        Set op to the extracted operator
        Set nom2 to the extracted numerator of the second operand
        Set denom2 to the extracted denominator of the second operand or 1 if not provided
        Return true
    Else:
        Return false

Define a function calculateSum(nom1, denom1, nom2, denom2):
    Calculate the numerator and denominator of the sum of two rational numbers
    Print the sum

Define a function calculateSubtraction(nom1, denom1, nom2, denom2):
    Calculate the numerator and denominator of the subtraction of two rational numbers
    Print the subtraction

Define a function calculateMultiplication(nom1, denom1, nom2, denom2):
    Calculate the numerator and denominator of the multiplication of two rational numbers
    Print the multiplication

Define a function calculateDivision(nom1, denom1, nom2, denom2):
    Calculate the numerator and denominator of the division of two rational numbers
    Print the division

Define the main function:
    Declare variables: input, nom1, denom1, nom2, denom2, op, choice
    Start an infinite loop
        Print a welcome message
        Prompt the user to enter a rational number operation or type "exit" to quit
        Read the input from the user
        If the input is "exit" or "Exit":
            Print a thank you message and exit the loop
        Else:
            Call parseInput function with input and pass by reference variables for numerator, denominator, and operator
            If parseInput returns true:
                Check the operator:
                    If it is '+', call calculateSum function
                    If it is '-', call calculateSubtraction function
                    If it is '*', call calculateMultiplication function
                    If it is '/', call calculateDivision function
                Break the loop
            Else:
                Print an error message for invalid input and clear the input buffer
    End of loop
End of main function

*/
