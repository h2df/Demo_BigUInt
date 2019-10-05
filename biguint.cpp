#include <iostream>
#include "biguint.h"
#include "string.h"

using namespace std;

bigUInt::bigUInt() {
    p = new char[2] {'0', 0};
}

bigUInt::bigUInt(unsigned int n) {
    p = new char[20]; // max int is of 10 digits
    sprintf(p, "%d", n);
    strrev(p);
}

bigUInt::bigUInt(const char *s) {
    int len = strlen(s);
    int i = 0;
    while (s[i] == '0') {
        i++;
    }
    if (i < len) {
        p = strdup(&s[i]);
        strrev(p);
    } else {
        p = new char[2] {'0', 0};
    }
}

bigUInt::bigUInt(const bigUInt &x) {
    p = strdup(x.get_p());
}

bigUInt::~bigUInt() {
    delete[] p;
}

void bigUInt::add(unsigned int n) {

}

void bigUInt::add(const bigUInt &x) {

}

void bigUInt::increment() {

}

void bigUInt::print() {
    strrev(p);
    printf("%s", p);
    strrev(p);
}

bigUInt bigUInt::operator+(const bigUInt &x) {

}

bigUInt bigUInt::operator-(const bigUInt &x) {

}

bigUInt & bigUInt::operator=(const bigUInt &x) {

}

std::ostream & operator<<(std::ostream &out, const bigUInt &x) {

}

int addDigit(char &i, const char j, int carry) {

}

