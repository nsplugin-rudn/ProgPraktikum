#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Vector2D {
public:
    double x, y;

    Vector2D() {
        x = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;
        y = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;
    }
    Vector2D(double xx, double yy) {
        x = xx;
        y = yy;
    }

    double length() const {
        return sqrt(x * x + y * y);
    }

    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D{x + other.x, y + other.y};
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D{x - other.x, y - other.y};
    }

    bool is_parallel(const Vector2D& other) const {
        return x * other.y == y * other.x;
    }

    static double angle(const Vector2D& v1, const Vector2D& v2) {
        double dot_product = v1.dot(v2);
        double lengths_product = v1.length() * v2.length();
        return acos(dot_product / lengths_product);
    }
};

void print_vector(const Vector2D& v) {
    cout << "(" << v.x << ", " << v.y << ")";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Vector2D v1, v2, v3;

    cout << "Vector v1: "; print_vector(v1); cout << endl;
    cout << "Vector v2: "; print_vector(v2); cout << endl;
    cout << "Vector v3: "; print_vector(v3); cout << endl;

    cout << "Length of v1: " << v1.length() << endl;
    cout << "Length of v2: " << v2.length() << endl;
    cout << "Length of v3: " << v3.length() << endl;

    cout << "Angle between v1 and v2: " << Vector2D::angle(v1, v2) << " radians" << endl;
    cout << "Angle between v1 and v3: " << Vector2D::angle(v1, v3) << " radians" << endl;
    cout << "Angle between v2 and v3: " << Vector2D::angle(v2, v3) << " radians" << endl;

    cout << "Sum of v1 and v2: "; print_vector(v1 + v2); cout << endl;
    cout << "Difference of v1 and v2: "; print_vector(v1 - v2); cout << endl;

    cout << "Sum of v1 and v3: "; print_vector(v1 + v3); cout << endl;
    cout << "Difference of v1 and v3: "; print_vector(v1 - v3); cout << endl;

    cout << "Sum of v2 and v3: "; print_vector(v2 + v3); cout << endl;
    cout << "Difference of v2 and v3: "; print_vector(v2 - v3); cout << endl;

    cout << "v1 and v2 are " << (v1.is_parallel(v2) ? "parallel" : "not parallel") << endl;
    cout << "v1 and v3 are " << (v1.is_parallel(v3) ? "parallel" : "not parallel") << endl;
    cout << "v2 and v3 are " << (v2.is_parallel(v3) ? "parallel" : "not parallel") << endl;

    return 0;
}
