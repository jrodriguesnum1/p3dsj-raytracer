#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "Geometry.h"

class BoundingBox : Geometry {
	glm::vec3 _minCorner;
	glm::vec3 _maxCorner;
public:
	BoundingBox();
	void setDimentions(glm::vec3 &minCorner, glm::vec3 &maxCorner);
	Intersection * checkIntersection(Ray * ray);

	// Update if necessary the min and max corners to contain the 'corner'
	void updateMaxCorner(glm::vec3 &corner);
	void updateMinCorner(glm::vec3 &corner);
	Plane negPlaneX();
	Plane posPlaneX();
	Plane negPlaneY();
	Plane posPlaneY();
	Plane negPlaneZ();
	Plane posPlaneZ();
	Intersection * tMaxX(Ray *ray);
	Intersection * tMaxY(Ray *ray);
	Intersection * tMaxZ(Ray *ray);
};

#endif