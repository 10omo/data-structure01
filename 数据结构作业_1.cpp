//线性表的链式存储结构课堂练习题
/*问题描述： 假设你正在准备去购物，并需要一个购物清单。你希望使用线性表的链式表示
来管理这个购物清单。*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
struct ShoppingItem {
 char name[50]; // 商品名称
 int quantity; // 商品数量
 struct ShoppingItem* next; // 指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL; // 初始化购物清单为空
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
	
	char name[3][50]={"苹果手机","华为手机","三星手机"};
	//添加商品到购物清单：
	addItem(name[0],80);
	addItem(name[1],70);
	addItem(name[2],60);
	displayList();

	//从购物清单中移除商品：
	printf("从购物清单中移除商品，");
	removeItem(name[2]);
	displayList();

	//修改购物清单中商品的数量：
	printf("修改购物清单中商品的数量，");
	updateQuantity(name[0],40);
	displayList();

	//计算购物清单中商品的总数量：
	printf("计算购物清单中商品的总数量，");
	int total=0;
	total=totalQuantity();
	printf("购物清单中商品的总数量为：%d，",total);
	
	//查找购物清单中的商品：
	printf("查找购物清单中的商品，");
	findItem(name[1]);
	
	//排序购物清单
	printf("排序");
	sortList();
	displayList();
	
	
	//合并购物清单：	
	//购物清单2
	char name2[2][50]={"牙刷","牙膏"};
	printf("合并购物清单，");
    addItem2(name2[0],3);
	addItem2(name2[1],2);
	mergeLists(&shoppingList,&shoppingList2);
	displayList();
	
	
	//删除购物清单中的商品：
	//重复增加一项华为手机商品
	addItem(name[1],20);
	printf("删除购物清单中的商品，");
	deleteItem(name[1],1); 
	displayList();

	//清空购物清单 
	clearList();
	printf("清空购物清单后，");
	displayList();
	
	return 0;
	
} 

//1. 添加商品到购物清单：
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
//2. 从购物清单中移除商品：
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


//3. 查看购物清单：
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("购物清单:\n");
 while (current!= NULL) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 current=current->next;
 } 
}

//4. 修改购物清单中商品的数量：
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

//5. 清空购物清单：
void clearList() {
 while (shoppingList != NULL) {
 temp=shoppingList;
 shoppingList=temp->next;
 free(temp);
 }
}

//6. 计算购物清单中商品的总数量：
int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
 total++;
 current=current->next; 
 }
 return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("查找商品 \"%s\" ：\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - 数量：%d", current->name, current->quantity);
 printf("\n");
 return;
 }
 current=current->next;
 }
 printf("未找到商品 \"%s\"。\n", itemName);
}


//8. 排序购物清单：
void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // 交换商品信息
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

//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 struct ShoppingItem* current = *list1;
 // 遍历到第一个购物清单的末尾
 while(current->next!=NULL){
 	current=current->next;
}
 // 将第二个购物清单连接到第一个清单的末尾
 current->next = *list2;
 *list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}


//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // 如果要删除的是第一个节点
 struct ShoppingItem* temp = shoppingList;
 shoppingList=shoppingList->next; 
 free(temp);
 if (!deleteAll) break;
 } else {
 // 如果要删除的不是第一个节点
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
