
#include <stdlib.h>
#include "BSTree.h"


//*********************************************************************************************
// 创建空树
//*********************************************************************************************

const void *defaultGetKey( const void *pData )
{
	return pData;
}

BST_t *newBST( CmpFunc_t *cmp, GetKeyFunc_t *getKey )
{
	BST_t *pBST = NULL;
	if ( cmp != NULL )
		pBST = malloc( sizeof(BST_t) );
	if ( pBST != NULL )
	{
		pBST->pRoot = NULL;
		pBST->cmp = cmp;
		pBST->getKey = ( getKey != NULL ) ? getKey : defaultGetKey;
	}
	return pBST;
}


//*********************************************************************************************
// 插入新节点
//*********************************************************************************************

static _Bool insert( BST_t *pBST, Node_t **ppNode, const void *pData, size_t size );

_Bool BST_insert( BST_t *pBST, const void *pData, size_t size )
{
	if ( pBST == NULL || pData == NULL || size == 0 )
		return false;
	return insert( pBST, &(pBST->pRoot), pData, size );
}

static _Bool insert( BST_t *pBST, Node_t **ppNode, const void *pData, size_t size )
{
	Node_t *pNode = *ppNode;		// 指向子树根节点的指针，
									// 新的节点要插入此子树中。
	if ( pNode == NULL )
	{								// 在这里，为新的叶子节点分配空间。
		pNode = malloc( sizeof(Node_t) + size );
		if ( pNode != NULL )
		{
			pNode->left = pNode->right = NULL;		// 初始化新的节点成员。
			memcpy( pNode->data, pData, size );
			*ppNode = pNode;						// 插入新的节点。
			return true;
		} 
		else
			return false;
	} 
	else							// 继续找地方...
	{
		const void *key1 = pBST->getKey( pData ),
				   *key2 = pBST->getKey( pNode->data );
		if ( pBST->cmp( key1, key2 ) < 0 )
			return insert( pBST , &(pNode->left), pData, size );	// ...在左边找
		else
			return insert( pBST, &(pNode->right), pData, size );	// 或在右边找。
	}
}


//*********************************************************************************************
// 在树中找数据
//*********************************************************************************************

static const void *search( BST_t *pBST, const Node_t *pNode, const void *pKey );

const void *BST_search( BST_t *pBST, const void *pKey )
{
	if ( pBST == NULL || pKey == NULL )
		return NULL;
	return search( pBST, pBST->pRoot, pKey );	// 从树根开始
}

static const void *search( BST_t *pBST, const Node_t *pNode, const void *pKey )
{
	if ( pNode == NULL )		// 没有子树了；
		return NULL;			// 没有找到。
	else
	{							// 比较数据
		int cmp_res = pBST->cmp( pKey, pBST->getKey(pNode->data) );

		if ( cmp_res == 0 )		// 寻找匹配的节点。
			return pNode->data;
		else if ( cmp_res < 0 )							// 在左子树
			return search( pBST, pNode->left, pKey );	// 继续寻找，
		else
			return search( pBST, pNode->right, pKey );	// 或者在右子树
	}													// 继续寻找
}


//*********************************************************************************************
// 从树中删除节点
//*********************************************************************************************

static Node_t *detachMin( Node_t **ppNode )
{
	Node_t *pNode = *ppNode;					// 指向目前节点的指针
	if ( pNode == NULL )
		return NULL;							// pNode是一个空的子树。
	else if ( pNode->left != NULL )
		return datachMin( &(pNode->left) );		// 左子树中的最小。
	else
	{											// pNode指向最小节点
		*ppNode = pNode->right;					// 附加右子节点到父节点之下。
		return pNode;
	}
}

static _Bool erase( BST_t *pBST, Node_t **ppNode, const void *pKey );

_Bool BST_erase( BST_t *pBST, const void *pKey )
{
	if ( pBST == NULL || pKey == NULL ) return false;
	return erase( pBST, &(pBST->pRoot), pKey );		// 从树根开始。
}

static _Bool erase( BST_t *pBST, Node_t **ppNode, const void *pKey )
{
	Node_t *pNode = *ppNode;		// 指到目前节点。
	if ( pNode == NULL )			
		return false;				// 找不到符合的节点

	int cmp_res = pBST->cmp( pKey, pBST->getKey( pNode->data ) );	// 比较数据；

	if ( cmp_res < 0 )									// 继续寻找
		return erase( pBST, &(pNode->left), pKey );		// 在左子树中，
	else if ( cmp_res > 0 )
		return erase( pBST, &(pNode->right), pKey );	// 或在右子树中。
	else
	{											// 找到欲删除的节点。
		if ( pNode->left == NULL )				// 如果只有一个或零个孩子，
			*ppNode = pNode->right;				// 将子节点附加到父节点之下。
		else if ( pNode->right == NULL )
			*ppNode = pNode->left;
		else								// 两个子节点：用右边子树中的
		{									// 的最小值来取代。
			Node_t *pMin = detachMin( &(pNode->right) );
			*ppNode = pMin;					// 连接"被删除节点"的父节点。
			pMin->left = pNode->left;		// 连接"被删除节点"的子节点。
			pMin->right = pNode->right;
		}
		free( pNode );					// 释放被删除节点的内存。
		return true;
	}
}

static void clear( Node_t *pNode );

void BST_clear( BST_t *pBST )
{
	if ( pBST != NULL )
	{
		clear( pBST->pRoot );
		pBST->pRoot = NULL;
	}
}

static void clear( Node_t *pNode )
{
	if ( pNode != NULL )
	{
		clear( pNode->left );
		clear( pNode->right );
		free( pNode );
	}
}


//*********************************************************************************************
// 在树中遍历
//*********************************************************************************************

static int inorder( Node_t *pNode, _Bool (*action)( void *pData ) );

int BST_inorder( BST_t *pBST, _Bool (*action)( void *pData ) )
{
	if ( pBST == NULL || action == NULL )
		return 0;
	else
		return inorder( pBST->pRoot, action );
}

static int inorder( Node_t *pNode, _Bool (*action)( void *pData ) )
{
	int count = 0;
	if ( pNode == NULL )
		return 0;
	count = inorder( pNode->left, action );		// L：遍历左边子树
	if ( action( pNode ->data ) )				// N：遍历目前的节点
		++count;
	count += inorder( pNode->right, action );	// R：遍历右边子树。
	return count;
}