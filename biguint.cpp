#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "biguint.h"
#include "string.h"

using namespace std;
int addDigits(char *i, const char *j);
int subDigits(char *i, const char *j);
void opStr(char *&origin, const char *s, int op(char *, const char *));

bigUInt::bigUInt () : p(new char[2])
{
    p[0] = '0';
    p[1] = 0;
}

bigUInt::bigUInt(unsigned int n) : p(new char[10])
{
    sprintf(p, "%d", n);
}

bigUInt::bigUInt(const char *s)
{
    int len = strlen(s);
    int i = 0;
    while (s[i] == '0')
    {
        i++;
    }
    if (i < len)
    {
        p = new char[len - i + 1];
        strcpy(p, &s[i]);
    }
    else
    {
        p = new char[2];
        p[0] = '0';
        p[1] = 0;
    }
}

bigUInt::bigUInt(const bigUInt &x)
{
    p = new char[strlen(x.p) + 1];
    strcpy(p, x.p);
}

bigUInt::~bigUInt()
{
    delete[] p;
}

void bigUInt::add(unsigned int n)
{
    char *s = new char[80];
    sprintf(s, "%d", n);
    opStr(p, s, addDigits);
    delete[] s;
}

void bigUInt::add(const bigUInt &x)
{
    opStr(p, x.p, addDigits);
}

void bigUInt::increment()
{
    opStr(p, "1", addDigits);
}

void bigUInt::print()
{
    cout << p;
}

bigUInt bigUInt::operator+(const bigUInt &x)
{
    bigUInt r(*this);
    r.add(x);
    return r;
}

bigUInt bigUInt::operator-(const bigUInt &x)
{
    bigUInt r(*this);
    opStr(r.p, x.p, subDigits);
    return r;
}

bigUInt &bigUInt::operator=(const bigUInt &x)
{
    delete[] p;
    p = new char[strlen(x.p) + 1];
    strcpy(p, x.p);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const bigUInt &x)
{
    out << x.get_p();
    return out;
}

void opStr(char *&origin, const char *s, int(op)(char *, const char *))
{
    int olen = strlen(origin);
    int slen = strlen(s);

    int digits = (olen > slen ? olen : slen) + 1; // longer operand + possible carriage
    char *newo = new char[digits + 1];
    newo[digits] = 0;
    char *news = new char[digits + 1];
    news[digits] = 0;

    for (int i = 0; i < digits; i++)
    { //padding operands to same length with '0'
        if (i < (digits - olen))
            newo[i] = '0';
        else
            newo[i] = origin[i - (digits - olen)];

        if (i < (digits - slen))
            news[i] = '0';
        else
            news[i] = s[i - (digits - slen)];
    }
    delete[] origin;

    //recursively add each digits
    newo[0] = op(newo, news) + '0';
    if (newo[0] < '0')
    {
        cout << "invalid subtraction";
        exit(1);
    }
    else if (newo[0] > '1')
    {
        cout << "Overflow (Debugging purpose. This should never happen.)";
        exit(1);
    }

    //clean up the leading 0s
    int i = 0;
    while (newo[i] == '0')
        i++;
    if (i < digits)
    {
        origin = new char[digits + 1  - i];
        strcpy(origin, &newo[i]);
    }
    else
    {
        origin = new char[2];
        origin[0] = '0';
        origin[1] = 0;
    }
    delete[] newo;
    delete[] news;
}

int addDigits(char *i, const char *j)
{
    if (*i == 0)
        return 0;
    else
    {
        char *i2 = i + 1;
        const char *j2 = j + 1;
        int r = *i - '0' + *j - '0' + addDigits(i2, j2);
        *i = r % 10 + '0';
        return r > 9;
    }
}

int subDigits(char *i, const char *j)
{
    if (*i == 0)
        return 0;
    else
    {
        char *i2 = i + 1;
        const char *j2 = j + 1;
        int r = *i - '0' - (*j - '0') + subDigits(i2, j2);
        *i = (r > 0 ? r : -r) + '0';
        return -(r < 0);
    }
}
