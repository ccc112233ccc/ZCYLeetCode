#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;
//节点
class Node
{
public:
    Node() : value(0), next(nullptr), last(nullptr) {}
    Node(int v) : value(v), next(nullptr), last(nullptr) {}
    ~Node()
    {
        // cout << value << " has been deleted\n";
    }
    int value;
    Node *last;
    Node *next;
};

class MyList
{
public:
    MyList() : head(nullptr), tail(nullptr) {}
    MyList(Node *h) : head(h), tail(gettail(h)) {}

    Node *gettail(Node *h)
    {
        while (h->next != nullptr)
        {
            h = h->next;
        }
        return h;
    }
    void push_back(Node *n)
    {
        if (n != nullptr)
        {
            if (head == nullptr)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                n->last = tail;
                tail = n;
            }
        }
    }
    MyList &link(MyList &l)
    {
        push_back(l.head);
        tail = l.tail == nullptr ? tail : l.tail;
        return *this;
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    //反向打印
    void rePrint()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->last;
        }
        cout << "\n";
    }

    //反转链表
    void reverse()
    {
        if (head == nullptr)
            return;
        tail = head;
        Node *cur = head;
        Node *nex = head->next;
        head->next = nullptr;
        head->last = nex;

        Node *temp = nullptr;
        while (nex != nullptr && cur != nullptr)
        {
            temp = nex->next;
            nex->next = cur;
            nex->last = temp;
            cur = nex;
            nex = temp;
        }
        head = cur;
    }
    //使用快慢指针得到链表中间位置
    Node *getMiddle()
    {
        Node *fast = head;
        Node *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ~MyList()
    {
    }
    void free()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
    }
    Node *head;

    //实际使用的话可能不需要尾部节点，遍历一遍链表也能找到
    Node *tail;
};
//打印两个有序链表的公共部分
void printPublic(MyList &l1, MyList &l2)
{
    Node *p1 = l1.head;
    Node *p2 = l2.head;

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->value == p2->value)
        {
            cout << p1->value << " ";
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->value < p2->value)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
    cout << "\n";
}
//判断链表是否回文
bool Palindrom(MyList &l)
{
    stack<int> s;
    Node *h = l.head;
    while (h != nullptr)
    {
        s.push(h->value);
        h = h->next;
    }
    h = l.head;
    while (h != nullptr)
    {
        if (h->value != s.top())
        {
            return false;
        }
        h = h->next;
        s.pop();
    }

    return true;
}
//判断是否回文，空间复杂度O(1)
bool Palindrom2(MyList &l)
{
    Node *m = l.getMiddle();
    Node *rh = m->next;

    m->next = nullptr;
    rh->last = nullptr;
    MyList r(rh);
    r.reverse();

    Node *n1 = l.head;
    Node *n2 = r.head;
    bool res = true;
    while (n1 != nullptr && n2 != nullptr)
    {
        if (n1->value != n2->value)
        {
            res = false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }

    //把右边的链表转回去
    r.reverse();
    m->next = r.head;
    rh->last = m;

    return res;
}
int main()
{
    cout << 1 % 4 << '\n';

    return 0;
}
