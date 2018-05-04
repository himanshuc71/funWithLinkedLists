#include "chain.h"
#include "chain_given.cpp"
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
  clear();
}

/**
 * Inserts a new node in position one of the Chain,
 * after the sentinel node.
 * This function **SHOULD** create a new Node.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertFront(const Block & ndata){
Node* temp = new Node (ndata);
temp->prev = head_;
temp->next = head_->next;

temp->next->prev=temp;
head_->next=temp;

length_++;
temp = NULL;
}

/**
 * Inserts a new node at the back of the Chain,
 * but before the tail sentinel node.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
   Node* temp= new Node(ndata);
   temp->prev = tail_->prev;
   temp->next = tail_;

   tail_->prev = temp;
   temp->prev->next = temp;

   length_++;
   temp = NULL;
}

/**
 * Modifies the Chain by moving a contiguous subset of Nodes to
 * the end of the chain. The subset of len nodes from (and
 * including) startPos are moved so that they
 * occupy the last len positions of the
 * chain (maintaining the sentinel at the end). Their order is
 * not changed in the move.
 */
void Chain::moveToBack(int startPos, int len){

   Node* start= walk(head_,startPos);
   Node* end = walk(start, len-1);

   start->prev->next = end->next;
   end->next->prev = start->prev;

   start->prev = tail_->prev;
   end->next = tail_;
   start->prev->next = start;
   tail_->prev = end;

   start=NULL;
   end=NULL;
}

/**
 * Rotates the current Chain by k nodes: removes the first
 * k nodes from the Chain and attaches them, in order, at
 * the end of the chain (maintaining the sentinel at the end).
 */
void Chain::rotate(int k){
   moveToBack(1,k);
}

/**
 * Modifies the current chain by swapping the Node at pos1
 * with the Node at pos2. the positions are 1-based.
 */
void Chain::swap(int pos1, int pos2){
   Node* one = walk(head_,pos1);
   Node* two = walk(head_,pos2);

   Node* temp = one->next;

   one->next = two->next;
   two->next->prev = one;

   two->next = temp;
   temp->prev = two;

   temp = one->prev;

   one->prev= two->prev;
   one->prev->next= one;

   two->prev = temp;
   temp->next= two;

   one = NULL;
   two = NULL;
   temp = NULL;
}

/*
 *  Modifies both the current and input chains by trading
 * nodes in even positions between the chains. Length
 * of each chain should stay the same. If the block dimensions
 * are NOT the same, the funtion has no effect and a simple
 * error message is output: cout << "Block sizes differ." << endl;
 */

void Chain::twist(Chain & other){
   if (height_ != other.height_ || width_ != other.width_) {
     std::cout<<"Block sizes differ."<<std::endl;
     return;
   }

   if (other.empty() || empty()) {
     return;
   }

   bool even = true;
   Node* c1= walk(head_,2);
   Node* c2= walk(other.head_,2);

   while (c1!=NULL && c2!=NULL) {

     if(even){
       Node* temp = c1->prev;
       c1->prev = c2->prev;
       temp->next = c2;

       Node* temp2 = c1->next;

       c1->next = c2->next;
       temp2->prev = c2;

       c2->next = temp2;
       c1->next->prev = c1;

       c2->prev=temp;
       c1->prev->next=c1;
     }
     c1 = c1->next;
     c2 = c2->next;
     even = !even;
   }

   c1 = NULL;
   c2 = NULL;
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() {
   Node* curr = head_;
   for (int i = 0; i <= size(); i++) {
     curr=curr->next;
     delete curr->prev;
   }
   length_ = 0;
   height_ = 0;
   width_ = 0;
   delete curr;
   curr = NULL;
   head_= NULL;
   tail_= NULL;

}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {

   length_ = other.size();
   height_ = other.height_;
   width_ = other.width_;

   head_ = new Node();
   head_->prev = NULL;
   tail_ = new Node();
   tail_->next = NULL;

   Node* previous = head_;
   Node* curr = other.head_->next;

   for (int i = 1; i <= length_; i++) {
     Node* x = new Node(curr->data);
     x->prev = previous;
     previous->next = x;
     previous = previous->next;
     curr = curr->next;
   }

   previous->next=tail_;
   tail_->prev= previous;

   curr = NULL;
   previous = NULL;

}
