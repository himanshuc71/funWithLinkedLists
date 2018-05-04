
#include "chain.h"

/* no-argument constructor w 2 sentinels */
Chain::Chain() : length_(0) {
   head_ = new Node();
   tail_ = new Node();
   head_->next = tail_;
   tail_->prev = head_;
}

/* Most useful constructor. requires your
 * implementation of Block and insertBack.
 * Builds a chain out of the blocks in the
 * given image. The blocks we create
 * have width equal to imIn.width()/cols,
 * and height equal to imIn.height()/rows.
 * Our Chain has one
 * sentinel node at the head, and another
 * at the tail.
 */
Chain::Chain(PNG & imIn, int rows, int cols){

   width_ = imIn.width()/cols;
   height_ = imIn.height()/rows;

   head_ = new Node(Block());
   tail_ = new Node(Block());
   head_->next = tail_;
   tail_->prev = head_;

   length_ = 0;

   for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
         Block b;
         b.build(imIn , j*width_, i*height_, width_, height_);
         insertBack(b);
      }
   }
}

/**
 * accessor for the length of the chain.
 */
int Chain::size() const {
   return length_;
}

/* copy constructor */
Chain::Chain(Chain const& other) {
   copy(other);
}

/* assignment operator */
Chain & Chain::operator=(Chain const& rhs) {
   if (this != &rhs) {
      clear(); // you'll implement clear
      copy(rhs);
   }
   return *this;
}
/**
 * checks for empty list
 */
bool Chain::empty() const {
   return length_ == 0;
}

/**
 * Takes the current chain and renders it into a
 * correctly sized PNG. The blocks in the chain
 * are placed in the image across each row,
 * top to bottom. If the chain is not long enough
 * to create a PNG with the right number of rows
 * and columns, the message "Chain is too short."
 * is printed and an empty PNG is returned.
 */
PNG Chain::render(int rows, int cols){

   PNG retVal;

   if (rows * cols <= length_){
      retVal.resize(cols*width_,rows*height_);
      Node * curr = head_->next;
      for (int i = 0; i < rows; i++){
         for (int j = 0; j < cols; j++){
            curr->data.render(retVal, j*width_, i*height_);
            curr = curr->next;
         }
      }
   }
   else {
      cout << "Chain is too short." << endl;
   }
   return retVal;
}

/* Returns a pointer to the node in the kth position of the list.
 * beyond curr. It effectively walks forward k steps from curr.
 * You may use this function in your solutions
 * to the PA1 functions. GIVEN in chain_given.cpp.
 */
typename Chain::Node * Chain::walk(Node * curr, int k){

   if (k==0 || curr == NULL)
      return curr;
   else
      return walk(curr->next,k-1);
}

// Node constructors
Chain::Node::Node() : next(NULL), prev(NULL), data(Block())
{ /* nothing */ }

Chain::Node::Node(const Block& ndata) : next(NULL), prev(NULL), data(ndata)
{ /* nothing */ }
