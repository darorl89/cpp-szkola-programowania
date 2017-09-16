#include <cctype>
#include <iostream>

using namespace std;

int main() {

    string word;
    int alpha,number;
    alpha = number = 0;
    while(cin>>word && word[0] != 'q'){
        if(isalpha(word[0]))
            alpha++;
        if(isdigit(word[0]))
            number++;
    }
    cout << "Litery: " << alpha << endl << "Liczby: " << number << endl;
    return 0;
}

