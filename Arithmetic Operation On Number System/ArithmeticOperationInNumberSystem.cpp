// In this Method, we first convert given number system to decimal number system
// Then perform operations on it and again converting the result back to given number system

/**** It might show some error at some point and might may be less accurate at some point ****/
/* Because of using 'stod' */

#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;
string Bin_Dec(string binary){
    string result = ""; // An empty string
    double decimal = 0.0;
    int point = binary.find("."); //Returns index
    int size = binary.length(); //Returns Number of character

    // If point (.) is not present (-1)
    if (point == -1){
        point = size - 1; // starting from the last character
    }
    else {
        point--; // moving to the character before point(.)
    }

    // Instead of using below loop, you can directly calculate decimal number (Only integral value) by using:--- 
    // decimal = stoi(binary, 0, 2); // '2' decides that it is for binary
    // Below Loop is for calculating integral part only
    int n = 0; //power will start from zero and will increase
    for (int i = point; i >= 0; i--){
        // Concatenating '-' character at the beginning of an empty string 'result'
        if (binary[i] == '-'){
            result.push_back('-');
            break;
        }
        // Checking that given input is correct or not before performing calculation
        if (binary[i] == '0' || binary[i] == '1'){
            decimal += (binary[i] - '0')*pow(2,n);
            n++;
        }
        else {
            return "ERROR! Wrong Input";
        }
    }

    // Below Loop is for calculation of part, which is after decimal point only
    n = -1; //power will start from -1 and will decrease
    for (int i = point + 2; i <= size-1; i++){
        // Checking that given input is correct or not before performing calculation
        if (binary[i] == '0' || binary[i] == '1'){
            decimal += (binary[i] - '0')*pow(2,n);
            n--;
        }
        else {
            return "ERROR! Wrong Input";
        }
    }
    result += to_string(decimal);
    return result;
}

string Oct_Dec(string octal){
    string result = ""; // An empty string
    double decimal = 0.0;
    int point = octal.find("."); //Returns index
    int size = octal.length(); //Returns Number of character

    // If point (.) is not present (-1)
    if (point == -1){
        point = size - 1; // starting from the last character
    }
    else {
        point--; // moving to the character before point(.)
    }

    // Instead of using below loop, you can directly calculate decimal number (Only integral value) by using:--- 
    // decimal = stoi(octal, 0, 8); // '8' decides that it is for octal
    // Below Loop is for calculating integral part only
    int n = 0; //power will start from zero and will increase
    for (int i = point; i >= 0; i--){
        // Concatenating '-' character at the beginning of an empty string 'result'
        if (octal[i] == '-'){
            result.push_back('-');
            break;
        }
        // Checking that given input is correct or not before performing calculation
        if (octal[i] >= '0' && octal[i] <= '7'){
            decimal += (octal[i] - '0')*pow(8,n);
            n++;
        }
        else {
            return "ERROR! Wrong Input";
        }
    }
    // Below Loop is for calculation of part, which is after decimal point only
    n = -1; //power will start from -1 and will decrease
    for (int i = point + 2; i <= size-1; i++){
        // Checking that given input is correct or not before performing calculation
        if (octal[i] >= '0' && octal[i] <= '7'){
            decimal += (octal[i] - '0')*pow(8,n);
            n--;
        }
        else {
            return "ERROR! Wrong Input";
        }
    }
    result += to_string(decimal);
    return result;
}

string Hex_Dec(string hexa){
    string result = "";
    double decimal = 0.0;
    int point = hexa.find("."); //Returns index
    int size = hexa.length(); //Returns Number of character

    // If point (.) is not present (-1)
    if (point == -1){
        point = size - 1; // starting from the last character
    }
    else {
        point--; // moving to the character before point(.)
    }

    // Instead of using below loop, you can directly calculate decimal number (Only integral value) by using:--- 
    // decimal = stoi(hexa, 0, 16); // '16' decides that it is for hexa
    // Below Loop is for calculating integral part only
    int n = 0; //power will start from zero and will increase
    for (int i = point; i >= 0; i--){
        // Concatenating '-' character at the beginning of an empty string 'result'
        if (hexa[i] == '-'){
            result.push_back('-');
            break;
        }
        // Condition for number 0-9
        if (hexa[i] >= '0' && hexa[i] <= '9'){
            decimal += (hexa[i] - '0')*pow(16,n);
            n++;
        }
        // Condition for character A-F
        else if (hexa[i] >= 'A' && hexa[i] <= 'F'){
            decimal += (hexa[i] - 'A' + 10)*pow(16,n);
            n++;
        }
        else {
            return "ERROR! Wrong Input";
        }
    }

    // Below Loop is for calculation of part, which is after decimal point only
    n = -1; //power will start from -1 and will decrease
    for (int i = point + 2; i <= size-1; i++){
        // Condition for number 0-9
        if (hexa[i] >= '0' && hexa[i] <= '9'){
            decimal += (hexa[i] - '0')*pow(16,n);
            n--;
        }
        // Condition for character A-F
        else if (hexa[i] >= 'A' && hexa[i] <= 'F'){
            decimal += (hexa[i] - 'A' + 10)*pow(16,n);
            n--;
        }
        else {
            return "ERROR! Wrong Input";
        }
    }
    result += to_string(decimal);
    return result;
}

