#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H

#include "PointType.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class CircleType : public PointType {
private:
    double radius;
    PointType pointOnCircumference;

public:
    CircleType(double x = 0.0, double y = 0.0, double px = 0.0, double py = 0.0)
        : PointType(x, y), pointOnCircumference(px, py) {
        radius = calculateRadius();
    }

    void setCenter(double x, double y) {
        setPoint(x, y);
        radius = calculateRadius();  // Recalculate radius if needed
    }

    void setPointOnCircumference(double px, double py) {
        pointOnCircumference.setPoint(px, py);
        radius = calculateRadius();  // Recalculate radius
    }

    double getRadius() const { return radius; }

    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    double getArea() const {
        return M_PI * radius * radius;
    }

    void printCircle() const {
        printPoint();
        pointOnCircumference.printPoint();
        cout << "Radius: " << radius << endl;
        cout << "Circumference: " << getCircumference() << endl;
        cout << "Area: " << getArea() << endl;
    }

private:
    double calculateRadius() const {
        double dx = pointOnCircumference.getX() - getX();
        double dy = pointOnCircumference.getY() - getY();
        return sqrt(dx * dx + dy * dy);
    }
};

#endif
