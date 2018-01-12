#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

constexpr float PI = 3.14159265;
constexpr float MIN_PI = 3.14;

template <typename T>
T toRadians(T degrees)
{
    return degrees * PI / 180;
}

template <typename T>
T toDegrees(T radians)
{
    return (radians * 180) / PI;
}

#endif // MATHS_H_INCLUDED
