#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m) {
    float tmp_00 = e_00*m.e_00 + e_10*m.e_01;
    float tmp_10 = e_00*m.e_10 + e_10*m.e_11;
    float tmp_01 = e_01*m.e_00 + e_11*m.e_01;
    float tmp_11 = e_01*m.e_10 + e_11*m.e_11;
    e_00 = tmp_00;
    e_10 = tmp_10;
    e_01 = tmp_01;
    e_11 = tmp_11;
    return *this;
};

float Mat2::det() const{
    return (e_00 * e_11) - (e_01 * e_10);
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    Mat2 m = m1;
    return m *= m2;
};

Mat2 transpose(Mat2 const& m) {
    return Mat2{m.e_00,m.e_01,m.e_10,m.e_11};
};

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    Vec2 b = v;
    b.x = m.e_00*v.x + m.e_10*v.y;
    b.y = m.e_01*v.x + m.e_11*v.y;
    return b;
};

Vec2 operator*(Vec2 const& v, Mat2 const& m) {
    Vec2 b = v;
    b.x = m.e_00*v.x + m.e_10*v.y;
    b.y = m.e_01*v.x + m.e_11*v.y;
    return b;
};

Mat2 inverse(Mat2 const& m) {
    Mat2 t = m;
    float c = 1.0f/m.det();
    t.e_00 = m.e_11*c;
    t.e_01 *= -c;
    t.e_10 *= -c;
    t.e_11 = m.e_00*c;
    return t;
}

Mat2 make_rotation_mat2(float phi) {
    Mat2 rm{float(cos(phi)), float(-sin(phi)), float(sin(phi)), float(cos(phi))};
    return rm;
};

bool operator==(Mat2 const& lhs,  Mat2 const& rhs) {
    bool con1 = (lhs.e_00 == Approx(rhs.e_00)) and (lhs.e_10 == Approx(rhs.e_10));
    bool con2 = (lhs.e_01 == Approx(rhs.e_01)) and (lhs.e_11 == Approx(rhs.e_11));
    if (con1 and con2) {
        return true;
    } else {
        return false;
    }
};

std::ostream& operator<<(std::ostream& c, Mat2 const& m) {
    c << "{" << m.e_00 << ", " << m.e_10 << ", " << m.e_01 << ", " << m.e_11 << "}";
    return c;
}