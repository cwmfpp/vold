
#include <iostream>
#include <set>//test

#include "test.h"
using namespace std;

typedef struct _abcde {
    int a;
    int b;
}abcde;

void func1()
{
    abcde *pabcde = new abcde{.a = 1, .b = 2};
    cout << "a=" << pabcde->a << endl;

    return;
}

void func2()
{

    set<int> iSet;

    iSet.insert(50);
    iSet.insert(98);
    iSet.insert(100);

    set<int>::iterator it;
    for (it = iSet.begin(); it != iSet.end(); it++) {
        cout << "value = " << *it << endl;
    }

    if (iSet.find(1) == iSet.end()) {
        cout << "not find 1" << endl;
    }

    if (iSet.find(100) != iSet.end()) {
        cout << "find 100" << endl;
    }

    return;
}

void test()
{    
    func2();
}
