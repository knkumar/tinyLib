#include <iostream>
#include <vector>

using namespace std;


class Node{
protected:
    int value;
    Node *right;
    Node *left;
    Node *parent;
    int height;
  
public:

    Node(int value, Node* node){
	this->value = value;
	this->parent = node;
	this->left = NULL;
	this->right = NULL;
	if(node != NULL)
	    height = node->height + 1;
	else 
	    height = 0
    }

    friend class Tree;
};

class Tree{

    Node *root;
    int depth;
   
    void insert_node(Node *node,int value, Node *prev){
	if(node == NULL){
	    if(value < prev->value)
		prev->left = new Node(value, prev);
	    if(value >= prev->value)
		prev->right = new Node(value, prev);
	    node = new Node(value);
	    return;
	}
	if(value < node->value)
	    insert_node(node->left, value, node);
	if(value >= node->value)
	    insert_node(node->right,value, node);
    }

    int find_node(Node* node,int value){
	if(node == NULL){
	    return -1;
	}
	if(node->value == value){
	    return(node->value);
	}
	else if(value < node->value){
	    return(find_node(node->left,value));
	}
	else if(value > node->value){
	    return(find_node(node->right,value));
	}
    }


    void disp_tree(Node *start){
	cout<<start->value;
	//add the new nodes to a queue
	disp_tree(start->left);
	disp_tree(start->right);
    }

public:

    Tree(){
	root = NULL;
    }

    static Tree create_tree(){
	Tree tree;
	return tree;
    }
  
    int insert(int value){
	if(this->root == NULL){
	    this->root = new Node(value, NULL);
	    return 0;
	}
	if(value < root->value)
	    insert_node(root->left, value, root);
	if(value >= root->value)
	    insert_node(root->right,value, root);
	return 0;
    }
    
    int find(int value){
	if(root->value == value){
	    return root->value;
	}
	else if(value < root->value){
	    return(find_node(root->left,value));
	}
	else if(value > root->value){
	    return(find_node(root->right,value));
	}
    }


    void fix_parent(Node* node, Node* temp){
	Node* parent = node->parent;
	if(parent->left == node)
	    parent->left = temp;
	else
	    parent->right = temp;
	//cleanup
	temp->parent = parent;
	node->parent = temp;
    }
    /*
     Called only if the balance factor is greater than 1 
     */
    Node* rotate_right(Node* node){
	Node *temp = node->left;
	node->left = temp->right;
	temp->right = node;
	fix_parent(node, temp);
    }

    /*
     Called only if the balance factor is greater than 1 
     */
    Node* rotate_left(Node* node){
	Node *temp = node->right;
	node->right = temp->left;
	temp->left = node;
	fix_parent(node, temp);
    }
    
    int remove(int value){	
	
    }
  
};



int main(){
    Tree tree = Tree::create_tree();
    int nums[] = {10,11,13,12,8,7,9};
    vector<int> test = vector<int>(nums, nums+ sizeof(nums)/sizeof(int));
    for(vector<int>::iterator it = test.begin(); it != test.end(); it++){
	cout<<"inserting...."<<*it<<"\n";
	tree.insert(*it);
    }
    cout<<tree.find(9)<<"\n";
    cout<<tree.find(19)<<"\n";
	
    return 0;
}
