#include <iostream>
#include "vec3.h"

int main() {
    //DO NOT CHANGE THIS CODE IN YOUR FINAL SUBMISSION
    //IT'S OUTPUT IS WHAT YOU'LL BE GRADED ON

    using Vec3f = Vec3<float>;
    using Vec3d = Vec3<double>;

    Vec3f a;    //shouldn't initialize values
    a.setX(4.0f);
    a.setY(2.0f);
    a.setZ(4.0f);

    std::cout << a << std::endl;

    //should set x, y, z to 3.0f
    Vec3f b = {3.0f};
    std::cout << b << std::endl;

    //should set x =1.0f, y = 2.0f, z = 3.0f
    Vec3f c = {1.0f, 2.0f, 3.0f};
    std::cout << c << std::endl;

    //c gets c + (a + b)
    c += a + b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    //c get c - (b - a);
    c -= b - a;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    //d get a copy of c
    Vec3f d(c);
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    d = c / 2;
    std::cout << d << std::endl;

    //e initialized to all 0's
    Vec3d e {0.0f};

    e.setY(4.0);
    std::cout << e << std::endl;

    e = e * 2;
    std::cout << e << std::endl;

    //Vec3++ and ++Vec3 rotate xyz to the right
    //i.e. Make X = Z, Y = X, Z = Y

    //Vec3-- and --Vec3 rotate xyz to the left
    //i.e. Make X = Y, Y = Z, Z = X

    //f initialized to e++
    Vec3d f {e++};
    std::cout << e << std::endl;
    std::cout << f << std::endl;

    //g initialized to ++e;
    Vec3d g {++e};
    std::cout << e << std::endl;
    std::cout << g << std::endl;

    Vec3d h {e--};
    std::cout << e << std::endl;
    std::cout << h << std::endl;

    Vec3d i {--e};
    std::cout << i << std::endl;
    std::cout << e << std::endl;

    f.setX(5.0);
    f.setY(2.3);
    f.setZ(5.1);
    g.setX(1.2);
    g.setY(5.1);
    g.setZ(94.2);

    double dotP = f.dot(g);
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << dotP << std::endl;

    f *= 8;
    std::cout << f << std::endl;
    f.setX(4.0);
    f.setY(4.0);
    f.setZ(4.0);
    f /= 2;
    std::cout << f << std::endl;

    Vec3d j {f};
    if(j == f) {
        std::cout << "Equal" << std::endl;
    }
    else {
        std::cout << "Not Equal" << std::endl;
    }

    if(j != g) {
        std::cout << "Not Equal" << std::endl;
    }
    else {
        std::cout << "Equal" << std::endl;
    }

}