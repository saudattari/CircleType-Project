#ifndef POINTTYPE_H
#define POINTTYPE_H

#include <iostream>
using namespace std;

class PointType {
protected:
    double x, y;

public:
    PointType(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    void setPoint(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    void printPoint() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

#endif
