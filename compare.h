#pragma once

//
template <class T>
bool compare(const T &a, const T &b) {
    return a.getCoef() < b.getCoef();
}
template <class T>
T& min(const T &a, const T &b) {
    if (a.getCoef() < b.getCoef() ) return a;
    return b;
}
