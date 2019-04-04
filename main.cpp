#include <iostream>
using namespace std;

struct node{
    int numb;
    node* next;
};

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
//test         cout << tab[i][0] << " " << tab[i][1];
    }
    return tab;
}

node** Sort(int** tab, int n){
    node** sor;
    sor = new node*[n - 1];

    for (int i = 0; i < n; i++){
        sor[i] = nullptr;
    }

    for (int i = 0; i < n; i++){
        cout << tab[i][0] << endl;
        sor[tab[i][0]]->next = sor[tab[i][0]];
        cout << sor[tab[i][0]] << endl;
        sor[tab[i][0]]->numb = i;
        cout << sor[tab[i][0]]->numb << endl;
    }

    return sor;

}

void Printer0(int** tab, int n){
    for (int i = 0; i < n; i++){
        cout << tab[i][0] << endl;
    }
}

void Printer1(int** tab, int n){
    for (int i = 0; i < n; i++){
        cout << tab[i][0] << " " << tab[i][1] << endl;
    }
}

void TestPrinter(node* sor){
    while (sor != nullptr){
        cout << sor->numb << endl;
        sor = sor->next;
    }
}



int main() {

    int n;
    int** tab;
    node** sor;
    cin >> n;
    tab = Loader(n);
    sor = Sort(tab, n);

    for (int i = 0; i < n; i++){
        TestPrinter(sor[i]);
    }


    Printer0(tab, n);
    Printer1(tab, n);

    delete [] tab[0];
    delete [] tab[1];

    return 0;
}
