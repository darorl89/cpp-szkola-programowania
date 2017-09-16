#include <iostream>
#include <cstring>
using namespace std;

struct stringy{
    char * str;
    int ct;
};

void set_str(stringy & str,const char * pchar);
void show(const stringy & str,int n = 1);
void show(const char input[], int n = 1);

int main()
{
    stringy beany;
    char testing[] = "Rzeczywistosc nie jest taka sama";
    set_str(beany,testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Gotowe");
    return 0;
}

void set_str(stringy & str,const char * pchar){
    strcpy(str.str,pchar);
    str.ct = strlen(str.str);
}

void show(const stringy & str,int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < str.ct; j++){
            cout << str.str[j];
        }
    }
}

void show(const char input[], int n){
    int j = 0;
    for (int i = 0; i < n; ++i)
        while(input[j] != '\0'){
            cout << input[j];
            ++j;
        }
}
