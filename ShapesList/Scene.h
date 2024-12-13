#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "Shape.h"
#include "List.h"

using std::cout;
using std::endl;

class Scene
{
	private:
		List<Shape>* list;
		
	public:
		Scene() 
		{
			this->list = new List<Shape>;
		}
		
		bool add(Shape* s)
		{
			list->add(s);
		}
		
		void clear()
		{
			list->clear();
		}
		
		/*virtual*/ void draw()
		{
			cout << "**********  Draw Scene **********" << endl;
			list->start();
			Shape* s;
			while ( (s = list->next()) != nullptr)
				s->draw();
				
			cout << "*********************************" << endl;
		}
		
		void scale(double factor)
		{
			list->start();
			Shape* s;
			while ( (s = list->next()) != nullptr) {
				IScaleable* sc = dynamic_cast<IScaleable*>(s);
				if (sc != nullptr)
					sc->scale(factor);
			}
		}
		
		
		
		/*virtual*/ ~Scene()
		{
			delete list;
		}
		
	
	
};

#endif
