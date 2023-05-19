#include<iostream>
#include<map>
#include<queue>
using namespace std;


class Node{
   public:
   int data;
   Node* left;
   Node* right;


   Node(int data){
    this->data = data;
    this->left = left;
    this->right = right;

   }

};

Node* buildTree(){
    int data ;
    cout<<"Enter the data :"<< endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout<<"Enter the data of left part" << data <<"node" << endl;
    root->left = buildTree();

    cout<<"Enter the data of right part " << data << "node" << endl;
    root->right = buildTree();

    return root;

}

// print the top view
void TopView(Node* root){
    if(root == NULL){
        return ;
    }
  // create map . Hme horizontal distance ke corrosponding mai node ka data store krna hai.
  map<int,int> topNode;

  // level order traversal
  // we will store the pair consisiting of node and horizontal distance
  queue<pair<Node*,int>>q;

  q.push(make_pair(root , 0));

  while(!q.empty()){
     pair<Node* , int> temp = q.front();
     q.pop();

     Node* frontNode = temp.first;
     int hd = temp.second;

     // jo bhi horizontal distance aaya h, check if answer for that hd already exists or not

     if(topNode.find(hd) == topNode.end()){
           topNode[hd] = frontNode->data;
     }
     if(frontNode->left){
        q.push(make_pair(frontNode->left , hd-1));

     }
     if(frontNode->right){
        q.push(make_pair(frontNode->right , hd+1));
     }


  }

  // Ab hmara answer map mai store ho gya hoga
  cout<< "printing the answer :"<< endl;

  for(auto i : topNode){
    cout<< i.first << " -> "<< i.second << endl;
  }


}


// print the Bottom view
// only map ki condtion remove krni hai. that mean hr bar update krna hai
void BottomView(Node* root){
    if(root == NULL){
        return ;
    }
  // create map . Hme horizontal distance ke corrosponding mai node ka data store krna hai.
  map<int,int> topNode;

  // level order traversal
  // we will store the pair consisiting of node and horizontal distance
  queue<pair<Node*,int>>q;

  q.push(make_pair(root , 0));

  while(!q.empty()){
     pair<Node* , int> temp = q.front();
     q.pop();

     Node* frontNode = temp.first;
     int hd = temp.second;

   
     topNode[hd] = frontNode->data;

     if(frontNode->left){
        q.push(make_pair(frontNode->left , hd-1));

     }
     if(frontNode->right){
        q.push(make_pair(frontNode->right , hd+1));
     }


  }

  // Ab hmara answer map mai store ho gya hoga
  cout<< "printing the answer :"<< endl;

  for(auto i : topNode){
    cout<< i.first << " -> "<< i.second << endl;
  }


}


int main(){

   Node* root = NULL;

   root = buildTree();
// print top view
  // TopView(root);

  // print Bottom View
  BottomView(root);


    return 0;
}