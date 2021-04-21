#include<cstddef>
#include<string>
using namespace std;

template<typename T>
class ListNode{
	T object;
public:
	ListNode* next;
	ListNode* previous;

	ListNode(){
	}
	ListNode(T _object){
		object = _object; 
		next = NULL;
		previous = NULL;
	}
	ListNode(T _object,ListNode* _next){
		object = _object; 
		next = _next;
	}

	ListNode(T _object,ListNode* _next, ListNode* _previous){
		object = _object; 
		next = _next;
		previous = _previous;
	}


	T getObject(){
		return object;
	}
	void setObject(T _object){
		object = _object;
	}

	bool isEquals(T _object){
		if(to_string(getObject()) == to_string(_object)){
			return true;
		}
		return false;
	}

	bool isEquals(ListNode* node){
		if(toString() == node->toString()){
			return true;
		}
		return false;
	}

	string toString(){
		ListNode* a = next;
		string n = "ListNode{object=" + to_string(getObject()) + ", next=";
		string b = "null}";
		while(a != NULL){
			n += "ListNode{object=" + to_string(a->getObject()) + ", next=";
			b += "}";
			a = a->next;
		}
		n += b;
		return n;
	}

	friend ostream& operator<<(ostream& os, ListNode* node){
		os << node->toString();
    	return os;
	}
	
};




