#include <iostream>

#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Scene.h"

int main(int argc, char** argv) {
	Scene* pScene = new Scene();
	pScene->add(new Point(10, 20, "green"));
	pScene->add(new Circle(100, 200, 50, "red"));
	
	pScene->draw();
	
	pScene->scale(1.5);
	
	pScene->draw();
	
	pScene->clear();
	pScene->add(new Point(1, 2, "green"));
	pScene->add(new Circle(5, 6, 50, "red"));
	pScene->draw();
	
	delete pScene;
	}
