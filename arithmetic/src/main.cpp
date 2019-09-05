#include <iostream>
#include "hello.h"
#include "opts.h"

using namespace std;

int main() {
    HelloWorld h;
    cout << add(100, -231) << endl;
    cout << sub(100, 231) << endl;
    cout << multiply(2, 4) << endl;
    cout << divide(15, 5) << endl;
}