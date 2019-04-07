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

    }
    return tab;
}


int* Sort(int* counter, int n){

    int* sort;

    sort = new int[n];
    sort[0] = 0;
    sort[1] = counter [0];

    for (int i = 2; i < n; i++){
        sort[i] = sort[i-1] + counter [i-1];
    }
    return sort;
}

int** SortedTab(int** tab, int* sort, int n){
    int** sortedtab;

    sortedtab = new int *[n];

    for (int i = 0; i < n; i++){
        sortedtab[sort[tab[i][0]]] = new int[2];
        sortedtab[sort[tab[i][0]]][0] = tab[i][0];
        sortedtab[sort[tab[i][0]]][1] = tab[i][1];
        sort[tab[i][0]]++;
    }
    return sortedtab;
}


int* Zero(int n){

    int* tab;

    tab = new int[n];

    for (int i = 0; i < n; i++){
        tab[i] = 0;
    }
    return tab;
}


int* Count(int** tab, int n){

    int* counter;

    counter = Zero(n);

    for (int i = 0; i < n; i++){
        counter[tab[i][0]]++;
    }
    return counter;
}


void Printer0(int** tab, int n){

    for (int i = 0; i < n; i++){

        cout << tab[i][0] << endl;
    }
}


void Printer1(int** tab, int n){

    for (int i = 0; i < n; i++){

        cout << tab[i][0] << "," << tab[i][1] << endl;
    }
}


int main() {

    int n, p;
    int** tab;
    int* counter;
    int** sortedtab;
    int* sort;

    cin >> n;

    tab = Loader(n);

    cin >> p;

    counter = Count(tab, n);
    sort = Sort(counter, n);
    sortedtab = SortedTab(tab, sort, n);

    if (p == 0){
        Printer0(sortedtab, n);
    } else {
        Printer1(sortedtab, n);
    }

    for (int i = 0; i < n; i++){
        delete [] tab[i];
        delete [] sortedtab[i];
    }

    delete [] sort;
    delete [] counter;
    delete [] tab;
    delete [] sortedtab;

    return 0;
}