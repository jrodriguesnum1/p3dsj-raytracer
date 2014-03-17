#include"scene\Scene.h"
#include "scene\Sphere.h"
#include"Raytracer.h"
#include"DrawAPI.h"

#define PI  3.1415926535897f

void test(Scene * s) {
	Ray ray;
	ray.point = glm::vec3(10.0f);
	ray.direction = glm::normalize(glm::vec3(-10.0f));
	s->checkIntersection(&ray);
}

int main(void) {
	int resx = 500;
	int resy = 500;
	Scene scene;
	scene.addObject(new Object(0.0f, 1.0f, 0.0f, new Sphere(0.0f, 0.0f, 0.0f, 1.0f)));
	scene.setCamera(new Camera(glm::vec3(2.0f,0.0f,0.0f), glm::vec3(1.5f,0.0f,0.0f), glm::vec3(0.0f, 1.0f, 0.0f), PI / 2, resx, resy));
	//test(&scene);
	Raytracer raytracer(resx, resy, &scene);
	renderScene(&raytracer, resx, resy);
	return 0;
}