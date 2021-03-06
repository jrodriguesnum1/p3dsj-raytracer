#include "Sphere.h"
#include<algorithm>

Sphere::Sphere(float x, float y, float z, float r)
	: _center(x,y,z), _radius(r) 
{
	// empty
}

Intersection * Sphere::checkIntersection(Ray * ray) {
	float a = glm::dot(ray->direction,ray->direction);
	glm::vec3 co = (ray->point - _center);
	float b = 2 * glm::dot(ray->direction, co);
	float c = glm::dot(co, co) - (_radius * _radius);

	float discriminant = b * b - 4 * a * c;
	if(discriminant < 0) {
		return nullptr; // there is no intersection
	}

	float t0 = (-b - glm::sqrt(b * b - 4 * a * c)) / (2 * a);
	float t1 = (-b + glm::sqrt(b * b - 4 * a * c)) / (2 * a);
	float t;

	if(t0 < 0 && t1 < 0) {
		return nullptr; // both roots are negative
	}

	if (t0 > 0 && t1 > 0) {
		t = std::min(t0, t1);
	}
	else {
		t = std::max(t0, t1);
	}

	if(t == 0) {
		return nullptr; // the intersection is on the eye
	}

	Intersection * result = new Intersection();
	result->position      = ray->f(t);
	result->normal        = glm::normalize(result->position - _center);
	result->object        = nullptr;
	result->distanceToEye = t;
	
	return result;
}

// Bounding corners of the geometry.
glm::vec3 Sphere::getMaxCorner() {
	return glm::vec3(_center.x + _radius, _center.y + _radius, _center.z + _radius);
}

glm::vec3 Sphere::getMinCorner() {
	return glm::vec3(_center.x - _radius, _center.y - _radius, _center.z - _radius);
}