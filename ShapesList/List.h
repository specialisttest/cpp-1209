#ifndef LIST_H
#define LIST_H

template<class T>
class List
{
	private:
		template<class T1>
		class Node
		{
			private:
				T1* value;
				Node<T1>* next;
			public:
				Node(T1* _value)
				: value(_value), next(0) {}
				
				T1*  get() const
				{ return this->value; }
				
				~Node() {
					delete value;
				}
			
			friend class List<T1>;	
				
		};
		
	private:
		Node<T>* first;
		Node<T>* pointer;
		Node<T>* last;
	public:
		List()
			: first(0), last(0), pointer(0) {}
			
		void add(T* v)
		{
			Node<T>* newNode = new Node<T>(v);
			if (first == NULL) // empty list
				first = last = newNode;
			else
			{
				last->next = newNode;
				last = newNode;
			}
		}
		
		void start()
		{
			pointer = 0;
		}
		
		T* next()
		{
			pointer = (pointer == 0) ? first : pointer->next;
			return (pointer == 0) ? 0 : pointer->get();
		}
		
		void clear()
		{
			Node<T>* p = first;
			while(p)
			{
				Node<T>* pNext = p->next;
				delete p;
				p = pNext;
			}
			
			first = last = pointer = 0;
		}
		
		~List()
		{
			clear();
		}
		
		
		
		
	
	
};

#endif
