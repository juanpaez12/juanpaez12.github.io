#include "ListNode.hpp"

using namespace std;

template<typename T>
class ListStack{
    private:
        ListNode<T>* top;
        int size;
    public:
        ListStack(){
        }
        void clear(){
            size = 0;
            top = NULL;
        }
        bool isEmpty(){
            return top == NULL;
        }
        T peek(){
            if(!isEmpty()){
                return top->getObject();
            }else{
                return NULL;
            }
            
        }

        T pop(){
            T a = top->getObject();
            top = top->next;
            size--;
            return a;
        }

        bool push(T _object){
            try {
                ListNode<T> *nuevo = new ListNode<T>;
                nuevo->next = top;
                top = nuevo;
                size++;
                return true;
            }
            catch(exception& e) {
                return false;
            }

        }

        int Size(){
            return size;
        }

        bool search(T object) {
            ListNode<T>* a = top;
            while(a != null){
                if(a->getObject()  == object){
                    return true;
                }
                a = a->next;
            }
                return false; 
            }

        void reverse() {
            ListStack* a = new ListStack();
            ListNode<T>* b = top;
            while (b != null){
                a->push(b->getObject());
                b = b->next;
            }
            top = a->top;
            a = NULL;
        }

        void sort(){

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

        


};