// Implementation of Depth First Search Algorithm ( DFS ) Using Stack Data Structure
#include <iostream>
#include <stack>
using namespace std;
class Node    // Node class for defining attributes of Nodes of the Tree
{
    public:       // Data members
    int data;
    Node* left;
    Node* right;
    Node* root;
    bool visited;
    Node(int val)     // Parametrized Constructor
    {
        data = val; left = NULL;
        visited = false;
        right = NULL; root = NULL;
    }
};
class BinaryTree    // Binary Tree class to Implement binary trees
{
    public:
    Node* InsertNodeInTree(Node* root, int val)  // Binary Tree Creation with the Node value
    {
        if(root == NULL)          // If Current node is empty or does not exist
            return new Node(val);      // Create One with the given data
        if(val <= root -> data)    // If data is less than the Parent Node, store in the Left Subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else                       // If data is more than the Parent Node, store in the Right Subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    public:
    void ShowTree(Node* root)   // Displaying Tree by InOrder Traversal
    {
        if(root == NULL)
           return;              // return if current Node is empty
        Node* temp = root;
        ShowTree(root -> left);     // Recursive Call for Left Subtree
        cout << "Node : " << endl;
        if(temp -> left != NULL)     // Printing if Left Subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> left -> data << "\t Left ( Occupied )" << endl;
        else                         // Printing if Left Subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(temp -> right != NULL)    // Printing if Right Subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> right -> data << "\t Right ( Occupied )" << endl;
        else                         // Printing if Right Subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(root -> right);   // Recursive Call for Right Subtree
    }
    public:
    void DepthFirstSearch(Node* root, int val)   // Depth First Search Algorithm by Stacks Iteratively
    {         // Time Complexity is.. O(n) time since n nodes will be traversed in worst case
        stack<Node*> Stack;   // Stack data Structure creation of Node pointer data type
        if(root == NULL)
        {
            Stack.pop();    // If Root node is empty, then no need of DFS 
            return;
        }
        Stack.push(root);       // Pushing Root Element to the Stack
        while(!Stack.empty())       // While Stack is not empty
        {
            Node* top = Stack.top();        // Storing the top pointer reference
            cout << top -> data << " --> ";   
            if(top -> data == val)           // If the required Value is found
            {
                cout << "Found " << endl;
                cout << "Search Successfull !!" << endl;    // Display Search Successful
                return;      // The Control moves out of the function
            }
            Stack.pop();         // Popping the top element after entering the while loop
            if(top -> right)               // While popping check if current Node has left child
                Stack.push(top -> right);   
            if(top -> left)                // While popping check if current Node has right child
                Stack.push(top -> left);
        }
        cout << "Not Found" << endl;              // If entire tree is traversed without finding the Node
        cout << "Search Unsuccessfull !!" << endl;
    }
    public:
    void DepthFirstSearch(Node* root, int val, bool visited)   // Depth First Search by Recursion 
    {      // Time Complexity is.. O(n) since n nodes will be recursively called in worst case
        if(root == NULL)   // If current Node is empty, return to the previous caller function ( backtrack )
            return;
        stack<Node*> Stack;    // Stack Data Structure creation of Node pointer data type 
        Stack.push(root);          // Pushing the root element
        Node* top = Stack.top();        // Storing the top pointer reference
        if(top -> data == val)      // If the required value is found
        {
            cout << top -> data << " --> Found ";
            top -> visited = true;               // Node visited
            if(top -> left -> visited == false)
                top -> left -> visited = true;    // Making the left Node visited, if exists
            if(top -> right -> visited == false)
                top -> right -> visited = true;   // Making the right Node visited, if exists
            cout << endl;
            cout << "Search Successfull !!" << endl;
        }
        if(top -> visited == false)    // If the Node is not visited yet
        {
            top -> visited = true;            // Make the Node visited True and print the data
            cout << top -> data << " --> ";
        }
        Stack.pop();          // Popping the Top element of the Stack after visiting the Node
        if(top -> left)
        {                // If Left Subtree exists and it is not visited yet
            if(top -> left -> visited == false)
            DepthFirstSearch(top -> left, val, visited);   // Recursive Call to the Left Subtree
        }
        if(top -> right)
        {                  // If Right Subtree exists and it is not visited yet
            if(top -> right -> visited == false)
            DepthFirstSearch(top -> right, val, visited);   // Recursive Call to the Right Subtree 
        }
        return;
    }
};
int main()
{
    Node* root = NULL;              // Root Node pointer set to Null
    BinaryTree binarytree;     // Binary Tree object creation
    int s, x;
    cout << "Enter the Value of Root Node of the Binary Tree : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);   // Root Node creation
    cout << "Enter the Number of nodes to be Inserted in the Binary Tree : ";
    cin >> s;
    for(int t = 0; t < s; t++)     //  Loop for entering the Node values
    {
        cout << "Enter the Node value : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);
    }
    binarytree.ShowTree(root);        // Displaying the Binary Tree
    cout << "Enter any Node to be Searched by Value : ";
    cin >> x;
    cout << "The Depth First Search by Iteration is : " << endl;
    binarytree.DepthFirstSearch(root, x);                                // Function call
    cout << "The Depth First Search by Recursion is : " << endl;
    binarytree.DepthFirstSearch(root, x, false);                         // Function Call
    return 0;   // End of the Program
}