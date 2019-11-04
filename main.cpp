#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "biguint.h"
#include "string.h"

using namespace std;
void testEqual(const bigUInt &u, const char *t, const char *m);
int main()
{
    bigUInt a;
    testEqual(a, "0", "default constructor");

    bigUInt b(5);
    testEqual(b, "5", "int constructor");

    bigUInt c(100);
    testEqual(c, "100", "int constructor with trailing 0");

    bigUInt d("1");
    testEqual(d, "1", "str constructor");

    bigUInt e("00100");
    testEqual(e, "100", "str constructor with leading 0 and trailing 0");

    bigUInt f("");
    testEqual(f, "0", "str ctr with empty string");

    bigUInt g("00");
    testEqual(g, "0", "str ctr with 0 string");

    bigUInt h(e);
    testEqual(h, "100", "bigUInt ctr");

    bigUInt i("0");
    i.add(0);
    testEqual(i, "0", "add function with 0");

    bigUInt j(123);
    j.add(1);
    testEqual(j, "124", "add function with num smaller than origin");

    bigUInt k(123);
    k.add(100000);
    testEqual(k, "100123", "add function with num bigger than origin");

    bigUInt l(123);
    l.add(bigUInt(23));
    testEqual(l, "146", "add function bigUInt");

    bigUInt m(123);
    m.add(bigUInt("00"));
    testEqual(m, "123", "add function bigUInt with 0");

    bigUInt n(1);
    n.increment();
    testEqual(n, "2", "increment");

    bigUInt p1("1");
    bigUInt p2("123");
    bigUInt p3(23);
    bigUInt p = p1 + p2 + p3;
    testEqual(p, "147", "add operator");

    testEqual(p1,"1", "add operator does not change operand");
    testEqual(p2,"123", "add operator does not change operand");
    testEqual(p3,"23", "add operator does not change operand");


    bigUInt q1("123");
    bigUInt q2("120");
    bigUInt q3(3);

    bigUInt q = q1 - q2 - q3;
    testEqual(q, "0", "sub operator");    
    testEqual(q1, "123", "sub operator does not change operand");
    testEqual(q2, "120", "sub operator does not change operand");
    testEqual(q3, "3", "sub operator does not change operand");


    bigUInt s1, s2;
    s1 = s2 = bigUInt("123");
    testEqual(s1, "123", "assignment operator");
    testEqual(s2, "123", "assignment operator");


    bigUInt d1(64);
    bigUInt d2("64");
    bigUInt d3 = d1 + d2;
    testEqual(d3, "128", "two 64"); //TODO : failing test cases

    bigUInt d4("99999999999999999999999999999999999999999999999999");
    bigUInt d5(d4);
    d5.increment();
    testEqual(d5, "100000000000000000000000000000000000000000000000000", "huge number increment"); //TODO : failing test cases

    int bigStrSize = 1000000;
    char * bigS1 = new char[bigStrSize];
    for (int i = 0; i < bigStrSize; i++) bigS1[i] = (i < bigStrSize - 1)? '9' : '\0';
    char * bigS2 = new char[bigStrSize];
    for (int i = 0; i < bigStrSize - 1; i++) bigS2[i] = (i < bigStrSize - 2)? '9' : '8';
    bigS2[bigStrSize - 1] = '\0';
    bigUInt d6 = bigUInt(bigS1) - bigUInt(bigS2);
    testEqual(d6, "1", "big string sub");  //TODO : failing test cases

    bigUInt d7("99999999999999999999999999999999999999999999999998");
    bigUInt d8 = d6 - d7;

    cout << bigUInt("12345") << bigUInt("6789") << bigUInt("") << endl; //cout<<
    return 0;
}

void testEqual(const bigUInt &u, const char *t, const char *m)
{
    printf("Testing [%s]\n", m);
    if (strcmp(t, u.get_p()))
    {
        printf("Expect: %s\n", t);
        printf("Actual: %s\n", u.get_p());
    }
    else
    {
        printf("Pass.\n");
    }
    printf("\n");
}
