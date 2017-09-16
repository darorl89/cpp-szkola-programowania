#include <iostream>

using namespace std;

const int funct = 4;

double calculate(double, double, double (*pf)(double,double));
double add(double,double);
double divide(double,double);
double multiply(double,double);
double subtraction(double,double);

double (*pf[funct])(double,double) = {add,subtraction,divide,multiply};

int main()
{
    for(int i = 0; i < funct; ++i ){
        double q = calculate(69,13,pf[i]);
        cout << q << endl;
    }
    return 0;
}

double calculate(double a, double b, double (*pf)(double,double)){
    return pf(a,b);
}

double add(double x, double y){
    cout << "Dodawanie: " << x << "+" << y << " = ";
    return x + y;
}

double divide(double x, double y){
    cout << "Dzielenie: " << x << "/" << y << " = ";
    return x/y;
}

double multiply(double x, double y){
    cout << "Mnozenie: " << x << "*" << y << " = ";
    return x*y;
}

double subtraction(double x, double y){
    cout << "Odejmowanie: " << x << "-" << y << " = ";
    return x-y;
}

