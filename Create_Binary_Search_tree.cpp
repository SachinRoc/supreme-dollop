#include <iostream>
using namespace std;
#include <queue>

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

Node* insertIntoBST(Node* root , int data){
    if(root == NULL){
        // this is first Node we have to create
        root = new Node(data);
        return root;
    }

    // first node nhi hai
    if(root->data > data){
        root->left = insertIntoBST(root->left , data);
    }
    else{
        root->right = insertIntoBST(root->right , data);
    }
    return root;
}
    



void takeInput(Node* &root){
    int data;
    cin>> data;

    while(data != -1){
        root = insertIntoBST(root , data);
        cout<<" root: " <<root->data << endl;
        cin >> data;
    }
}

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
  // preorder Traversal
void preOrderTraversal(Node* root){
    // NLR
    if(root == NULL){
        return;
    }
    cout<< root->data << " ";
   preOrderTraversal(root->left);
   preOrderTraversal(root -> right);

}

// Inorder traversal

void inOrderTraversal(Node* root){
    //LNR
    if(root == NULL){
        return ;
    }

    inOrderTraversal(root->left);
    cout<< root->data <<" ";
    inOrderTraversal(root->right);
}

//  post order traversal
 void posrOrdertraversal(Node* root){

    // LRN
  if(root == NULL){
    return ;
  }

  posrOrdertraversal(root->left);
  posrOrdertraversal(root->right);
  cout<< root->data << " ";

 }


int main(){

Node* root = NULL;

cout<<"Enter the data Node"<< endl;

takeInput(root); 

cout<<"printing the level order Traversal" << endl;

levelOrderTraversal(root);
cout<< endl;

// pre Order Traversal
cout<< "printing PreOrder :"<< endl;
  preOrderTraversal(root);
// In Order Traversal
cout<< "printing inOrder :"<< endl;
cout<< endl;
  inOrderTraversal(root);
// post order traversal
cout<<endl;
cout<< "printing postOrder :"<< endl;
  posrOrdertraversal(root);


    return 0;
}