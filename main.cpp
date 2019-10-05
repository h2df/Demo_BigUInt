#include <iostream>
#include "biguint.h"
#include "string.h"

using namespace std;
void testEqual(bigUInt &u, char *t, char *m);
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



    return 0;
}

void testEqual(bigUInt &u, char *t, char *m) {
    printf("Testing [%s]\n", m);
    if (strcmp(t, u.get_p())) {
        printf("Expect: %s\n", t);
        printf("Actual: %s\n", u.get_p());
    } else {
        printf("Pass.\n");
    }
    printf("\n");
}

