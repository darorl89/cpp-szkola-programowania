#include <iostream>

using namespace std;

string toUp(string &);

int main()
{
    cout << "Wprowadz lancuch (q, aby zakonczyc): ";
    string text;
    while(cin >> text && text != "q"){
        toUp(text);
        cout << text << endl;
        cout << "Nastepny lancuch (q, aby zakonczyc): ";
    }
    return 0;
}

string toUp(string & str){
    for (int i = 0; i < str.size(); ++i){
        str[i] = toupper(str[i]);
    }
    return str;
}
