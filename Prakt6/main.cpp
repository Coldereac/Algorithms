#include <iostream>
#include <ostream>

/* ready tree (111 to search)
*
100
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

/* Прямий
 *100
 *28
 *-4
 *111
 *112
 *130
 *111
 *145
 */

/* Симетричний
 * -4
 * 28
 * 111
 * 112
 * 100
 * 130
 * 111
 * 145
 */

/* Зворотній
 * -4
 * 112
 * 111
 * 28
 * 111
 * 145
 * 130
 * 100
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
