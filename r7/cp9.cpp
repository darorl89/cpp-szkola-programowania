#include <iostream>
using namespace std;

const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);

void display2(const student * ps);

void display3(const student pa[], int n);

int main()
{
    cout << "Podaj wielkosc grupy: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; ++i){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Gotowe\n";
    return 0;
}

int getinfo(student pa[], int n){
    cout << "Wprowadz dane o studentach: " << endl;
    int i;
    for (i = 0; i < n; ++i){
        cout << "Imie nr " << i+1 << ": ";
        cin.getline(pa[i].fullname,SLEN);
        cout << "Hobby dla numeru " << i+1 << ": ";
        cin.getline(pa[i].hobby,SLEN);
        cout << "Ooplevel numer " << i+1 << ": ";
        cin >> pa[i].ooplevel;
        cin.ignore();
    }
    return i;
}

void display1(student st){
    cout << "Oto twoj student: (display1)" << endl;
    cout << st.fullname << ", " << st.hobby << ", " << st.ooplevel << ".\n";
}

void display2(const student * ps){
    cout << "Oto twoj student: (display2)" << endl;
    cout << ps->fullname << ", " << ps->hobby << ", " << ps->ooplevel << ".\n";
}

void display3(const student pa[], int n){
    for (int i = 0; i < n; ++i){
        cout << "Student nr " << i+1 << ": " << pa[i].fullname << ", " << pa[i].hobby << ", " << pa[i].ooplevel << ".\n";
    }
}
