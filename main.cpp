#include <iostream>
#include "headers/BinTree.h"
#include <math.h>

using namespace std;

int main()
{
    BinTree<int> abc;
    int n = 10,
        tmp;
    for(int i = 1; i < n; i++) {
        tmp = n*(n-i) + pow(-1, i) * n;
        abc.add(tmp);
    }

    abc.printPre();
    cout << abc.height() << endl;


/**** Inserccion y eliminacion de nodos ****/
//    BinTree<int> abc;
//    int n = 10,
//        tmp;
//    for(int i = 1; i < n; i++) {
//        tmp = i*(n-i) + pow(-1, i) * ((n*i) % i);
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

