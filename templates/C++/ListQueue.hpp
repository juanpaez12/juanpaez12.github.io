
#include "ListNode.hpp"

using namespace std;


template<typename T>
class ListQueue{

private:
    int size;
    ListNode<T>* top;
    ListNode<T>* bot;

public:
    
    ListQueue() {
        clear();
    }
    
    
    void clear() {
        size = 0;
        top = NULL;
        bot = NULL;
    }

    
    bool isEmpty() {
        return top == NULL;
    }

    
    T extract() {
        try{
            if(!isEmpty()){
                T a = top->getObject();
                top = top->next;
                size--;
                return a;
            }else{
                return NULL;
            }    
        }catch(exception& e){
            return NULL;
        }

    }

    
    bool insert(T object) {
        try{
            ListNode<T>* nodoInsertado = new ListNode(object);
            if(!isEmpty()){
                bot->next = nodoInsertado;
            }else{
                top = nodoInsertado;
            }
            bot = nodoInsertado;
            size++;
            return true;
        }catch(exception& e){
            return false;
        }
    }

    
    int size() {
        return size;
    }

    
    bool search(Object object) {
        
        try{
            if(!isEmpty()){
                ListNode<T> a = top;
                while(a != null){
                    if(a->getObject()->equals(object)){
                        return true;
                    }
                    a = a->next;
                }
                return false;
            }else{
                return false;
            }
        }catch(exception& e){
            return false;
        }
    }

    
    void sort() {
            T *arr[size];
            ListNode<T>* t = head;
            for (int i = 0; i < size; ++i)
            {
                arr[i] = t->getObject();
                t = t->next;
            }

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
            top = l;
        }

    void reverse() {
        if(!isEmpty()){
            T *array[size];
            ListNode<T>* t = head;
            for (int i = 0; i < size; ++i)
            {
                array[i] = t->getObject();
                t = t->next;
            }
            top = NULL;
            for (int i = size-1; i > -1; i--) {
                insert(array[i]);
            }  
        }
    }