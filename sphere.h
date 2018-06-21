#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "hitable.h"

class material;

class sphere: public hitable {

 public:
    sphere() {}
 sphere(vec3 cen, vec_type r, material* m) : center(cen), radius(r), material(m){}

    virtual bool hit(const ray& r, vec_type t_min, vec_type t_max, hit_record& rec) const;

    vec3 center;
    vec_type radius;
    material* material;
};


bool sphere::hit( const ray& r, vec_type t_min, vec_type t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;

    vec_type a = dot(r.direction(), r.direction());
    vec_type b = dot(oc, r.direction());
    vec_type c = dot(oc, oc) - radius*radius;

    vec_type discriminant = b*b - a*c;

    if (discriminant > 0){
        vec_type t = (-b - sqrt(b*b - a*c)) / a;

        if (t < t_max && t > t_min){
            rec.t = t;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = material;
            return true;
        }

        t = (-b + sqrt(b*b - a*c)) / a;
        if (t < t_max && t > t_min){
            rec.t = t;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = material;
            return true;
        }
    }

    return false;
}

#endif /* __SPHERE_H__ */
