# -*- coding: utf-8 -*-

class ListNode:
    Object = None
    Next = None
    Previous = None
    
    def __init__(self):
        self.Object = None
        self.Next = None
        self.Previous = None
        
    @classmethod
    def NodeObject(cls,objecto):
        Nodo = cls.__new__(cls)
        Nodo.Object = objecto
        Nodo.Next = None
        Nodo.Previous = None
        return Nodo
        
    @classmethod
    def NodeObjectNext(cls,objecto, nxt):
        Nodo = cls.__new__(cls)
        Nodo.Object = objecto
        Nodo.Next = nxt
        return Nodo
    
    @classmethod
    def NodeObjNxtPre(cls,objecto, nxt, pre):
        Nodo = cls.__new__(cls)
        Nodo.Object = objecto
        Nodo.Next = nxt
        Nodo.Previous = pre
        return Nodo
    
    def getObject(self):
        return self.Object
    
    def setObject(self,objecto):
        self.Object = objecto
        
    def __str__(self):
        if self.Previous == None :
            return "ListNode{object=" + str(self.Object) + ", next=" + str(self.Next) + "}"
        else:
            try:
                return "ListNode{object=" + str(self.Object) + ", next=" + str(self.Next.getObject()) +", Previous =" +  str(self.Previous.getObject()) +  "}"
            except:
                return "ListNode{object=" + str(self.Object) + ", next=" + "None" +", Previous =" +  str(self.Previous.getObject()) +  "}"
    
    def isEquals(self, objecto):
        if(type(ListNode()) == type(objecto)):
            return str(self).__eq__(str(objecto))
        else:
            return self.Object.__eq__(objecto)
        return False
    
