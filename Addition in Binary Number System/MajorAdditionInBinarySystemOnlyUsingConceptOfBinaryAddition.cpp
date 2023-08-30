// In this method we actually use concept of binary addition to add two binary numbers
// To understand it, properly go through notebook

#include <iostream>
using namespace std;

string reverse (string ans){
    string rev_ans = "";
    int size = ans.length();
    for(int i = size-1; i >= 0; i--){
        rev_ans.push_back(ans[i]);
    }
    return (rev_ans);
}

string seperator_integral(string binary){
    int point = binary.find('.');
    int size = binary.length();
    if (point == -1){
        point = size;
    }
    string integral = "";
    for(int i = 0; i < point; i++){
        integral += binary[i];
    }
    return integral;
}
string seperator_decimal (string binary){
    int point = binary.find('.');
    int size = binary.length();
    if (point == -1){
        return "0";
    }
    string after_point = "";
    for (int i = point+1; i < size; i++){
        after_point += binary[i];
    }
    return after_point;
}

string addition(string a, string b, int prevCarry){
    string ans = "";

    for (int i = a.length()-1; i >= 0; i--){
        if (a[i] == '0' && b[i] == '0'){
            ans += to_string(prevCarry);
            prevCarry = 0;
        }
        else if ((a[i] =='0' && b[i] == '1') || (a[i] == '1' && b[i] =='0')){
            if (prevCarry == 1){
                ans += '0';
                prevCarry = 1;
            }
            else {
                ans += '1';
            }
        }
        else {
            ans += to_string(prevCarry);
            prevCarry= 1; 
        }
    }
    if (prevCarry == 1){
        ans += '1';
    }
    return reverse(ans);
}

void addBinary (string bin1, string bin2){
    int prevCarry = 0;
    string a = seperator_decimal(bin1);
    string b = seperator_decimal(bin2);

    while (true){
        if (a.length() > b.length()){
            b.push_back('0');
        }
        else if (a.length() < b.length()){
            a.push_back('0');
        }
        else {
            break;
        }
    }

    string part1 = addition(a, b, prevCarry);

    // Instead of using this method you can make prevCarry as global variable
    if (part1.length() > a.length()){ // If length has increased then prevcarry is 1;
        prevCarry = 1;
        part1.erase(0,1); // At first positing and deleting only 1 character
    }

    string c = seperator_integral(bin1);
    string d = seperator_integral(bin2);

    while(true){
        if (c.length() > d.length()){
            d = reverse(d);
            d.push_back('0');
            d = reverse(d);
        }
        else if (c.length() < d.length()){
            c = reverse(c);
            c.push_back('0');
            c = reverse(c);
        }
        else {
            break;
        }
    }
    string part2 = addition (c, d, prevCarry);
    
    cout << bin1 << " + " << bin2 << " = " << part2 + "." << part1 << endl;
    return;
}

int main(){
    string bin1, bin2;
    char op;
    cout << "Enter the first binary Number = ";
    cin >> bin1;
    cout << "Enter the second binary Number = ";
    cin >> bin2;
    
    addBinary(bin1, bin2);
    
    return 0;
}