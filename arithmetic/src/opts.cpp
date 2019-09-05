#include <iostream>
#include "opts.h"

int add(int x, int y) {
    int sum = x ^ y;
    int carry = (x & y) << 1;
    return carry ? add(sum, carry) : sum;
}

int negative(int x) {
    return add(~x, 1);
}

int sub(int x, int y) {
    return add(x, negative(y));
}

int multiply(int x, int y) {
    int ans = 0;
    while (y) {
        if (y & 1) {
            ans = add(ans, x);
        }
        x <<= 1;
        y >>= 1;
    }
    return ans;
}

int divide(int x, int y) {
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (x >> i >= y) {
            ans = add(ans, 1 << i);
            x = sub(x, y << i);
        }
    }
    return ans;
}