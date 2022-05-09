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
			ptr=searchIterative(head,key); // ptr에 searchIterative의 return 값 할당
			if(ptr!=NULL)
			printf("\n node [%d] found at %p\n", ptr->key, ptr); // 해당 key값을 갖고 있는 노드의 주소 출력
			else
			printf("\n Cannot find the node [%d]\n", key); // 해당 key값을 갖고있는 노드를 찾지 못한 경우
			break;
			case's':case'S':
			printf("Your key = ");
			scanf("%d", &key);
			ptr=searchRecursive(head->left,key); // ptr에 searchRecursive의 return값 할당
			if(ptr!=NULL)
			printf("\n node [%d] found at %p\n", ptr->key,ptr); // 해당 key값을 갖고있는 노드의 주소 출력
			else
			printf("\n Cannot find the node [%d]\n", key); // ptr이 NULL인 경우, 즉 재귀함수로 해당 key값을 갖고있는 노드를 찾지 못한 경우
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
    (*h)->left=NULL; // head의 초기 값 설정
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

int insert(Node* head, int key) // key(입력)값을 key로 받는 노드 생성
{
    Node* newNode = (Node*)malloc(sizeof(Node)); // newNode 생성 및 메모리 할당
    newNode->key=key; // 초기값 설정
    newNode->left=NULL;
    newNode->right=NULL;

    if(head->left==NULL) { // 트리가 비어있을 경우
        head->left = newNode;
        return 1;
    }

    Node* ptr= head->left; // 트리가 비어있지 않은 경우 ptr을 레벨 1 노드로 지정

    Node* parentNode = NULL;

    while(ptr!=NULL){ // key값 비교해가며 자리 찾기
        if(ptr->key==key) return 1; // key 값을 찾으면 return

        parentNode=ptr; // parentNode에 ptr 할당

        if(ptr->key<key) // ptr의 key값보다 입력값이 크면
        ptr=ptr->right; // 오른쪽으로 이동
        else
        ptr=ptr->left; // ptr의 key값보다 입력값이 작으면 왼쪽으로 이동
    }

    if(parentNode->key>key)
    parentNode->left=newNode; // 부모노드의 값보다 작으면 왼쪽
    else
    parentNode->right=newNode; // 부모노드의 값보다 크면 오른쪽에 저장
    return 1;
}

int deleteLeafNode(Node* head, int key) // key(입력값)을 key로 갖고있는 노드 삭제
{
    if(head==NULL){
        printf("\n Nothing to delete!\n");
        return -1;
    }

    if(head->left==NULL) {
        printf("\n Nothing to delete!\n");
        return -1;
    }

    Node* ptr = head->left; // 트리의 레벨 1 노드를 ptr로 지정

    Node* parentNode=head; // parentNode에 head 할당

    while(ptr!=NULL){

        if(ptr->key==key){ // ptr->key 가 입력값일때
            if(ptr->left==NULL && ptr->right == NULL) { // 자식노드가 없을 때

                if(parentNode==head) // 부모노드가 head일때, 즉 ptr이 레벨 1의 노드일때
                head->left=NULL; // head -> left 끊어준 뒤 메모리 해제

                if(parentNode->left==ptr) // parentNode의 left에 ptr이 있을 때, 즉 ptr의 key값이 parentNode의 key보다 작을 때
                parentNode->left=NULL; 
                else // ptr의 key 값이 parentNode의 key보다 클 때
                parentNode->right=NULL;

                free(ptr);
            }
            else{
                printf("the node [%d] is not a leaf \n", ptr->key); // 자식노드가 있을 때
            }
            return 1;
        }

        parentNode = ptr; // parentNode 에 ptr 할당

        if(ptr->key<key) // 입력받은 key값이 ptr->key 보다 클때
        ptr=ptr->right; // 오른쪽으로 이동
        else
        ptr=ptr->left; // 작을 때 왼쪽으로 이동
    }
    printf("Cannot find the node for key [%d]\n ", key); // key값을 갖는 노드를 찾지 못했을 때

    return 1;
}

Node* searchRecursive(Node* ptr, int key) // 재귀함수로 특정 key 값을 갖고있는 노드 찾기
{
    if(ptr==NULL) // 트리가 비어있는 경우 (여기서 ptr은 head->left이며 트리의 레벨 1에 해당하는 부분)
    return NULL;

    if(ptr->key < key) // 입력 key 값이 ptr의 key보다 클 경우
    ptr=searchRecursive(ptr->right, key); // ptr(head->left)로 받은 부분을 ptr->right로 이동하면서 재귀호출
    else if (ptr->key > key) // 입력 key 값이 ptr의 key보다 작은 경우
    ptr=searchRecursive(ptr->left, key); // ptr(head->left)로 받은 부분을 ptr->left로 이동하면서 재귀호출

    return ptr; //해당 ptr return
}

Node* searchIterative(Node* head, int key) // 반복함수로 특정 key 값을 갖고있는 노드 찾기
{
    Node* ptr=head->left; // ptr을 트리의 레벨 1 에 해당하는 노드로 지정

    while(ptr!=NULL)
    {
        if(ptr->key==key) // ptr의 key값이 입력받은 key 값일 때
        return ptr; // ptr을 return

        if(ptr->key<key) ptr= ptr->right; // 입력받은 key값이 ptr의 key값보다 클 때, 오른쪽아래로 이동
        else // 그렇지 않을때
        ptr=ptr->left; // 왼쪽 아래로 이동
    }

    return NULL;
}

void freeNode(Node* ptr) // freeBST에서 사용될 함수
{
    if(ptr) { // ptr의 왼쪽, 오른쪽 freeNode재귀호출
        freeNode(ptr->left);
        freeNode(ptr->right);
        free(ptr); // ptr 메모리 해제
    }
}

int freeBST(Node* head) // 트리 메모리 해제
{
	if(head->left==head)
    {
        free(head);
        return 1;
    }

    Node* p = head->left; // p를 트리의 레벨 1 에 위치한 노드로 지정

    freeNode(p); // freeNode함수는 p와 p의 자식노드들 모두를 메모리 해제하는 함수

    free(head); // head 메모리 해제
    return 1;
}