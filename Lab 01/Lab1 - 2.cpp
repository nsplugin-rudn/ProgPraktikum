#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Vector3D {
public:
    double x, y, z;

    Vector3D() {
        x = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;
        y = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;
        z = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;
    }
    
    Vector3D(double xx, double yy, double zz) {
        x = xx;
        y = yy;
        z = zz;
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D cross(const Vector3D& other) const {
        return Vector3D{
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D{x + other.x, y + other.y, z + other.z};
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D{x - other.x, y - other.y, z - other.z};
    }

    bool is_parallel(const Vector3D& other) const {
        Vector3D cross_product = this->cross(other);
        return cross_product.length() == 0;
    }

    static double angle(const Vector3D& v1, const Vector3D& v2) {
        double dot_product = v1.dot(v2);
        double lengths_product = v1.length() * v2.length();
        return acos(dot_product / lengths_product);
    }

    static double triple_product(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) {
        return v1.dot(v2.cross(v3));
    }

    static bool are_coplanar(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) {
        return triple_product(v1, v2, v3) == 0;
    }
};

void print_vector(const Vector3D& v) {
    cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Vector3D v1, v2, v3;

    cout << "Vector v1: "; print_vector(v1); cout << endl;
    cout << "Vector v2: "; print_vector(v2); cout << endl;
    cout << "Vector v3: "; print_vector(v3); cout << endl;

    cout << "Length of v1: " << v1.length() << endl;
    cout << "Length of v2: " << v2.length() << endl;
    cout << "Length of v3: " << v3.length() << endl;

    cout << "Angle between v1 and v2: " << Vector3D::angle(v1, v2) << " radians" << endl;
    cout << "Angle between v1 and v3: " << Vector3D::angle(v1, v3) << " radians" << endl;
    cout << "Angle between v2 and v3: " << Vector3D::angle(v2, v3) << " radians" << endl;

    cout << "Sum of v1 and v2: "; print_vector(v1 + v2); cout << endl;
    cout << "Difference of v1 and v2: "; print_vector(v1 - v2); cout << endl;

    cout << "Sum of v1 and v3: "; print_vector(v1 + v3); cout << endl;
    cout << "Difference of v1 and v3: "; print_vector(v1 - v3); cout << endl;

    cout << "Sum of v2 and v3: "; print_vector(v2 + v3); cout << endl;
    cout << "Difference of v2 and v3: "; print_vector(v2 - v3); cout << endl;

    cout << "v1 and v2 are " << (v1.is_parallel(v2) ? "parallel" : "not parallel") << endl;
    cout << "v1 and v3 are " << (v1.is_parallel(v3) ? "parallel" : "not parallel") << endl;
    cout << "v2 and v3 are " << (v2.is_parallel(v3) ? "parallel" : "not parallel") << endl;

    cout << "v1, v2, and v3 are " << (Vector3D::are_coplanar(v1, v2, v3) ? "coplanar" : "not coplanar") << endl;
    cout << "Triple product of v1, v2, and v3: " << Vector3D::triple_product(v1, v2, v3) << endl;

    return 0;
}
