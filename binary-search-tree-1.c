#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
}Node;

int initializeBST(Node** h);
void inorderTraversal(Node* ptr);
void preorderTraversal(Node* ptr);
void postorderTraversal(Node* ptr);
int insert(Node* head, int key);
int deleteLeafNode(Node* head, int key);
Node* searchRecursive(Node* ptr, int key);
Node* searchIterative(Node* head, int key);
int freeBST(Node* head);

int main()
{
	char command;
	int key;
	Node* head=NULL;
	Node* ptr=NULL;

    printf("----------[2019037002]---------[hankyuwon]---------\n");

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command){
			case'z':case'Z':
			initializeBST(&head);
			break;
			case'q':case'Q':
			freeBST(head);
			break;
			case'n':case'N':
			printf("Your key = ");
			scanf("%d", &key);
			insert(head,key);
			break;
			case'd':case'D':
			printf("Your key = ");
			scanf("%d", &key);
			deleteLeafNode(head,key);
			break;
			case'f':case'F':
			printf("Your key = ");
			scanf("%d",&key);
			ptr=searchIterative(head,key);
			if(ptr!=NULL)
			printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
			printf("\n Cannot find the node [%d]\n", key);
			break;
			case's':case'S':
			printf("Your key = ");
			scanf("%d", &key);
			ptr=searchRecursive(head->left,key);
			if(ptr!=NULL)
			printf("\n node [%d] found at %p\n", ptr->key,ptr);
			else
			printf("\n Cannot find the node [%d]\n", key);
			break;
			case'i':case'I':
			inorderTraversal(head->left);
			break;
			case'p':case'P':
			preorderTraversal(head->left);
			break;
			case't':case'T':
			postorderTraversal(head->left);
			break;
			default:
			printf("\n       >>>>>  Concentration!!  <<<<<       \n");
			break;
		}

	}while(command!='q'&& command!='Q');

	return 1;
}

int initializeBST(Node** h) // head 노드 생성
{
    if(*h!=NULL) // head 가 NULL이 아니면
    freeBST(*h); // head 초기화

    *h=(Node*)malloc(sizeof(Node)); // head 생성, 메모리 할당
    (*h)->left=NULL; // 초기 값 설정
    (*h)->right=*h;
    (*h)->key=-9999;
    return 1;
}

void inorderTraversal(Node* ptr) // 중위순회 알고리즘
{
    if(ptr)
    {
        inorderTraversal(ptr->left); // 왼쪽 서브트리를 중위순회한다
        printf(" [%d] ", ptr->key); // 노드를 출력한다
        inorderTraversal(ptr->right); //오른쪽 서브트리를 중위순회한다
    }
}

void preorderTraversal(Node* ptr) // 전위순회
{
    if(ptr){
        printf(" [%d] ", ptr->key); // 노드를 출력한다
        preorderTraversal(ptr->left); // 왼쪽 서브트리를 전위순회한다
        preorderTraversal(ptr->right); // 오른쪽 서브트리를 전위순회한다
    }
}

void postorderTraversal(Node* ptr) // 후위순회 알고리즘
{
    if(ptr){
        postorderTraversal(ptr->left); // 왼쪽 서브트리를 후위순회한다
        postorderTraversal(ptr->right); // 오른쪽 서브트리를 후위순회한다
        printf(" [%d] ", ptr->key); // 노드를 출력한다
    }
}

int insert(Node* head, int key)
{

}

int deleteLeafNode(Node* head, int key)
{

}

Node* searchRecursive(Node* ptr, int key)
{

}

Node* searchIterative(Node* head, int key)
{

}

void freeNode(Node* ptr)
{

}

int freeBST(Node* head)
{
	
}