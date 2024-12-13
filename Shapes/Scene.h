#ifndef __SCENE_H__
#define __SCENE_H__

#include <iostream>
#include "Shape.h"
#include "IScaleable.h"
#include "IMoveable.h"

using std::cout;
using std::endl;

const int MAX_SCENE_SIZE = 100;

class Scene : public IScaleable 
{
	private:
		Shape** obj;
		int size;
		
	public:
		Scene()	: size(0) 
		{
			obj = new Shape*[MAX_SCENE_SIZE];
		}
		
		bool add(const Shape* s)
		{
			if (size < MAX_SCENE_SIZE)
			{
				obj[size++] = const_cast<Shape*>(s);
				return true;
			}
			else
				return false;
		}
		
		void clear()
		{
			for(int i = 0; i < size; i++)
				delete obj[i];
			size = 0;
		}
		
		/*virtual*/ void draw()
		{
			cout << "**********  Draw Scene **********" << endl;
			for(int i = 0; i < size; i++)
				obj[i]->draw(); // полиморфизм!!!
				
			cout << "*********************************" << endl;
		}
		
		void scale(double factor) {
			for(int i = 0; i < size; i++){
				IScaleable* s = dynamic_cast<IScaleable*>(obj[i]);
				if (s != NULL) s->scale(factor);
			}
				
		}

		void moveBy(int dx, int dy) {
			for(int i = 0; i < size; i++){
				IMoveable* s = dynamic_cast<IMoveable*>(obj[i]);
				if (s != NULL) s->moveBy(dx, dy);
			}
				
		}
		
		/*virtual*/ ~Scene()
		{
			cout << "~Scene()" << endl;
			clear();
			delete[] obj;
		}
		
	
	
};

#endif

