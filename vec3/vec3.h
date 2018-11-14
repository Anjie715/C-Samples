//
// Created by Brian Swenson on 1/29/18.
//

#pragma once
#include <iostream>


template<typename T>
class Vec3 {
public:
//fill in here

    Vec3(){};

    Vec3(T a){
        x = a;
        y = a;
        z = a;
    }

    Vec3(T a, T b, T c): x(a), y(b), z(c){
        x = a;
        y = b;
        z = c;
    }

    void setX( T a ){
        x = a;
    }
    void setY( T b ){
        y = b;
    }
    void setZ( T c ){
        z = c;
    }

    Vec3 &operator=(const Vec3& v){
        x =v.x;
        y =v.y;
        z =v.z;
    }

    Vec3 operator += (const Vec3& v){
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3 operator -= (const Vec3& v){
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vec3 operator / (T v) const {
        return Vec3<T>(x/v, y/v, z/v);
    }

    Vec3 operator * (T v) const {
        return Vec3<T>(x*v, y*v, z*v);
    }

    Vec3 operator + (const Vec3& v) const {
        return Vec3<T>(x+v.x, y+v.y, z+v.z);
    }

    Vec3 operator - (const Vec3& v) const {
        return Vec3<T>(x-v.x, y-v.y, z-v.z);
    }

    const Vec3 operator ++(int){
        Vec3 temp = *this;
        T k = temp.z;
        z = temp.y;
        y = temp.x;
        x = k;
        return temp;
    }

    const Vec3& operator ++(){
        Vec3 temp = *this;
        T k = temp.z;
        z = temp.y;
        y = temp.x;
        x = k;
        return *this;
    }

    const Vec3 operator --(int){
        Vec3 temp = *this;
        T k = temp.x;
        x = temp.y;
        y = temp.z;
        z = k;
        return temp;
    }

    const Vec3& operator --(){
        Vec3 temp = *this;
        T k = temp.x;
        x = temp.y;
        y = temp.z;
        z = k;
        return *this;
    }

    T dot(const Vec3 v)const {
        return x*v.x + y*v.y + z*v.z;
    }

    Vec3 operator *= (T v){
        x = x*v;
        y = y*v;
        z = z*v;
        return *this;
    }

    Vec3 operator /= (T v){
        x = x/v;
        y = y/v;
        z = z/v;
        return *this;
    }

    bool operator ==(const Vec3& v)  const{
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator != (const Vec3& v) const {
        return x!=v.x || y!=v.y || z!=v.z;
    }

    T getX() const{
        return x ;
    }
    T getY() const{
        return y;
    }
    T getZ() const{
        return z;
    }

private:
    T x;
    T y;
    T z;
};

//for printing
template<typename T>
std::ostream& operator<<(std::ostream& stream, const Vec3<T>& vec) {
    stream << "X=" << vec.getX() << ", Y=" << vec.getY() << ", Z=" << vec.getZ();
    return stream;
}