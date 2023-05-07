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
        left = NULL;
        right = NULL; 
    }

};

Node* BuildTree(){
    int data;
   cout<<"Enter your data"<< endl;
   cin>> data;

   if(data == -1){
    return NULL;
   }

   Node* root = new Node(data);

   cout<< "Enter of data Left side " << data << "node" << endl;

   root->left = BuildTree();

  cout<< "Enter of data right side " << data << "node" << endl;
   
   root->right = BuildTree();

   return root;

}

void levelOrderTraversalPrinting(Node* root){
    queue<Node*> q;
    q.push(root);

    // intially push NUll;
    q.push(NULL);
  
  while(!q.empty()){
     
    Node* temp = q.front();
    q.pop();
      // level wise printing
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

// InOrderTraversal
void inOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return ;
    }
    //LNR
    inOrderTraversal(root->left);
    cout<<root->data<< " ";
    inOrderTraversal(root->right);
}


// preOrderTraversal
void PreOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }
    //NLR
    cout<<root->data<< " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

// Post Order Traversal
void PostOrderTraversal(Node* root){
     if(root == NULL){
        return ;
    }
    //LRN
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}


int main(){

Node* root = NULL;
root = BuildTree();

//levelOrderTraversalPrinting(root);

inOrderTraversal(root);
cout<<endl;
PreOrderTraversal(root);
cout<<endl;
PostOrderTraversal(root);

    return 0;
}