string Dec_Bin(string decimal){
    if (decimal == "ERROR! Wrong Input"){
        return "ERROR! Wrong Input";
    }
    string binary = ""; // An empty string
    // Solving the integral part (before point)
    int part1 = stoi(decimal); // Storing integral part of decimal value in part1
    int remainder = 0;
    while (part1 != 0){
        if (part1 < 0){
            part1 = -part1; // Changing the sign to positive, if input is negative
        }
        remainder = part1 % 2;
        binary += to_string(remainder);
        part1 /= 2;
    }

    // Concatenating '-' sign if given decimal number is negative
    if (decimal[0] == '-'){
        binary.push_back('-');
    }

    // Reversing the String
    // Can also use 'reverse(binary.begin(), binary.end());' to reverse a string directly by including <bits/stdc++.h>
    string rev_binary;
    int size1 = binary.length();
    for (int i = size1-1; i >= 0; i--){
        rev_binary.push_back(binary[i]);
    }

    binary = rev_binary;
    
    // Extracting value after the point from the string 'decimal' and storing it in part2
    int size2 = decimal.length();
    int point = decimal.find('.');
    if (point == -1){
        return binary;
    }
    int temp = 0;
    for (int i = point+1; i <= size2-1; i++){
        temp = temp*10  + (decimal[i] - '0');
    }
    double part2 = temp / pow(10,size2-1-point);

    double rem;
    // Solving for number after the point
    for (int i = 1; i <= 15 && part2 != 0; i++){
        // Firstly pushing '.' sign at the end of string before starting solving 
        if (i == 1){
            binary.push_back('.');
        }
        rem = part2 * 2;
        binary += to_string(int(rem));
        part2 = rem - int(rem);
    }
    return binary;
}

string Dec_Oct (string decimal){
    if (decimal == "ERROR! Wrong Input"){
        return "ERROR! Wrong Input";
    }
    string octal = ""; // An empty string

    // Solving the integral part (before point)
    int part1 = stoi(decimal); // Storing integral part of decimal value in part1
    int remainder = 0;
    while (part1 != 0){
        if (part1 < 0){
            part1 = -part1; // Changing the sign to positive, if input is negative
        }
        remainder = part1 % 8;
        octal += to_string(remainder);
        part1 /= 8;
    }

    // Concatenating '-' sign if given decimal number is negative
    if (decimal[0] == '-'){
        octal.push_back('-');
    }

    // Reversing the String
    // Can also use 'reverse(octal.begin(), octal.end());' to reverse a string directly by including <bits/stdc++.h>
    string rev_octal;
    int size1 = octal.length();
    for (int i = size1-1; i >= 0; i--){
        rev_octal.push_back(octal[i]);
    }

    octal = rev_octal;
    
    // Extracting value after the point from the string decimal and storing it in part2
    int point = decimal.find('.');
    int size2 = decimal.length();
    if (point == -1){
        return octal;
    }
    int temp = 0;
    for (int i = point+1; i <= size2-1; i++){
        temp = temp*10  + (decimal[i] - '0');
    }
    double part2 = temp / pow(10,size2-1-point);
    
    double rem;
    // Solving for number after the point
    for (int i = 1; i <= 15 && part2 != 0; i++){
        // firstly pushing '.' sign at the end of string before starting solving 
        if (i == 1){
            octal.push_back('.');
        }
        rem = part2 * 8;
        octal += to_string(int(rem));
        part2 = rem - int(rem);
    }
    return octal;
}

