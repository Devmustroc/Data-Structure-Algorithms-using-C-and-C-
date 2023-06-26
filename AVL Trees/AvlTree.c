#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node *lChild;
    int data;
    int height;
    struct Node *rChild;
}*root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lChild ? p->lChild->height : 0;
    hr = p && p->rChild ? p->rChild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lChild ? p->lChild->height : 0;
    hr = p && p->rChild ? p->rChild->height : 0;
    return hl - hr;

}

struct Node * LLRotation(struct Node *p)
{
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;

    pl->rChild = p;
    p->lChild = plr;
    p->height = NodeHeight(p);
    pl->height  = NodeHeight(pl);
    if (root == p)
    {
        root = pl;
    }
    return pl;
}
struct Node * LRRotation(struct Node *p)
{
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;

    pl->rChild = plr->lChild;
    p->lChild = plr->rChild;

    plr->lChild = pl;
    plr->rChild = p;


}
struct Node * RRRotation(struct Node *p)
{

}
struct Node * RLRotation(struct Node *p)
{

}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if (key < p->data) p->lChild = RInsert(p->lChild, key);
    else if (key > p->data) p->rChild = RInsert(p->rChild, key);
    p->height = NodeHeight(p);
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lChild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lChild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rChild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rChild) == 1)
        return RLRotation(p);

    return p;
}


int main()
{
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);
    return 0;
}
