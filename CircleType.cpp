#include <iostream>
#include <cmath>

using namespace std;

class PointType {
private:
    double x;
    double y;

public:
    // Constructors
    PointType() : x(0.0), y(0.0) {}
    PointType(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Getters and Setters
    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    // Print point
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class CircleType {
private:
    PointType center;
    PointType circumferencePoint;

public:
    // Constructors
    CircleType() : center(PointType()), circumferencePoint(PointType()) {}
    CircleType(const PointType& c, const PointType& cp) : center(c), circumferencePoint(cp) {}

    // Getters and Setters
    PointType getCenter() const { return center; }
    PointType getCircumferencePoint() const { return circumferencePoint; }

    void setCenter(const PointType& c) { center = c; }
    void setCircumferencePoint(const PointType& cp) { circumferencePoint = cp; }

    // Calculate the radius
    double calculateRadius() const {
        double xDiff = circumferencePoint.getX() - center.getX();
        double yDiff = circumferencePoint.getY() - center.getY();
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    // Calculate the circumference
    double calculateCircumference() const {
        double radius = calculateRadius();
        return 2 * 3.14 * radius;
    }

    // Calculate the area
    double calculateArea() const {
        double radius = calculateRadius();
        return 3.14 * radius * radius;
    }

    // Print Circle Information
    void printCircleInfo() const {
        double radius = calculateRadius();
        double circumference = calculateCircumference();
        double area = calculateArea();

        cout << "Radius: " << radius << endl;
        cout << "Circumference: " << circumference << endl;
        cout << "Area: " << area << endl;
    }
};

int main() {
    PointType center(0, 0);
    PointType circumferencePoint(1, 0);

    CircleType circle(center, circumferencePoint);

    circle.printCircleInfo();

    return 0;
}
