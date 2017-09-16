#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,5> uneven;
    uneven[0] = 1;
    int i,value;
    for(i=1, value = 3 ;i<uneven.size();)
    {
        if(value%2!=0){
            uneven[i]=value;
            value++;
            i++;
        }else{
            value++;
        }
    }
    for(int i = 0; i<uneven.size();i++)
        cout<<uneven[i]<<endl;
}
