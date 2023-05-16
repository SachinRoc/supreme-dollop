#include<iostream>
#include <queue>
using namespace std;

// Delete Node IN BST
 //10 20 5 11 17 2 4 8 6 25 15


class Node{
      public:
      int data;
      Node* left;
      Node* right;

      Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
  };

   Node* inserInputBST(Node* root , int data){
        // first Node in Insert
         if(root == NULL){
            root = new Node(data);
            return root;
         }

         // second Node Insert
         if(root->data > data){
            root->left = inserInputBST(root->left , data);
         }
         else{
            root->right = inserInputBST(root->right , data);
         }
  }

void takeInput(Node* &root){
    int data;
    cin>> data;
    while(data != -1){
        root = inserInputBST(root , data);
        cin>> data;
    }
}  

 // level Order Print
void levelOrderTraversal(Node* root){
      queue<Node*> q;
      q.push(root);

      q.push(NULL);

      while(!q.empty()){
          Node* temp = q.front();
          q.pop();

          if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
          }

          else{
              cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

          }

      }


}

// find max value
int findMax(Node* root){
    Node* temp = root;
    if(temp == NULL){
        return -1;
    }
    
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;

}

// Delete Node in BST

Node* DeleteNodeInBST(Node* root , int target){

   // base case
   if(root == NULL){
    return NULL;
   }

   if(root->data == target){
    // isi ko delete krna hai
    // 4 case exist honga
      if(root->left == NULL && root->right == NULL){
        // leaf Node
        // delete Node
        return NULL;
      }
      else if(root->left == NULL && root->right !=NULL){
          Node* child = root->right;
          // delete Node
          return child;
      }
      else if(root->left != NULL && root->right == NULL){
        Node* child = root->left;
        // delete child
        return child;
      }
      else{
        // both case
        // find Inorder Predecessor in left sub tree
        int inorderPre = findMax(root->left);
         // replace root->data value with predeccessor
         root->data = inorderPre;
         // delete inorder predecessor from left sub tree
         root->left = DeleteNodeInBST(root->left , inorderPre);
         
         return root;
         
      }


   }

  if(root->data > target ){
    root->left = DeleteNodeInBST(root->left , target);
  }
  else{
    root->right = DeleteNodeInBST(root->right , target);
  }
   return root;

}



int main(){
    Node*  root = NULL;
    cout<<"Enter the Data"<< endl;
    takeInput(root);
     
     cout<<endl;
     levelOrderTraversal(root);
     cout<< endl;

    Node* mainRoot= DeleteNodeInBST(root ,10 );
    cout<<endl;
    levelOrderTraversal(mainRoot);


    return 0;
}