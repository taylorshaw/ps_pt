#include <math.h>
#include <stdlib.h>
#include <iostream>

typedef float vec_type;

class vec3 {

 public:
    vec3() {}
    vec3( vec_type e0, vec_type e1, vec_type e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
    inline vec_type x() const { return e[0]; }
    inline vec_type y() const { return e[1]; }
    inline vec_type z() const { return e[2]; }

    inline vec_type r() const { return e[0]; }
    inline vec_type g() const { return e[1]; }
    inline vec_type b() const { return e[2]; }

    inline const vec3& operator+() const { return *this; }
    inline vec3 operator-() const { return vec3( -e[0], -e[1], -e[2] ); }
    inline vec_type operator[](int i) const { return e[i]; }
    inline vec_type& operator[](int i) { return e[i]; }

    inline vec3& operator+=(const vec3 &v2);
    inline vec3& operator-=(const vec3 &v2);
    inline vec3& operator*=(const vec3 &v2);
    inline vec3& operator/=(const vec3 &v2);

    inline vec3& operator*=(const vec_type t);
    inline vec3& operator/=(const vec_type t);

    inline vec_type length() const {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    }

    inline vec_type squared_length() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    inline void make_unit_vector();

    vec_type e[3]; // try changing to double
    
};


inline std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const vec3 &t) {
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

inline void vec3::make_unit_vector() {
    vec_type k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] + v2.e[0],
                v1.e[1] + v2.e[1],
                v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] - v2.e[0],
                v1.e[1] - v2.e[1],
                v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] * v2.e[0],
                v1.e[1] * v2.e[1],
                v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] / v2.e[0],
                v1.e[1] / v2.e[1],
                v1.e[2] / v2.e[2]);
}

inline vec3 operator*(vec_type t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, vec_type t) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator/(const vec3 &v, vec_type t) {
    return vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}


inline vec_type dot(const vec3 &v1, const vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3( (v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
                -(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0]),
                 (v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]) );
}


inline vec3& vec3::operator+=(const vec3 &v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3 &v){
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

inline vec3& vec3::operator/=(const vec3 &v){
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3 &v){
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec_type t){
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

inline vec3& vec3::operator/=(const vec_type t){
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
    return *this;
}

inline vec3 unit_vector(vec3 v){
    return v / v.length();
}


vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0 * vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
        
    } while( p.squared_length() >= 1.0 );

    return p;
}

vec3 reflect( const vec3& v, const vec3& n ) {
    return v - 2*dot(v,n) * n;
}
