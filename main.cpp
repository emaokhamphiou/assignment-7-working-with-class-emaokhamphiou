#include <iostream>
#include <cmath>
using namespace std;

class Electric_Field {
    double* E;
public:
    Electric_Field() : E(new double[3]{0}) {}
    Electric_Field(double x, double y, double z) : E(new double[3]{x, y, z}) {}
    ~Electric_Field() { delete[] E; }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    double magnitude() const {
        return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
    }

    double innerProduct(const Electric_Field& other) const {
        return E[0]*other.E[0] + E[1]*other.E[1] + E[2]*other.E[2];
    }
};

class Magnetic_Field {
    double* B;
public:
    Magnetic_Field() : B(new double[3]{0}) {}
    Magnetic_Field(double x, double y, double z) : B(new double[3]{x, y, z}) {}
    ~Magnetic_Field() { delete[] B; }

    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }

    double magnitude() const {
        return sqrt(B[0]*B[0] + B[1]*B[1] + B[2]*B[2]);
    }

    void showUnitVector() const {
        double mag = magnitude();
        cout << "(" << B[0]/mag << ", " << B[1]/mag << ", " << B[2]/mag << ")\n";
    }
};

int main() {
    Electric_Field E1;
    Electric_Field E2(1e5, 10.9, 1.7e2);
    
    E1.setX(2.3); E1.setY(4.5); E1.setZ(1.1);
    
    cout << "E1 Magnitude: " << E1.magnitude() 
         << "\nE2 Magnitude: " << E2.magnitude()
         << "\nInner Product: " << E1.innerProduct(E2) << "\n\n";

    Magnetic_Field B1;
    Magnetic_Field B2(0.4, 0.3, 0.9);
    
    B1.setX(1.0); B1.setY(0.5); B1.setZ(0.2);
    
    cout << "B1 Magnitude: " << B1.magnitude()
         << "\nB2 Magnitude: " << B2.magnitude()
         << "\nB2 Unit Vector: ";
    B2.showUnitVector();

    return 0;
}
