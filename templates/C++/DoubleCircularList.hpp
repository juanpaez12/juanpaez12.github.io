#include "ListNode.hpp"

using namespace std;

template<typename T>
class DoubleCircularList{
private:
	int size;
	ListNode<T>* inode;
public:
	ListNode<T>* head;
	ListNode<T>* tail;

	DoubleCircularList(){
		clear();
	}

	DoubleCircularList(T _object){
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
                ListNode<T>* newNode = new ListNode<T>(object,node->next,node);
                newNode->next->previous = newNode;
                node->next = newNode;
            }
            return true;
        } catch (exception& e) {
            return false;
        }
    }


    bool insert(Object ob, T object) {
        try {
            if (ob != null) {
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
                head = new ListNode<T>*(object);
                tail = head;
                tail->next = head;
                head->previous = tail;
               
            } else {
                head =new ListNode<T>*(object,head,tail);
                head->next->previous = head;
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
                head->previous = tail;
            } else {
                tail->next = new ListNode<T>(object, head,tail);
                tail = tail.next;
                head->previous = tail;
            }
            this->size++;
            return true;
        } catch (exception& e) {
            return false;
        }
    }

    bool remove(ListNode<T>* node) {
        return remove(node.getObject());
    }

    bool remove(T object) {
        try{
            if(object != null){
                bool eliminado = false;
                ListNode<T>* node = head;
                int s = 0;
                while(eliminado == false && s < size){
                    if(node->getObject() == object){
                        this->size--;
                        eliminado = true;
                        if(node.previous == tail){
                            head = head->next;
                            head->previous = tail;
                            tail->next = head;
                            
                        }else if(node == tail){
                            node->previous->next = node->next;
                            head->previous = node->previous;
                        }else{
                            node->previous.next = node->next;
                        }
                    }
                    s++;
                    node = node->next;
                }
                return true;
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


    ListNode<T>* getBeforeTo(ListNode<T>* node) { 
        try{return node->previous;}catch(exception& e){return NULL;}
    }

    T getNextTo() {
        return head->next->getObject();
    }

    T getNextTo(ListNode<T>* node) {
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