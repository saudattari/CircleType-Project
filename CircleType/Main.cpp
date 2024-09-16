#include "PointType.h"
#include "CircleType.h"
#include <iostream>
using namespace std;

int main() {
    CircleType circle(2.0, 3.0, 5.0, 7.0);

    cout << "Circle Details:" << endl;
    circle.printCircle();

    circle.setCenter(1.0, 1.0);
    circle.setPointOnCircumference(4.0, 5.0);

    cout << "\nUpdated Circle Details:" << endl;
    circle.printCircle();

    return 0;
}
