#include "../header.h"

int main() {
    pnode test1 = formLIFO_1();
    display(test1);
    pnode test2;
    formLIFO_2(&test2);
    display(test2);
}
