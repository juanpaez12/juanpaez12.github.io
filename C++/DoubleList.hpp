
#include "ListNode.hpp"

using namespace std;

template<typename T>
class DoubleList{

private:
	int size;
	ListNode<T>* inode;
public:
	ListNode<T>* head;
	ListNode<T>* tail;

	DoubleList(){
		clear();
	}

	DoubleList(T _object){
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
            if (node->next == NULL) {
                add(object);
            } else {
                this->size++;
                ListNode<T>* newNode = new ListNode<T>(object,node->next,node);
                newNode->next->previous = newNode;
                node->next = newNode;
            }
            return true;
        } catch (exception& e) {
            return false;
        }
    }

    
    bool insert(T ob, T object) {
        try {
            if (ob != NULL) {
                ListNode<T>* node = this->search(ob);
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
            } else {
                head = new ListNode<T>(object,head,NULL);
                head->next->previous = head;
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
            } else {
                tail->next = new ListNode<T>(object, NULL,tail);
                tail = tail->next;
                
            }
            this->size++;
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    bool remove(ListNode<T>* node) {
        return remove(node->getObject());
    }

    
    bool remove(T object) {
        try{
            if(object != NULL){
                boolean eliminado = false;
                ListNode<T>* node = head;
                while(eliminado == false && node != NULL){
                    if(node->getObject() == object){
                        this->size--;
                        eliminado = true;
                        if(node->previous == NULL){
                            head = head->next;
                            head->previous = NULL;
                            
                        }else{
                            node->previous->next = node->next;
                        }
                    }
                    node = node->next;
                }
                return eliminado;
            }
            
            return false;
        }catch(exception& e){
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
        try{
            return head->previous->getObject();
        }catch(exception& e){
            return NULL;
        }
    }

    ListNode<T>* getBeforeTo(ListNodeDouble node) { 
        try{return node->previous;}catch(exception& e){return NULL;}
    }

    T getNextTo() {
        return head->next->getObject();
    }

    T getNextTo(ListNodeDouble node) {
        try{return node->next;}catch(exception& e){return NULL;}
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