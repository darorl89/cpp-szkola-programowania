#include <iostream>

using namespace std;

void * insert_scores(int scores[], int tableSize);
void show_scores(int * scores);
double avg_scores(int * scores);

int main()
{
    int scores[3]{0};
    insert_scores(scores, 3);
    show_scores(scores);
    avg_scores(scores);
    return 0;
}

void * insert_scores(int scores[], int tableSize){
    cout << "Wpisz 3 wyniki golfowe : ";
    for (int i = 0; i < tableSize && cin >> scores[i]; ++i){
    }
}
void show_scores(int * scores){
    for(int i = 0; i < 3; ++i)
        cout << "Wynik " << i << " : " << scores[i] << endl;
}

double avg_scores(int * scores){
    int sum = 0;
    for(int i = 0; i < 3; ++i){
        sum += scores[i];
    }
    cout << "Srednia: " << sum / 3;
}