string Dec_Hex (string decimal){
    if (decimal == "ERROR! Wrong Input"){
        return "ERROR! Wrong Input";
    }
    string hexa = ""; // An empty string

    // Solving the integral part (before point)
    int part1 = stoi(decimal); // Storing integral part of decimal value in part1
    int remainder = 0;
    while (part1 != 0){
        if (part1 < 0){
            part1 = -part1; // Changing the sign to positive, if input is negative
        }
        remainder = part1 % 16;
        //
        if (remainder >= 0 && remainder <= 9){
            hexa += to_string(remainder);
        }
        else if (remainder >= 10 && remainder <= 15){
            hexa += ('A' + (remainder - 10)); // Bracket part is already a string
        }
        part1 /= 16;
    }

    // Concatenating '-' sign if given decimal number is negative
   if (decimal[0] == '-'){
        hexa.push_back('-');
    }

    // Reversing the String
    // Can also use 'reverse(hexa.begin(), hexa.end());' to reverse a string directly by including <bits/stdc++.h>
    string rev_hexa;
    int size1 = hexa.length();
    for (int i = size1-1; i >= 0; i--){
        rev_hexa.push_back(hexa[i]);
    }

    hexa = rev_hexa;
    
    // Extracting value after the point from the string decimal and storing it in part2
    int point = decimal.find('.');
    int size2 = decimal.length();
    if (point == -1){
        return hexa;
    }
    int temp = 0;
    for (int i = point+1; i <= size2-1; i++){
        temp = temp*10  + (decimal[i] - '0');
    }
    double part2 = temp / pow(10,size2-1-point);
    
    double rem;
    // Solving for number after the point
    for (int i = 1; i <= 15 && part2 != 0; i++){
        // firstly pushing '.' sign at the end of string before starting solving 
        if (i == 1){
            hexa.push_back('.');
        }
        rem = part2 * 16;
        if (rem >= 0.0 && rem <= 9.0){
            hexa += to_string(int(rem));
        }
        else if (rem >= 10.0 && rem <= 15.0){
            hexa += ('A' + (int(rem) - 10));
        }
        part2 = rem - int(rem);
    }
    return hexa;
}

int main(){
    cout << "Arithmetic Operations (+, -, *, /) On Special Number System"
    "\n1. Binary Number System"
    "\n2. Octal Number System"
    "\n3. Hexadecimal Number System\n";
    int option;
    
    cout << "Choose: ";
    cin >> option;

    string num1, num2;
    char ch;

    if (option == 1){
        cout << "Enter first Binary Number: ";
        cin >> num1;
        cout << "Operation (+ - * /): ";
        cin >> ch;
        cout << "Enter second Binary Number: ";
        cin >> num2;
        if (ch == '+'){
            cout << "Result = " << Dec_Bin(to_string(stod(Bin_Dec(num1))+stod(Bin_Dec(num2))));
        }
        else if (ch == '-'){
            cout << "Result = " << Dec_Bin(to_string(stod(Bin_Dec(num1))-stod(Bin_Dec(num2))));
        }
        else if (ch == '*'){
            cout << "Result = " << Dec_Bin(to_string(stod(Bin_Dec(num1))*stod(Bin_Dec(num2))));
        }
        else if (ch == '/'){
            cout << "Result = " << Dec_Bin(to_string(stod(Bin_Dec(num1))/stod(Bin_Dec(num2))));
        }
        else {
            cout << "Wrong Input!" << endl;
        }
    }

    else if (option == 2){
        cout << "Enter first Octal Number: ";
        cin >> num1;
        cout << "Operation (+ - * /): ";
        cin >> ch;
        cout << "Enter second Octal Number: ";
        cin >> num2;
        if (ch == '+'){
            cout << "Result = " << Dec_Oct(to_string(stod(Oct_Dec(num1))+stod(Oct_Dec(num2))));
        }
        else if (ch == '-'){
            cout << "Result = " << Dec_Oct(to_string(stod(Oct_Dec(num1))-stod(Oct_Dec(num2))));
        }
        else if (ch == '*'){
            cout << "Result = " << Dec_Oct(to_string(stod(Oct_Dec(num1))*stod(Oct_Dec(num2))));
        }
        else if (ch == '/'){
            cout << "Result = " << Dec_Oct(to_string(stod(Oct_Dec(num1))/stod(Oct_Dec(num2))));
        }
        else {
            cout << "Wrong Input!" << endl;
        }
    }

    else if (option == 3){
        cout << "Enter first Hexadecimal Number: ";
        cin >> num1;
        cout << "Operation (+ - * /): ";
        cin >> ch;
        cout << "Enter second Hexadecimal Number: ";
        cin >> num2;
        if (ch == '+'){
            cout << "Result = " << Dec_Hex(to_string(stod(Hex_Dec(num1))+stod(Hex_Dec(num2))));
        }
        else if (ch == '-'){
            cout << "Result = " << Dec_Hex(to_string(stod(Hex_Dec(num1))-stod(Hex_Dec(num2))));
        }
        else if (ch == '*'){
            cout << "Result = " << Dec_Hex(to_string(stod(Hex_Dec(num1))*stod(Hex_Dec(num2))));
        }
        else if (ch == '/'){
            cout << "Result = " << Dec_Hex(to_string(stod(Hex_Dec(num1))/stod(Hex_Dec(num2))));
        }
        else {
            cout << "Wrong Input!" << endl;
        }
    }
    else {
        cout << "Wrong Input!" << endl;
    }

    cout << "\n\npress any key to exit" << endl;
    getch();

    return 0;
}