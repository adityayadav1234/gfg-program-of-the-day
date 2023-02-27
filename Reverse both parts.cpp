//feb 27, 2023
//



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        int n = 0;
        Node * current = head;
        
        stack<Node *> s;
        
        while(current != nullptr){
            s.push(current);
            current = current -> next;
            ++n;
        }
            
        Node * secondHead = s.top();
        for(int i = 0; i < n - k; i++){
            current = s.top();
            s.pop();
            current -> next = s.top();
        }
        current -> next = nullptr;
        
        head = s.top();
        for(int i = 0; i < k; i++){
            current = s.top();
            s.pop();
            if(s.size())
                current -> next = s.top();
            else
                current -> next = secondHead;
        }
        
        return head;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
