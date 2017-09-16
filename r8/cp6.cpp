#include <iostream>
#include <cstring>
using namespace std;

template<typename T>T maxn(T tab[],int tabSize);
template <> const char* maxn<const char*>(const char* tab[], int tabSize);
int main()
{
    int tab[5] = {0,2,1,5,10};
    cout << maxn(tab,5);
    const char * ctab[7] = {"co","tam","u","ziom","cb","elo","ASDKAS"};
    cout << maxn(ctab,7);
    return 0;
}

template<typename T>T maxn(T tab[],int tabSize){
    T maxn = tab[0];
    for (int  i = 0; i < tabSize; ++i){
        if(tab[i] > maxn)
            maxn = tab[i];
    }
    return maxn;
}

template <> const char* maxn<const char*>(const char* tab[], int tabSize){
    /*int maxn = 0;
    int j = 0;
    for (int i = 1; i < tabSize; ++i){
        while(tab[i][j] != '\0'){
            if(tab[i-1][j] == '\0'){
                maxn = i;
                break;
            }
            ++j;
        }
    j=0;
    }
    */
    const char *p = tab[0];
    for (int i = 0; i < tabSize; ++i){
        if(strlen(tab[i])>strlen(p))
            p = tab[i];
    }
    return p;
}
