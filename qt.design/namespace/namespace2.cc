#include "a.h"
#include "b.h"

int main() {
    using A::f; /* Declaration - brings A::f() into scope. */
    f();
    using namespace B; /* Directive - brings all of B into scope. */
    g();  /* Okay. */
    f();  /* Ambiguous! */
}
/*OUT
f from A
g from B
f from A
*/

