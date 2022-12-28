// #include<iostream>
// using namespace std;

// //Creating a node class 
// class Node{
//     public:
//     int row;
//     int col;
//     int data;
//     Node *next;
// };

// void create_node(Node **p, int row, int col, int x){
//     Node *temp = *p;  // dereferncing to make the changes in "first"..
//     Node *r;


//     // creation of first node or first element of the matrix..
//     if(temp == NULL){
//         temp = new Node();
//         temp->row = row;
//         temp->col = col;
//         temp->data = x;
//         temp->next = NULL;
//         *p = temp;   // assigning p to temp..
//     }
//     else{   // jab temp ya fir first null na ho.. or for creation of new nodes after first node has been created..
//         while(temp->next != NULL){
//             temp = temp->next;
//         }

//         // creation of new nodes after the first node has been created..
//         r = new Node();
//         r->row = row;
//         r->col = col;
//         r->data = x;
//         r->next = NULL;
//     }   
// }

// void display(Node *first){
//     Node *start = first;

//     cout << "Row Position:" << endl;
//     while(start != NULL){
//         cout << start->row << " ";
//         start = start->next;
//     }
//     cout << endl;
//     cout << "Column Position:" << endl;
//     start = first;
//     while(start != NULL){
//         cout << start->col << " ";
//         start = start->next;
//     }
//     cout << endl;
//     cout << "Data" << endl;
//     start = first;
//      while(start != NULL){
//         cout << start->data << " ";
//         start = start->next;
//     }
// }

// int main(){

//     int sparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
//                                { 0 , 0 , 5 , 7 , 0 },
//                                { 0 , 0 , 0 , 0 , 0 },
//                                { 0 , 2 , 6 , 0 , 0 } };


//     Node *first = NULL;

//     for(int i=0; i<4; i++){
//         for(int j=0; j<5; j++){
            
//             if(sparseMatrix[i][j] != 0){
//                 create_node(&first, i, j, sparseMatrix[i][j]);
//             }

//         }
//     }

//     display(first);

//     return 0;
// }



// C++ program for sparse matrix representation.
// Using Link list
#include<iostream>
using namespace std;

// Node class to represent link list
class Node
{
	public:
	int row;
	int col;
	int data;
	Node *next;
};

// Function to create new node
void create_new_node(Node **p, int row_index,
					int col_index, int x)
{
	Node *temp = *p;
	Node *r;
	
	// If link list is empty then
	// create first node and assign value.
	if (temp == NULL)
	{
		temp = new Node();
		temp->row = row_index;
		temp->col = col_index;
		temp->data = x;
		temp->next = NULL;
		*p = temp;
	}

	// If link list is already created
	// then append newly created node
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
			
		r = new Node();
		r->row = row_index;
		r->col = col_index;
		r->data = x;
		r->next = NULL;
		temp->next = r;
	}
}

// Function prints contents of linked list
// starting from start
void printList(Node *start)
{
	Node *ptr = start;
	cout << "row_position:";
	while (ptr != NULL)
	{
		cout << ptr->row << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "column_position:";

	ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->col << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "Value:";
	ptr = start;
	
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

// Driver Code
int main()
{
	
	// 4x5 sparse matrix
	int sparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
							{ 0 , 0 , 5 , 7 , 0 },
							{ 0 , 0 , 0 , 0 , 0 },
							{ 0 , 2 , 6 , 0 , 0 } };
	
	// Creating head/first node of list as NULL
	Node *first = NULL;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			
			// Pass only those values which
			// are non - zero
			if (sparseMatrix[i][j] != 0)
				create_new_node(&first, i, j,
								sparseMatrix[i][j]);
		}
	}
	printList(first);

	return 0;
}

// This code is contributed by ronaksuba
