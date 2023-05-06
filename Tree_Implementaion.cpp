#include<iostream>
#include<queue>
using namespace std;

// tree creation using Recursion.

class Node {
    public:
    int data;
    Node* left;
    Node* right;
   
   Node(int data){
    this->data = data;
    left = NULL;
    right = NULL;

   }
};

Node * bulidTree(){
    int data ; 
    cout<< " Enter the data:" << endl;
    cin>> data;

    if(data == -1){
        return NULL;
    }

    // step A B and C
    Node * root = new Node(data);

    cout<< " Enter data for left part of "<< data << " node" << endl;
    root->left = bulidTree();

    cout<< " Enter data for right part of "<< data << " node" << endl;
    root->right = bulidTree();
    
    return root;
     
}

// code of level order travarsal
void levelOrderTravarsal(Node* root){
   queue<Node*> q;

   // initially
   q.push(root);

   while(!q.empty()){
      //step A : store the front element in temp
      Node * temp = q.front();

      //step B : pop the element in queue
      q.pop();
      
      //step:3 print the data
      cout<< temp->data ;

      //step :4 Insert the chide element
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }

   }

}


int main(){

    Node* root = NULL;
    root = bulidTree();
   
   // print level order travarsal
    levelOrderTravarsal(root);


    return 0;
}

