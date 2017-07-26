
#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>

/* 树节点的结构类型的定义 */
typedef struct Node
{
	struct Node *left,		// 指向左边
				*right;		// 和右边的字节点。
	size_t size;			// 数据的空间大小。
	char data[];			// 数据本身。
} Node_t;

typedef const void *GetKeyFunc_t( const void *pData );		// 得到“对应于数据”的键值。

typedef int CmpFunc_t( const void *pKey1, const void *pKey2 );	// 比较“对应于数据”的键值。

/* 树的结构类型的定义 */
typedef struct  
{
	struct Node *pRoot;		// 指向根的指针。
	CmpFunc_t *cmp;			// 比较两个键值。
	GetKeyFunc_t *getKey;	// 将数据转换成键值。
} BST_t;

// 动态地创建一个新的对象，类型为BST_t，并返回指向此对象的指针。
BST_t *newBST( CmpFunc_t *cmp, GetKeyFunc_t *getKey );		

// 动态地创建一个新的节点，将pData指向的数据复制到新节点中，然后将新节点插入到指定的树中。
_Bool BST_insert( BST_t *pBST, const void *pData, size_t size );	

// 搜索此树，比较确定与pKey具有相同键值的项目，然后返回一个“指向此项目节点”的指针。
const void *BST_search( BST_t *pBST, const void *pKey );

// 删除第一个“数据内容键值符合“pKey”的节点。
_Bool BST_erase( BST_t *pBST, const void *pKey );

// 删除树中的所有节点。
void BST_clear( BST_t *pBST );

int BST_inorder( BST_t *pBST, _Bool (*action)( void *pData ) );

/*
int BST_rev_inorder( BST_t *pBST, _Bool (*action)( void *pData ) );

int BST_preorder( BST_t *pBST, _Bool (*action)( void *pData ) );

int BST_postorder( BST_t *pBST, _Bool (*action)( void *pData ) );
*/

#endif