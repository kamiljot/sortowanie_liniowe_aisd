#include <iostream>
using namespace std;



int** Loader(int n){
    int input = 0;
    int ** tab;
    tab = new int *[n];

    for (int i = 0; i < n; i++){
        tab[i] = new int [2];
        cin >> input;
        tab[i][0] = input;
        cin >> input;
        tab[i][1] = input;
         cout << tab[i][0] << " " << tab[i][1];
    }
    return tab;
}




int main() {

    int n;
    cin >> n;
    Loader(n);


    return 0;
}