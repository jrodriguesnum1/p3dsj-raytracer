#include "Scene.h"
#include <float.h>

Scene::Scene() : _objects(), _lights() {}

// If no intersection was found returns null
Intersection * Scene::checkIntersection(Ray * ray) {
	std::vector<Object*>::iterator it;
	Intersection * intersectionPoint;
	Intersection * result = nullptr;
	float minDist = FLT_MAX;
	for(it = _objects.begin(); it != _objects.end(); it++) {
		intersectionPoint = (*it)->checkIntersection(ray);
		if(intersectionPoint != nullptr && intersectionPoint->distanceToEye < minDist) {
			result = intersectionPoint;
			minDist = result->distanceToEye;
		}
	}
	return result;
}

void Scene::addObject(Object * object) {
	_objects.push_back(object);
}

void Scene::addLight(Light * light) {
	_lights.push_back(light);
}

void Scene::setCamera(Camera * camera) {
	_camera = camera;
}

Camera *  Scene::getCamera() {
	return _camera;
}