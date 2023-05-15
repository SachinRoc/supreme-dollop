#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
       this-> left = NULL;
       this-> right = NULL;
    }

};

// find element in preorder
int findPosition(int arr[] , int n , int element){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}
// build tree from inorder and preorder traversal
Node* buildTreeFromPreOrderINOrder(int inorder[] , int preorder[] , int size , int &preIndex, 
int inorderStart , int inorderEnd){ 

    // base case
    if(preIndex > size  || inorderStart > inorderEnd){
        return NULL;
    }
     
     //Step A
     int element = preorder[preIndex++];
     Node* root = new Node(element);
     int pos = findPosition(inorder , size , element);

     // step B : root ->left solve
     root->left = buildTreeFromPreOrderINOrder(inorder , preorder , size, preIndex , inorderStart , pos-1);
    
    // step C: root->right solve
    root->right = buildTreeFromPreOrderINOrder(inorder , preorder , size , preIndex , pos+1,inorderEnd);
   
   return root;
}

void levelOrderTraversalPrinting(Node* root){
  queue<Node*> q;
  q.push(root);
  
  // initially NULL Push
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
        cout<< temp->data <<endl;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

     }

  }

}

int main(){

    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};

    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;

    cout<<"building Tree :" << endl;

    Node* root = buildTreeFromPreOrderINOrder(inorder , preorder, size , preIndex, inorderStart , inorderEnd);

    cout<<endl <<"Printing level order traversal"<<endl;

    levelOrderTraversalPrinting(root);


    return 0;
}
