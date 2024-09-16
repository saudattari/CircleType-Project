#include <iostream>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


class PointType {
protected:
    double x, y;

public:
    PointType(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    void setPoint(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    double getX() const { 
        return x; 
    }
    double getY() const { 
        return y; 
    }

    void printPoint() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

// CircleType class
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

    double getRadius() const { 
        return radius; 
    }

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

// Main function to test the CircleType class
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
