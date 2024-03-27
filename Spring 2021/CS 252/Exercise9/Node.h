//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef NODE_H
#define NODE_H

class Node{
private:
   int info;
   Node* next;

public:
   Node(int info, Node* next){
       this->info = info;
       this->next = next;
   }

   void setInfo(int info){
       this->info = info;
   }

   int getInfo(){
       return info;
   }

   void setNext(Node* next){
       this->next = next;
   }

   Node* getNext(){
       return next;
   }
};

#endif // NODE_H
