#ifndef __LIST_H__
#define __LIST_H__

#include <stdexcept>
#include <string>

class invalid_iterator_state : public std::logic_error
{
	private:
		void* invalid_iterator;
	public:
		invalid_iterator_state(const std::string& message, void* _invalid_iterator)
			: std::logic_error(message), invalid_iterator(_invalid_iterator)
		{}
		
		void* getInvalidIterator() const
		{ return invalid_iterator;}
		
	
};

template<class T>
class List {
private:
	
	template<class T1>
	class Node {
		private:
			T1* value;
			Node<T1>* next;
		public:
			Node(T1* _value)
				: value(_value), next(nullptr) {}
			T1* get() const {return value;}
			~Node() { delete value; }
		friend class List<T1>;
	};
	
	Node<T>* first;
	Node<T>* last;

public:
	List() : first(nullptr), last(nullptr) {}
	
	void add(T* v) {
		Node<T>* newNode = new Node<T>(v);
		if (first == nullptr) // empty list
			first = last = newNode;
		else {
			last->next = newNode;
			last = newNode;
		}
	}
	
	
	
	
	
	template<class T2>
	class Iterator {
		private:
			List<T2>* list;
			Node<T2>* pointer;
			Iterator(List<T2>* _list) : list(_list) {
				start();
			}
		public:
			void start() { pointer = nullptr; }
			bool hasNext(){
				if (pointer == nullptr) 
					pointer = list->first;
				else
					pointer = pointer->next;
				
				return pointer != nullptr;
			}
			T& value() {
				if (pointer != nullptr)
					return *(pointer->value);
				else
					//throw "invalid iterator state";
					throw invalid_iterator_state("invalid iterator state", this);
			}
			
			friend class List<T2>;
	};
	
	Iterator<T> iterator()
	{
		return Iterator<T>(this);
	}
	
	~List() {
			Node<T>* p = first;
			while(p)
			{
				Node<T>* pNext = p->next;
				delete p;
				p = pNext;
			}
			
			first = last = nullptr;
	}
	
	
};


#endif

