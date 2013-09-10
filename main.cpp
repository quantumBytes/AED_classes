#include <iostream>
#include "headers/c_list.h"
#include <fstream>

using namespace std;

int main()
{
    int a = 10, b = 20, c = 30, d = 40;
    C_List<int> A;
    A.push_back(a);
//    A.push_front(b);
    A.push_back(c);
    A.push_front(d);

    cout << A << endl;
    A.pop_back();
    cout << A << endl;
    cout << A.find(a) << endl;

    return 0;
}

