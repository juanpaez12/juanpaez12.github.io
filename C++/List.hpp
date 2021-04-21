#include<cstddef>
#include "ListNode.hpp"

using namespace std;

template<typename T>
class List{
private:
	int size;
	ListNode<T>* inode;
public:
	ListNode<T>* head;
	ListNode<T>* tail;
	List(){
		clear();
	}

	List(T _object){
		add(_object);
	}

	bool isEmpty(){
		return head == NULL;
	}

	int getSize(){
		return size;
	}

	void clear(){
		head = NULL;
		tail = NULL;
		size = 0;
	}

	ListNode<T>* getHead(){
		return head;
	}

	ListNode<T>* getTail(){
		return tail;
	}

	ListNode<T>* search(T _object){
		inode = head;
		while(inode != NULL){
			if(inode->isEquals(_object)){
				return inode;
			}
			inode = inode->next;
		}
		return NULL;
	}

	bool add(T _object){
		return insertTail(_object);
	}
	
	bool insert(ListNode<T>* node ,T _object){
		if(node->next == NULL){
			add(_object);
		} else {
			ListNode<T>* newNode;
			newNode = new ListNode<T>(_object);
			newNode->next = node->next;
			node->next = newNode;
		}
		size++;
		return true;
	}

	bool insert(T ob, T _object){
		if(ob != NULL){
			ListNode<T>* node = this->search(ob);
			if(node != NULL){
				return insert(node, _object);
			}else{
				return false;
			}
		}else{
			return false;
		}
	}

	bool inserHead(T _object){
		if(isEmpty()){
			head = new ListNode<T>(_object);
			tail = head;
			
		}else{
			head = new ListNode<T>(_object);
		}
		size++;
		return true;
	}

	bool insertTail(T _object){
		if(!isEmpty()){
			tail->next = new ListNode<T>(_object);
			tail = tail->next;
		}else{
			head = new ListNode<T>(_object);
			tail = head;
		}
		size++;
		return true;
	}

	bool remove(ListNode<T>* node){
		return remove(node->getObject());
	}

	bool remove(T _object){
		ListNode<T>* a = head;
		ListNode<T>* t = NULL;
		bool eliminado = false;
		while(a != NULL && eliminado == false){
			if(a->getObject() == _object){
				size--;
				eliminado = true;
				if(t == NULL){
					head = a->next;
					a->next = NULL;
				}else{
					t->next = a->next;
					a->next = NULL;
				}
			}
			t = a;
			a = a->next;
		}
		return eliminado;
	}

	bool contains(T _object){
		return this->search(_object) != NULL;
	}



	int* toArray(T arr[]){
		ListNode<T>* t = head;
		for (int i = 0; i < size; ++i)
		{
			arr[i] = t->getObject();
			t = t->next;
		}
		return arr;
	} 

	T getBeforeTo(){
		return NULL;
	}

	ListNode<T>* getBeforeTo(ListNode<T>* node){
		try{
			ListNode<T>* a = head;
			while(a->next != node){
				a = a->next;
			}
			return a;
		}catch(exception& e){
			return NULL;
		}
	}

	T  getNextTo(){
		return head->next->getObject();
	}

	T getNextTo(ListNode<T>* node){
		return node->next->getObject();
	}

	List* subList(ListNode<T>* from,ListNode<T>* to){
        List* listSub = new List();
        try{
            bool stop = true;
            while(stop){
                listSub->add(from->getObject());
                from = from->next;
                if(from->getObject() == to->getObject())
                    stop = false;
            }
            return listSub;
        } catch(exception& e){
            return NULL;
        }  
    }



	List* sortList(){
		T ar[size];
		T *arr = toArray(ar);

		List* l = new List();
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size-1; ++j)
			{
				T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
			}
		}

		for (int i = 0; i < getSize(); ++i)
		{
			l->add(arr[i]);

		}
		return l;	

	}

};






