#include "ListNode.hpp"

using namespace std;

template<typename T>
class CircularList{

private:
	int size;
	ListNode<T>* inode;
public:
	ListNode<T>* head;
	ListNode<T>* tail;

	CircularList(){
		clear();
	}

	CircularList(T _object){
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

	bool insert(ListNode<T>* node, T object) {
        try {
            if (node->next == head) {
                add(object);
            } else {
                this->size++;
                ListNode newNode = new ListNode<T>(object);
                newNode->next = node->next;
                node->next = newNode;
            }
            return true;
        } catch (exception& e) {
            return false;
        }
    }

    
    bool insert(T ob, T object) {
        try {
            if (ob != null) {
                ListNode node = this->search(ob);
                if (node != null) {
                    return insert(node, object);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } catch (exception& e) {
            return false;
        }
    }

    
    bool insertHead(T object) {
        try {
            if (isEmpty()) {
                head = new ListNode<T>(object);
                tail = head;
                tail->next = head;
            } else {
                head = new ListNode<T>(object, head);
                tail->next = head;
            }
            this->size++;
            return true;
        } catch (exception& e) {
            return false;
        }
    }

    
    bool insertTail(T object) {
        try {
            if (isEmpty()) {
                head = new ListNode<T>(object);
                tail = head;
                tail->next = head;
            } else {
                tail->next = new ListNode<T>(object);
                tail = tail->next;
                tail->next = head;
            }
            this->size++;
            return true;
        } catch (exception& e) {
            return false;
        }
    }

    bool remove(ListNode<T>* node) {
        return remove(node->getObject());
    }
    
    

    bool remove(T object) {
        try{
            ListNode<T>* a = head;
            ListNode<T>* anterior = tail;
            int t = 0;
            boolean eliminado = false;
            while(t < size && eliminado == false){
                t++;
                if( a.getObject() == object){
                    eliminado = true;
		    this->size--;
                    if(anterior == tail){
                        head = a->next;
                        tail->next = head;
                    }else{
                        anterior->next = a->next;
                    }
                }
                anterior = a;
                a = a->next;
            }
            return eliminado;
        } catch(exception& e){
            return false;
        }
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

	T getBeforeTo() {
        try{return tail->getObject();}catch(exception& e){return NULL;}
    }

    
    ListNode<T>* getBeforeTo(ListNode<T>* node) {
        try{
            ListNode<T>* a = head;
            ListNode<T>* p = NULL;
            while(a != node){
                p = a;
                a = a->next;
            }
            return p;
        }catch(exception& e){
            return NULL;
        }
    }
    
    T getNextTo() {
        try{return head->next->getObject();}catch(exception& e){return NULL;}
    }

    T getNextTo(ListNode<T>* node) {
        try{return node->next->getObject();}catch(exception& e){return NULL;}
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