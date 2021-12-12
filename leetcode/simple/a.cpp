#include<iostream>
using namespace std;
typedef int  ElemType; //假设线性表中的元素均为整型

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

void ListCreate_L(LinkList &L)
{
    LNode *rearPtr,*curPtr;   //一个尾指针，一个指向新节点的指针
    L=new LNode;
    L->next=NULL;//先建立一个带头结点的单链表
    rearPtr=L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    int a;
    cin>>a;
    while(a!=-1)
    {
        //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr= new LNode;//生成新结点
        curPtr->data=a;//输入元素值
        curPtr->next=NULL;  //最后一个节点的next赋空
        rearPtr->next=curPtr;
        rearPtr=curPtr;
        cin>>a;
    }
}

void ListReverse_L(LinkList &L1,LinkList &L2,LinkList &L)
{
    LNode *p1,*p2,*r,*p;
    r=L;//尾指针r指向头结点
    p1=L1->next;//p1遍历表1
    p2=L2->next;//p2遍历表2
    while(p1&&p2)//先把等长的部分放进去
    {
        if((p1->data)>(p2->data))
        {
            p=new LNode;//生成新结点
            p->data=p2->data;//把数值更小的那个（也就是L2里的）放进链表L里
            p->next=NULL;
            r->next=p;//将p插入到链表的尾部
            r=p;//指针r又指向链表尾部
            p2=p2->next;//L2里的指针向后移动一步
        }
        else
        {
            p=new LNode;
            p->data=p1->data;
            p->next=NULL;
            r->next=p;
            r=p;
            p1=p1->next;
        }
    }
    if(p1==NULL)//表1结束了，放表2
    {
        while(p2)
        {
            p=new LNode;
            p->data=p2->data;
            p->next=NULL;
            r->next=p;
            r=p;
            p2=p2->next;
        }
    }
    else//表2 已经完了，放表1
    {
        while(p1)
        {
            p=new LNode;
            p->data=p1->data;
            p->next=NULL;
            r->next=p;
            r=p;
            p1=p1->next;
        }
    }
}

void ListPrint_L(LinkList &L)
{
//输出单链表
    LNode *p=L->next;  //p指向第一个元素结点
    if(p==NULL)
        cout<<"NULL";
    else
    {
        while(p!=NULL)
        {
            if(p->next!=NULL)
                cout<<p->data<<" ";
            else
                cout<<p->data;
            p=p->next;
        }
        cout<<endl;
    }
}

int main()
{
    LinkList L1,L2,L;
    ListCreate_L(L1);
    ListCreate_L(L2);
    L=new LNode;
    L->next=NULL;
    ListReverse_L(L1,L2,L);
    ListPrint_L(L);
    return 0;
}