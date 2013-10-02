#include <iostream>
#include "headers/avl_tree.h"
#include <math.h>

using namespace std;

int fds(void *k, int tam) {
    char *p = (char *)((string &) k)->c_str();
    int s = 0;
    while(*p) {
        s += *p;
        p++;
    }
    return s%tam;
}

int main()
{
    Hash<Persona, string, fds> A;
    A.add(Persona("0131", "Juan"), "0131");
    A.add(Persona("3141", "Juan"), "3141");
    cout << A.find("3141") << endl;

/************* Árbol AVL *************/
//    AVL_tree<int> Tr;
//    int ins = 50;
//    Tr.insert(ins);
//    Tr.printPre();
//    ins = 10;
//    Tr.insert(ins);
//    Tr.printPre();
//    ins = 60;
//    Tr.insert(ins);
//    Tr.printPre();
//    ins = 55;
//    Tr.insert(ins);
//    Tr.printPre();
//    ins = 70;
//    Tr.insert(ins);
//    Tr.printPre();
//    ins = 57;
//    Tr.insert(ins);
//    Tr.printPre();

/*************** Árbol Binario ***************/
//    BinTree<int> abc;
//    int tmp;

//    tmp = 50;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 30;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 20;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 70;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 80;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 75;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 90;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;
//    tmp = 0;   abc.add(tmp);
//    abc.printIn();  cout << abc.height() << endl;

//    cout << endl << abc.nodeCount() << endl;

//    cout << abc.leafCount() << endl;

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

