#include<iostream>
#include <queue>
using namespace std;

  // Searching in Binary Tree
  // find Minimum Value
  // find maximum value

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

// Assuming in BST NO duplicate data 
bool SearchinInBST(Node* root , int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    
    if(target > root->data){
        return SearchinInBST(root->right , target);
    }
    else{
        return SearchinInBST(root->left , target);
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


// find Minimum Value in BST

int MinValue(Node* root){
    // first case Crete Node Pointer temp
    Node* temp = root;
  
  // second Step
  if(temp == NULL){
    return -1;
  }
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp-> data;
 
}

// find Maximum Value in BST
int MaxValue(Node* root){
    // first case Crete Node Pointer temp
    Node* temp = root;
  
  // second Step
  if(temp == NULL){
    return -1;
  }
  while(temp->right != NULL){
    temp = temp->right;
  }
  return temp-> data;
 
}


int main(){
    Node*  root = NULL;
    cout<<"Enter the Data"<< endl;
    takeInput(root);
     
     cout<<endl;
     levelOrderTraversal(root);
     cout<< endl;

   bool ans = SearchinInBST(root, 40);
   cout<<endl;
   cout<< "ans is :" << ans << endl;

int minVal =  MinValue(root);
cout<< "minimum Value : " << minVal <<endl ;

int maxVal =  MaxValue(root);
cout<< "maximum Value : " << maxVal <<endl ;


    return 0;
}