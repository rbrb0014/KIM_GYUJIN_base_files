#include <stdio.h>
#include <stdlib.h>
#define MAX 503

typedef int Element;

typedef struct
{
    Element *stack;
    int size;
    int top;
} Stack;

Stack *CreateStack(int size)
{
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    if (pStack == NULL)
        return NULL;

    pStack->stack = (Element *)malloc(size * sizeof(Element));
    if (pStack->stack == NULL)
    {
        free(pStack);
        return NULL;
    }

    pStack->size = size;
    pStack->top = -1;

    return pStack;
}

void Push(Stack *pStack, Element item)
{
    //check if stack is full
    if (pStack->top == pStack->size - 1)
        return;
    pStack->stack[++pStack->top] = item;
}

Element Pop(Stack *pStack)
{
    // check if stack is empty
    if (pStack->top < 0)
        return 0;
    return pStack->stack[pStack->top--];
}

Element Top(Stack *pStack)
{
    if (pStack->top < 0) // stack is empty
        return 0;
    return pStack->stack[pStack->top];
}

void DestroyStack(Stack *pStack)
{
    if (pStack->size > 0)
        free(pStack->stack); // dealloc memory
    free(pStack);
}

bool isFullStack(Stack *pStack){
    return true;
}
bool isEmptyStack(Stack *pStack){
    return true;
}
int CountStackItem(Stack *pStack){
    return 0;
}
void ClearStack(Stack *pStack){
    return;
}

int main()
{
    int i = 0;
    int item = 0;
    Stack *pStack = CreateStack(100);
    printf("Input 10 numbers :");
    for (i = 0; i < 10; i++)
    {
        item = 0;
        scanf("%d", &item);
        Push(pStack, item);
    }
    printf("Reversed :");
    while(pStack->top>=0)
    {
        item = Pop(pStack);
        printf("%d ", item);
    }
    printf("\n");
    DestroyStack(pStack);
    pStack = NULL;
    return 0;
}

//ctrl+shift+B  gcc_compile     build
//ctrl+P    task execute_c      execute