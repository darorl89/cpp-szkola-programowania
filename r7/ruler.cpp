#include <iostream>

using namespace std;
const int x = 66;
const int y = 5;

void subdivide(char ruler[], int low, int high, int level);

int main()
{
    char ruler[x];
    ruler[x-1] = '\0';
    ruler[x-2] = ruler[0] = '|';
    for (int i = 1; i < x - 2; ++i)
        ruler[i] = ' ';
    for (int i = 1; i <= y; ++i){
        subdivide(ruler,0,x-2,i);
        cout << ruler << endl;
    }
    return 0;
}

void subdivide(char ruler[], int low, int high, int level){
    if(level == 0) return;
    int mid = (low + high) / 2;
    ruler[mid] = '|';
    subdivide(ruler, low, mid, level - 1);
    subdivide(ruler, mid, high, level - 1);
}
