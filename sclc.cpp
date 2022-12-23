#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
void sum()
{
    int x, y, sum;
    cout << "\nenter first number\n";
    cin >> x;
    cout << "\nenter second number\n";
    cin >> y;
    sum = x + y;
    cout << "sum is" << sum << endl;
}
void product()
{
    int x, y, product;
    cout << "\nenter first number\n";
    cin >> x;
    cout << "\nenter second number\n";
    cin >> y;
    product = x * y;
    cout << "product is" << product << endl;
}
void sub()
{
    int x, y, sub;
    cout << "\nenter first number\n";
    cin >> x;
    cout << "\nenter second number\n";
    cin >> y;
    sub = x - y;
    cout << "subtraction is" << sub << endl;
}
void div()
{
    int x, y, div;
    cout << "\nenter first number\n";
    cin >> x;
    cout << "\nenter second number\n";
    cin >> y;
    div = x / y;
    cout << "division is" << div << endl;
}
void remainder()
{
    int x, y, remainder;
    cout << "\nenter first number\n";
    cin >> x;
    cout << "\nenter second number\n";
    cin >> y;
    remainder = x * y;
    cout << "remainder is" << remainder << endl;
}
void square()
{
    int x, square;
    cout << "\nenter number\n";
    cin >> x;
    square = x * x;
    cout << "square is" << square << endl;
}
void cube()
{
    int x, cube;
    cout << "\nenter number\n";
    cin >> x;
    cube = x * x * x;
    cout << "cube is" << cube << endl;
}
void cos()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = cos(x * PI / 180);
    cout <<  "cosine of " << x << " is " << result << endl;
}
void sin()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = sin(x * PI / 180);
    cout <<  "sine of " << x << " is " << result << endl;
}
void tan()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = tan(x * PI / 180);
    cout <<  "tan of " << x << " is " << result << endl;
}
void cosh()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = cosh(x);
    cout <<  "hyperbolic cosine of " << x << " is " << result << endl;
}
void sinh()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = sinh(x);
    cout <<  "hyperbolic sine of " << x << " is " << result << endl;
}
void tanh()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = tanh(x);
    cout <<  "hyperbolic tangent of " << x << " is " << result << endl;
}
void acos()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = acos(x) * 180.0 / PI;
    cout <<  "arc cosine of " << x << " is " << result << endl;
}
void asin()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = asin(x) * 180.0 / PI;
    cout << " arc sine of " << x << " is " << result << endl;
}
void atan()
{
    double x, result, PI = 3.14159265;
    cout << "\nenter angle\n";
    cin >> x;
    result = tanh(x);
    cout <<  "arc tangential of " << x << " is " << result << endl;
}
void exp()
{
    double x, result;
    cout << "\nenter number\n";
    cin >> x;
    result = exp(x);
    cout <<  "exponential value of " << x << " is = " << result << endl;
}
void log()
{
    double x, result;
    cout << "\nenter value to take x log \n";
    cin >> x;
    result = log(x);
    cout << " logarithm of " << x << " is " << result << endl;
}
void log10()
{
    double x, result;
    cout << "\nenter value to take x log \n";
    cin >> x;
    result = log10(x);
    cout <<  "common logarithm of " << x << " is " << result << endl;
}
void atan2()
{
    float x, y, result, PI = 3.14;
    cout << "\nenter first number\n";
    cin >> x;
    cout << "\nenter second number\n";
    cin >> y;
    result = atan2(x, y) * 180 / PI;
    cout <<  "arc tangent for " << x << " and " << y << " is " << result << endl;
}
void pow()
{
    int x, y, pow1;
    cout << "\nenter number\n";
    cin >> x;
    cout << "\nenter power\n";
    cin >> y;
    pow1 = pow(x, y);
    cout << "\n"
         << x << "raise to power" << y << "is" << pow1;
}
int main3()
{   a:
    system("cls");
    cout << "SCIENTIFIC CALCULATOR" << endl;
    long func;
    cout << "Enter the function you want to perform(+,*,D,-,R,S,C,c,s,t,h,H,T,A,y,d,E,L,l,N,P): \n";
    cout << "Key :\n";
    cout << "`+' is for addition\n";
    cout << "`*' is for multiplication\n";
    cout << "`D' is for division\n";
    cout << "`-' is for subtraction \n";
    cout << "`R' is for remainder\n";
    cout << "`S' is for square\n";
    cout << "`C' is for cube\n";
    cout << "`c' is for cosine\n";
    cout << "`s' is for sine\n";
    cout << "`t' is for tangent\n";
    cout << "`T' is for hyperbolic tangent\n";
    cout << "`h' is for hyperbolic cosine\n";
    cout << "`H' is for hyperbolic sine\n";
    cout << "`A' is for arc cosine\n";
    cout << "`y' is for arc sine\n";
    cout << "`d' is for arc tangential\n";
    cout << "`E' is for exponent\n";
    cout << "`L' is for logarithm\n";
    cout << "`l' is for common logarithm i.e log10\n";
    cout << "`N' is for atan2\n";
    cout << "`P' is for power\n";
    func = getche();
    if (func == '+')
    {
        sum();
        cout << "***\n";
    }
    else if (func == '*')
    {
        product();
        cout << "**\n";
    }
    else if (func == '-')
    {
        sub();
        cout << "**\n";
    }
    if (func == 'D')
    {
        div();
        cout << "*\n";
    }
    else if (func == 'R')
    {
        remainder();
        cout << "***\n";
    }
    else if (func == 'S')
    {
        square();
        cout << "*\n";
    }
    else if (func == 'C')
    {
        cube();
        cout << "**\n";
    }
    else if (func == 'c')
    {
        cos();
        cout << "**\n";
    }
    else if (func == 's')
    {
        sin();
        cout << "***\n";
    }
    else if (func == 't')
    {
        tan();
        cout << "**\n";
    }
    else if (func == 'h')
    {
        cosh();
        cout << "**\n";
    }
    else if (func == 'H')
    {
        sinh();
        cout << "**\n";
    }
    else if (func == 'T')
    {
        tanh();
        cout << "**\n";
    }
    else if (func == 'A')
    {
        acos();
        cout << "*\n";
    }
    else if (func == 'y')
    {
        asin();
        cout << "***\n";
    }
    else if (func == 'd')
    {
        atan();
        cout << "***\n";
    }
    else if (func == 'E')
    {
        exp();
        cout << "**\n";
    }
    else if (func == 'L')
    {
        log();
        cout << "**\n";
    }
    else if (func == 'l')
    {
        log10();
        cout << "*\n";
    }
    else if (func == 'N')
    {
        atan2();
        cout << "*\n";
    }
    else if (func == 'P')
    {
        pow();
        cout << "**\n";
    }
    int i=0;
    cout<<"to do more operation press 1\nto end calculator operation press 2\n";
    cin>>i;
    if(i==1)
    goto a;
    else 
    return 0;
}