#include <cstdlib>
#include <string>
#include <limits>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    // ---------- DATA TYPES ----------
    // Data types define how much memory to set aside
    // for data we want to store

    // Booleans can have a value of true (1), or false (0)
    // Chars store 256 single characters represented by
    // keys on your keyboard
    char myGrade = 'A';

    // There are many integer types with different min
    // and max values
    cout << "Min unsigned short int " <<
            numeric_limits<unsigned short int>::min()
            << endl;
    cout << "Max unsigned short int " <<
            numeric_limits<unsigned short int>::max()
            << endl;
    cout << "Min short int " <<
            numeric_limits<short int>::min()
            << endl;
    cout << "Max short int " <<
            numeric_limits<short int>::max()
            << endl;
    cout << "Min int " <<
            numeric_limits<int>::min()
            << endl;
    cout << "Max int " <<
            numeric_limits<int>::max()
            << endl;
    cout << "Min long " <<
            numeric_limits<long>::min()
            << endl;
    cout << "Max long " <<
            numeric_limits<long>::max()
            << endl;

    // Floating type numbers have decimal places
    cout << "Min float " <<
            numeric_limits<float>::min()
            << endl;
    cout << "Max float " <<
            numeric_limits<float>::max()
            << endl;
    cout << "Min double " <<
            numeric_limits<double>::min()
            << endl;
    cout << "Max double " <<
            numeric_limits<double>::max()
            << endl;
    cout << "Min long double " <<
            numeric_limits<long double>::min()
            << endl;
    cout << "Max long double " <<
            numeric_limits<long double>::max()
            << endl;

    // The float is accurate to 6 digits
    float f1 = 1.1111111;
    float f2 = 1.1111111;

    // Printf allows you to print with formatting
    // Here I say I want to print 7 decimals
    printf("Sum = %.7f\n", (f1 + f2));

    // Doubles have 15 digits of precision
    double d1 = 1.1111111111111111;
    double d2 = 1.1111111111111111;
    printf("Sum 2 = %.16f\n", (d1 + d2));

    // Get the number of bytes assigned to a type
    cout << "int Bytes : " << sizeof(int) << endl;

    // More about printf()
    // char, int, 5 space right justified int,
    // 3 decimal float / double, string specifiers
    printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi");

    // ---------- ARRAYS ----------
    // An array is a collection of data of the same type
    // Declare an array of ints with the value of 1
    // Once the size is defined it can't change
    int arrnNums[10] = {1};

    // Leave out the array length
    int arrnNums2[] = {1,2,3};

    // Create an array and assign some values
    int arrnNums3[5] = {8, 9};

    // Access array values using indexes starting with 0
    cout << "1st Value : " << arrnNums3[0] << endl;

    // Change a value
    arrnNums3[0] = 7;

    // A multidimensional array
    int arrnNums4[2][2][2] = {{{1,2}, {3,4}},{{5,6}, {7,8}}};

    // ---------- STRINGS ----------
    // A C++ string is a series of characters that
    // can be changed
    string str1 = "I'm a string";

    // Get the 1st character
    cout << "1st : " << str1[0] << endl;

    // Get the last character
    cout << "Last : " << str1.back() << endl;

    // Get the string length
    cout << "Length : " << str1.length() << endl;

    // Copy a string to another
    string str2 = str1;

    // Copy a string after the 1st 4 characters
    string str3(str2, 4);

    // Combine strings
    string str4 = str1 + " and your not";

    // Append to the end of a string
    str4.append("!");

    // Erase characters from a string from 1 index
    // to another
    str4.erase(12, str4.length() - 1);
    cout << "New String : " << str4 << endl;

    // find() returns index where pattern is found
    // or npos (End of String)
    if(str4.find("string") != string::npos)
        cout << "String Index : "
             << str4.find("string") << endl;

    // substr(x, y) returns a substring starting at
    // index x with a length of y
    cout << "Substring : "
         << str4.substr(6,6) << endl;

    // Convert int to string
    string strNum = to_string(1+2);
    cout << "I'm a String : " << strNum << "\n";

    // Character functions
    char letterZ = 'z';
    char num5 = '5';
    char aSpace = ' ';
    cout << "Is z a letter or number " <<
            isalnum(letterZ) << endl;
    cout << "Is z a letter " <<
            isalpha(letterZ) << endl;
    cout << "Is 3 a number " <<
            isdigit(num5) << endl;
    cout << "Is space a space " <<
            isspace(aSpace) << endl;

    // ---------- MATH FUNCTIONS ----------
    // There are numerous math functions provided by
    // cmath en.cppreference.com/w/cpp/numeric/math

    cout << "abs(-10) = " << abs(-10) << endl;
    cout << "max(5, 4) = " << max(5, 4) << endl;
    cout << "min(5, 4) = " << min(5, 4) << endl;
    cout << "fmax(5.3, 4.3) = " << fmax(5.3, 4.3) << endl;
    cout << "fmin(5.3, 4.3) = " << fmin(5.3, 4.3) << endl;
    cout << "ceil(10.45) = " << ceil(10.45) << endl;
    cout << "floor(10.45) = " << floor(10.45) << endl;
    cout << "round(10.45) = " << round(10.45) << endl;
    cout << "pow(2,3) = " << pow(2,3) << endl;
    cout << "sqrt(100) = " << sqrt(100) << endl;
    cout << "cbrt(1000) = " << cbrt(1000) << endl;

    // e ^ x
    cout << "exp(1) = " << exp(1) << endl;

    // 2 ^ x
    cout << "exp2(1) = " << exp2(1) << endl;

    // e * e * e ~= 20 so log(20.079) ~= 3
    cout << "log(20.079) = " << log(20.079) << endl;

    // 2 * 2 * 2 = 8
    cout << "log2(8) = " << log2(8) << endl;

    // Hypotenuse : SQRT(A^2 + B^2)
    cout << "hypot(2,3) = " << hypot(2,3) << endl;

    // Also sin, cos, tan, asin, acos, atan, atan2,
    // sinh, cosh, tanh, asinh, acosh, atanh

    // ---------- EXCEPTION HANDLING ----------
    // You try to execute code that could be troublesome
    // and if an error occurs you catch it and throw
    // it to another block of code for handling

    double num3 = 10, num4 = 0;
    try{
        if(num4 == 0){
            throw "Division by Zero Error";
        } else {
            printf("%.1f / %.1f = %.1f", num3, num4,
                    (num3 / num4));
        }
    }

    catch(const char* exp){
        cout << "Error : " << exp << endl;
    }

    // The main function returns a 0 when it has executed
    // without an error
    return 0;
}
