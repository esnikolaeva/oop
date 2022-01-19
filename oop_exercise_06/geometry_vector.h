#ifndef GEOMETRY_VECTOR_H
#define GEOMETRY_VECTOR_H 1

#include <utility>
#include <cmath>
#include <iostream>

#include "vertex.h"

template<typename T> 
struct GeometryVector {
	using vertex_t = std::pair<T, T>;
	T p1, p2;

	GeometryVector(T x_cord, T y_cord) : p1{x_cord}, p2{y_cord} {};
	GeometryVector(vertex_t &p1, vertex_t &p2) : p1{p2.first - p1.first},
				p2{p2.second - p1.second} {};
	double operator*(const GeometryVector<T> &a) const {
		return (p1 * a.p1) + (p2 * a.p2);
	}
	GeometryVector<T> &operator=(const GeometryVector<T> &a) {
		p1 = a.p1;
		p2 = a.p2;
		return *this;
	}
};

template<typename T>
double Length(const GeometryVector<T> &vector) {
	return sqrt(vector.p1 * vector.p1 + vector.p2 * vector.p2);
}

template<typename T>
double Length(const std::pair<T, T> &A, 
			  const std::pair<T, T> &B) {
	return sqrt(pow((B.first - A.first), 2) + 
				pow((B.second - A.second), 2));
}

template<typename T>
bool is_parallel(const GeometryVector<T> &A, const GeometryVector<T> &B) {
	return (A.p1 * B.p2) - (A.p2 * B.p1) == 0;
}

#endif //GEOMETRY_VECTOR_H