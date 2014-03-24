#include <iostream>

#include "scene/Scene.h"
#include "scene/Sphere.h"
#include "scene/Triangle.h"
#include "scene/Intersection.h"
#include "Raytracer.h"
#include "DrawAPI.h"
#include "NFFLoader.h"


void test(Scene * s) {
	int resx = 500;
	int resy = 500;
	Ray ray;
	s->addObject(new Object(glm::vec3(0.0f, 1.0f, 0.0f), 0.50f, 1.0f, 50.0f, 0.9f, 1.2f, new Sphere(0.0f, 0.0f, 0.0f, 1.0f)));
	s->addObject(new Object(glm::vec3(0.0f, 0.0f, 1.0f), 0.50f, 2.0f, 50.0f, 0.9f, 1.2f, new Sphere(1.0f, 0.5f, 0.0f, 1.0f)));
	s->addObject(new Object(glm::vec3(1.0f, 0.0f, 0.0f), 0.50f, 1.0f, 50.0f, 0.9f, 1.2f, new Sphere(2.0f, 0.7f, 0.5f, 0.1f)));
	s->addLight(createLight(glm::vec3(10.0f), glm::vec3(1.0f)));
	//s->addLight(createLight(glm::vec3(4.0f,0.0f,5.0f), glm::vec3(1.0f)));
	s->setCamera(new Camera(glm::vec3(4.0f, 0.0f, 0.0f), glm::vec3(1.5f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), PI / 2, resx, resy));
	ray.point = glm::vec3(2.0f,0.0f,0.0f);
	ray.direction = glm::normalize(glm::vec3(0.0f, 1.2f, 0.0f) - ray.point);
	s->checkIntersection(&ray);
}

void printVec3(glm::vec3 vec) {
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
}

void testTriangle(Scene * s) {
	int resx = 500;
	int resy = 500;
	s->addObject(new Object(
		glm::vec3(0.0f, 1.0f, 0.0f), 0.50f, 1.0f, 50.0f, 1.0f, 1.2f,
		new Triangle(glm::vec3(0,0,0),glm::vec3(0,1,0),glm::vec3(0,0,1))));
	s->addLight(createLight(glm::vec3(10.0f), glm::vec3(1.0f)));
	s->setCamera(new Camera(glm::vec3(4.0f, 0.0f, 0.0f), glm::vec3(1.5f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), PI / 2, resx, resy));
	/*
	Ray ray;
	ray.point = glm::vec3(1.0f,0.0f,0.0f);
	ray.direction = glm::normalize(glm::vec3(-1.0f, 0.0f, 0.0f));
	Intersection *i = nullptr;
	if( (i = s->checkIntersection(&ray)) != nullptr) {
		printVec3(i->position);
	} else {
		std::cout << "Nao intersecta." << std::endl;
	}*/
}

int main(int argc, char *argv[]) {
	char * fileName = "resources/balls_low.nff";
	// read the file name from the argument if any given
	if(argc >= 2) {
		fileName = argv[1];
	}
	
	std::cout << argc << ": " << fileName << std::endl;
	/** /
	Scene * scene = new Scene();
	test(scene);
	/**/
	Scene * scene = new Scene();
	testTriangle(scene);
	/**/
	//Scene * scene = NFFLoader::createScene(fileName);
	Raytracer raytracer(scene);
	renderScene(&raytracer, scene->resX(), scene->resY());
	/**/
	return 0;
}