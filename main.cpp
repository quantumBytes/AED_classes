#include <iostream>
#include "headers/BinTree.h"
#include <math.h>

using namespace std;

int main()
{
    BinTree<int> abc;
    int tmp;

    tmp = 50;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 30;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 20;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 70;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 80;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 75;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 90;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;
    tmp = 0;   abc.add(tmp);
    abc.printIn();  cout << abc.height() << endl;


/**** Inserccion y eliminacion de nodos ****/
//    BinTree<int> abc;
//    int n = 10,
//        tmp;
//    for(int i = 1; i < n; i++) {
//        tmp = i*(n-i) + pow(-1, i) * ((n*i) % i); //tmp = n*(n-i) + pow(-1, i) * n;
//        abc.add(tmp);
//        abc.printPre();
//        abc.remove(tmp);
//        abc.printPre();
//    }


/****    Diccionario e Index  ********/
//    Dictionary<DList> myDict;
//    myDict.index("dictionary.txt");
//    cout << myDict;

    return 0;
}

