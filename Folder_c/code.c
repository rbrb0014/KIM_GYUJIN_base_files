#include <stdio.h>
#include <stdlib.h>
#define SECURE_NO_WARNINGS_

typedef struct
{
    int exp;
    NODE *llink;//prev
    NODE *rlink;//next
    int coef;
} NODE;

static int _insert(LIST *pList, NODE *pPre, tTOKEN *dataInPtr)
{
    //헤드가 이상한걸 가르키게 됨
    //노드 생성
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode)
        return 0;
    newNode->dataPtr = dataInPtr;
    int addNode(LIST * pList, tTOKEN * dataInPtr)
    {
        NODE *pPre, *pLoc;
        int found = _search(pList, &pPre, &pLoc, dataInPtr->token);
        if (found)
        {
            pLoc->dataPtr->freq++;
            return 2;
        }
        int ret = _insert(pList, pPre, dataInPtr);
        if (!ret)
            return 0;
        else
            return 1;
    }
    if (emptyList(pList))
    {
        pList->head = newNode;
        pList->rear = newNode;
        newNode->llink = NULL;
        newNode->rlink = NULL;
    }
    else
    {
        if (!pPre)
        {
            newNode->rlink = NULL;
            newNode->llink = pList->head;
            pList->head->rlink = newNode;
            pList->head = newNode;
        }
        else
        {
            newNode->llink = pPre->llink;
            newNode->rlink = pPre;

            if (!pPre->llink)
                pList->rear = newNode;
            else
                newNode->llink->rlink = newNode;

            pPre->llink = newNode;
        }
    }
    pList->count++;
    return 1;
}
static int _search(LIST *pList, NODE **pPre, NODE **pLoc, char *pArgu)
{
    /*
	empty면 null null
	맨처음이면 null first
	중간에 있으면 pre loc
	마지막뒤면 last null
	*/

    //맨처음이면 ppre=ploc, 아니면 ppre->rlink==ploc으로 함
    //만약 없는걸 찾으면 ppre와 ploc 사이에 있다고 반환해주기

    *pPre = NULL;
    *pLoc = pList->head;

    while (*pLoc && strcmp(pArgu, (*pLoc)->dataPtr->token) > 0)
    {
        *pPre = *pLoc;
        *pLoc = (*pLoc)->llink;
    }

    if (!*pLoc)
        return 0;

    return !strcmp(pArgu, (*pLoc)->dataPtr->token);
}

int main()
{
    NODE *H, *T, *S;
    NODE *ptr;

    for (ptr = H; ptr->next != T; ptr = ptr->next)
    {
        S = extract(H, T);
    }
}