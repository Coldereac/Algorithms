#include <iostream>
#include <ostream>

/* ready tree (111 to search)
*100
28
-4
0
0
111
0
112
0
0
130
111
0
0
145
0
0
 */
#include "functions.h"
using namespace std;

int main() {
    cout << "Forming a tree..." << endl;
    tree *t = formTree();
    cout << "Straight" << endl;
    displayStraight(t);
    cout << "Symmetrical" << endl;
    displaySymmetrical(t);
    cout << "Reverse" << endl;
    displayReverse(t);
    cout << "Enter element to count in tree" << endl;
    int elem;
    cin >> elem;
    cout << countElem(t, elem) << endl;
    return 0;
}
