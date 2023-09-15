//���Ա����ʽ�洢�ṹ������ϰ��
/*���������� ����������׼��ȥ�������Ҫһ�������嵥����ϣ��ʹ�����Ա����ʽ��ʾ
��������������嵥��*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
struct ShoppingItem {
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL; // ��ʼ�������嵥Ϊ��
struct ShoppingItem* temp = NULL;
void addItem(char itemName[], int itemQuantity);
void addItem2(char itemName[], int itemQuantity); 
void removeItem(char itemName[]);
void displayList();
void updateQuantity(char itemName[], int newItemQuantity); 
void clearList();
int totalQuantity();
void findItem(char itemName[]); 
void sortList();
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2);
void deleteItem(char itemName[], int deleteAll); 
int main()
{
	
	char name[3][50]={"ƻ���ֻ�","��Ϊ�ֻ�","�����ֻ�"};
	//�����Ʒ�������嵥��
	addItem(name[0],80);
	addItem(name[1],70);
	addItem(name[2],60);
	displayList();

	//�ӹ����嵥���Ƴ���Ʒ��
	printf("�ӹ����嵥���Ƴ���Ʒ��");
	removeItem(name[2]);
	displayList();

	//�޸Ĺ����嵥����Ʒ��������
	printf("�޸Ĺ����嵥����Ʒ��������");
	updateQuantity(name[0],40);
	displayList();

	//���㹺���嵥����Ʒ����������
	printf("���㹺���嵥����Ʒ����������");
	int total=0;
	total=totalQuantity();
	printf("�����嵥����Ʒ��������Ϊ��%d��",total);
	
	//���ҹ����嵥�е���Ʒ��
	printf("���ҹ����嵥�е���Ʒ��");
	findItem(name[1]);
	
	//�������嵥
	printf("����");
	sortList();
	displayList();
	
	
	//�ϲ������嵥��	
	//�����嵥2
	char name2[2][50]={"��ˢ","����"};
	printf("�ϲ������嵥��");
    addItem2(name2[0],3);
	addItem2(name2[1],2);
	mergeLists(&shoppingList,&shoppingList2);
	displayList();
	
	
	//ɾ�������嵥�е���Ʒ��
	//�ظ�����һ�Ϊ�ֻ���Ʒ
	addItem(name[1],20);
	printf("ɾ�������嵥�е���Ʒ��");
	deleteItem(name[1],1); 
	displayList();

	//��չ����嵥 
	clearList();
	printf("��չ����嵥��");
	displayList();
	
	return 0;
	
} 

//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
	
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	struct ShoppingItem* p = shoppingList;
	 
	strcpy(newItem->name,itemName);
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	 
	if(shoppingList==NULL)shoppingList = newItem;
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
	p->next=newItem;
	}
}

void addItem2(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	struct ShoppingItem* p = shoppingList2;
	 
	strcpy(newItem->name,itemName);
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	 
	if(shoppingList2==NULL)shoppingList2 = newItem;
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
	p->next=newItem;
	}
}
//2. �ӹ����嵥���Ƴ���Ʒ��
void removeItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* previous = NULL;
	while (current != NULL) {
	if (strcmp(current->name, itemName) == 0) {
	if (previous != NULL) {
	previous->next = current->next;
	} else {
	shoppingList = current->next;
	}
	free(current);
	break;
	}

	previous=current;
	current=current->next;
	}
}


//3. �鿴�����嵥��
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("�����嵥:\n");
 while (current!= NULL) {
 printf("%s - ������%d\n", current->name, current->quantity);
 current=current->next;
 } 
}

//4. �޸Ĺ����嵥����Ʒ��������
void updateQuantity(char itemName[], int newItemQuantity) {
 struct ShoppingItem* current = shoppingList;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 current->quantity=newItemQuantity;
 break;
 }
 current = current->next;
 }
}

//5. ��չ����嵥��
void clearList() {
 while (shoppingList != NULL) {
 temp=shoppingList;
 shoppingList=temp->next;
 free(temp);
 }
}

//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
 total++;
 current=current->next; 
 }
 return total;
}

//7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("������Ʒ \"%s\" ��\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - ������%d", current->name, current->quantity);
 printf("\n");
 return;
 }
 current=current->next;
 }
 printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}


//8. �������嵥��
void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // ������Ʒ��Ϣ
 strcpy(tempName,current->name);
 strcpy(current->name,nextItem->name);
 strcpy(nextItem->name,tempName);
 
 tempQuantity = current->quantity;
 current->quantity = nextItem->quantity;
 nextItem->quantity = tempQuantity;
 }
 nextItem = nextItem->next;
 }
 current = current->next;
 }
}

//9. �ϲ������嵥��
//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 struct ShoppingItem* current = *list1;
 // ��������һ�������嵥��ĩβ
 while(current->next!=NULL){
 	current=current->next;
}
 // ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
 current->next = *list2;
 *list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}


//10. ɾ�������嵥�е���Ʒ��
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ��
//����ѡ��ɾ������һ����ȫ����
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // ���Ҫɾ�����ǵ�һ���ڵ�
 struct ShoppingItem* temp = shoppingList;
 shoppingList=shoppingList->next; 
 free(temp);
 if (!deleteAll) break;
 } else {
 // ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
 prev->next=current->next;
 free(current);
 current = prev->next;
 if (!deleteAll) break;
 }
 } else {
 prev = current;
 current = current->next;
 }
 }
}
