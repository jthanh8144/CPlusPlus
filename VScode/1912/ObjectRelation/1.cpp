#include "Creature.h"

int main(){
    Creature c("Creature", point2D(4, 7));
    cout << c;
    int x = 0, y = 0;
    cout << "Enter new X location for creature: ";
    cin >> x;
    cout << "Enter new Y location for creature: ";
    cin >> y;
    c.moveTo(x, y);
    cout << c;
    return 0;
}