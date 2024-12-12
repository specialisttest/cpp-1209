#ifndef __SCENE_H__
#define __SCENE_H__

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

const int MAX_SCENE_SIZE = 100;

class Scene
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

		
		/*virtual*/ ~Scene()
		{
			cout << "~Scene()" << endl;
			clear();
			delete[] obj;
		}
		
	
	
};

#endif

