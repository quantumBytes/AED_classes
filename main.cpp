#include <iostream>
#include "headers/Dlist.h"
#include "file_mng/file_managing.h"
#include <vector>

using namespace std;

int main()
{
    Dictionary<DList> myDict;
    myDict.index("dictionary.txt");
//    cout << myDict;
    return 0;
}

