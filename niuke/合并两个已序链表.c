#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

//循环合成链表
ListNode* Merge(ListNode* pHead1,ListNode* pHead2){
    if(NULL == pHead1)
    return pHead2;
    if(NULL == pHead2)
    return pHead2;

    ListNode* pNewHead=NULL;
    ListNode* pTailNode=NULL;
    ListNode* pCur1=pHead1;
    ListNode* pCur2=pHead2;

    if(pCur1->m_nValue<pCur2->m_nValue){
        pNewHead=pCur1;
        pTailNode=pCur1;
        pCur1=pCur1->m_pNext;
    }
    else{
        pNewHead=pCur2;
        pTailNode=pCur2;
        pCur2=pCur2->m_pNext;
    }

    while(pCur1&&pCur2){
        if(pCur1->m_nValue<pCur2->m_nValue){
            pTailNode=pCur1;
            pCur1=pCur1->m_pNext;
        }
    else{
            pTailNode=pCur2;
            pCur2=pCur2->m_pNext;
        }
        pTailNode=pTailNode->m_pNext;
    }
    if(pCur1)
        pTailNode->m_pNext=pCur1;
    if(pCur2)
        pTailNode->m_pNext=pCur2;

    return pNewHead;
}

//递归合成新链表
ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
{
    if (NULL == pHead1 && NULL == pHead2)
        return NULL;
    if (NULL == pHead1)
        return pHead2;
    if (NULL == pHead2)
        return pHead1;
    ListNode* pNewHead = new ListNode(0);
    while (pHead1&&pHead2){
        if (pHead1->val<pHead2->val){
            pNewHead->val = pHead1->val;
            pNewHead->next=
        }
    }
}
