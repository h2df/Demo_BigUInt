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

    return 0;
}

void testEqual(bigUInt &u, char *t, char *m) {
    char *rev = strrev(strdup(u.get_p()));
    printf("Testing [%s]\n", m);
    if (strcmp(t, rev)) {
        printf("Expect: %s\n", t);
        printf("Actual: %s\n", rev);
    } else {
        printf("Pass.\n");
    }
    printf("\n");
}

