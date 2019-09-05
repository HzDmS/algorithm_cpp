#include <iostream>
#include "hello.h"

using namespace std;

HelloWorld::HelloWorld() {
    cout << "Hello World!" << endl;
}

HelloWorld::~HelloWorld() {
    cout << "Bye World!" << endl;
}