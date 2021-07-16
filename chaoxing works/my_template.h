#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

template<typename T> class Vec_base
{
    protected:int vec_capacity=1,vec_length=0;
    protected:T *arr = new T[vec_capacity];
    public:

    void push_back(T input)
    {
        if(vec_length == vec_capacity)
        {
            auto temp = arr;
            T *p = new T[vec_capacity*2];
            vec_capacity *= 2;
            for(int i = 0;i<vec_length;i++)
            {
                p[i] = arr[i];
            }
            arr = p;
            delete[] temp;
        }
        arr[vec_length] = input;
        vec_length++;
    }

    void pop_back()
    {
        if(!vec_length)
            throw "No any elements in vector";
        else
        {
            vec_length--;
        }

        if(vec_length*2 == vec_capacity)
        {
            auto *temp = arr;
            T *p = new T[vec_capacity/2];
            vec_capacity /= 2;
            for(int i = 0;i<vec_length;i++)
            {
                p[i] = arr[i];
            }
            arr = p;
            delete temp;
        }
    }

    bool empty()
    {
        return vec_length == 0;
    }

    int size()
    {
        return vec_length;
    }

    T& operator[](int pos)
    {
        return *(arr+pos);
    }

    void output()
    {
        for(int i = 0;i<vec_length;i++)
            std::cout<<arr[i]<<' ';
        std::cout<<std::endl;
    }
};



/*-------------------------------*/
template<typename T>
class mystack:public Vec_base<T>
{
public:T top()
    {
        return this->arr [(this->vec_length)-1];
    }
};



/*----------------------------------*/
template<typename T>
class myqueue
{
    protected:
    unsigned int queue_capacity=1,queue_length=0,head=0,tail=0;
    T* arr = new T[queue_capacity];
    public:
    void push(T input)
    {
        arr[tail] = input;
        queue_length++;
        tail++;
        tail %= queue_capacity;
        if(tail == head)
        {
            auto *temp = arr;
            T *p = new T[queue_capacity*2];
            for(int i = 0;i<queue_capacity;i++)
            {
                p[i] = arr[(i+head)%queue_capacity];
                if(i == queue_capacity - 1)
                    tail = i+1; 
            }
            head = 0;
            queue_capacity *= 2;
            arr = p;
            delete temp;
        }
    }

    void pop()
    {
        if(!queue_length)
            throw "No any elements in queue";
        else
        {
            queue_length--;
            head++;
            head %= queue_capacity;
        }

        if(queue_length*2 < queue_capacity)
        {
            auto *temp = arr;
            T *p = new T[queue_capacity/2];
            for(int i = 0;i<queue_length;i++)
            {
                p[i] = arr[(i+head)%queue_capacity];
            }
            queue_capacity /= 2;
            head = 0;
            tail = queue_length%queue_capacity;
            arr = p;
            delete temp;
        }
    }

    int size()
    {
        return queue_length;
    }

    T front()
    {
        return arr[head];
    }

    T back()
    {
        int a = tail-1;
        if(a>=0)
        return arr[tail-1];
        else
        {
            return arr[queue_capacity-1];
        }
        
    }

    int empty()
    {
        if(!queue_length)
            return 1;
        else
        {
            return 0;
        }
        
    }

    T& operator[](int pos)
    {
        return arr[pos];
    }

    void print()
    {
        int pb = head;
        while(pb != tail)
        {
            std::cout<<arr[pb]<<' ';
            pb++;
            pb %= queue_capacity;
        }
        std::cout<<std::endl;
    }
};


/*---------------------------------*/
template<typename T>
class Mylist_cycle
{
    private:
    class Node
    {
        public:
        T Node_data;
        Node *next,*pre;

        Node()
        {
            next = NULL;
            pre = NULL;
        }
        Node(T data)
        {
            Node_data = data;
            next = NULL;
            pre = NULL;
        }
    };
    Node *head = NULL,*tail = NULL;
    int l_size=0;


    public:

    Mylist_cycle(Mylist_cycle<T> &a)
    {
        auto i = a.begin();
       do
       {
           insert_tail(i->Node_data);
           i++;
       } while (i != a.begin());
    }

    Mylist_cycle()
    {

    }

    class iterator
    {
        friend void Mylist_cycle<T>::erase(iterator pos);
        friend void Mylist_cycle<T>::insert(iterator pos,T inp);

        private:
        Node *node;
        public:
        iterator(Node *v)
        {
            node = v;
        }

        T operator*()
        {
            return node->Node_data;
        }

        Node* operator->()
        {
            return node;
        }
 
        iterator operator++()
        {
            node = node->next;
            return *this;
        }

        iterator operator++(int k)
        {
            iterator temp(node);
            node = node->next;
            return temp;

        }

        iterator operator--()
        {
            node = node->pre;
            return *this;
        }

        iterator operator--(int k)
        {
            iterator temp(node);
            node = node->pre;
            return temp;
        }

        bool operator==(const iterator &a)
        {
            return node == a.node;
        }

        bool operator!=(const iterator &a)
        {
            return node != a.node;
        }
    };

    void insert_head(T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = head;
            head->pre = head;
            tail = head;
            l_size++;
        }
        else
        {
            Node *newnode = new Node(inp);
            newnode->next = head;
            head->pre = newnode;
            head = newnode;
            tail->next = head;
            head->pre = tail;
            l_size++;
        } 
    }

    void insert(iterator pos,T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = head;
            head->pre = head;
            tail = head;
            l_size++;
        }
        else
        {
            Node *newnode = new Node(inp);
            Node *now = pos.node;
            newnode->next = now;
            newnode->pre = now->pre;
            now->pre->next = newnode;
            now->pre = newnode;
            if(pos.node == head)
            {
                head = newnode;
            }
            l_size++;
        }
    }

    void erase(iterator pos)
    {
        Node* now = pos.node;
        if(pos.node == head)
        {
            now->pre->next = now->next;
            now->next->pre = now->pre;
            head = now->next;
        }
        else if(pos.node == tail)
        {
            now->pre->next = now->next;
            now->next->pre = now ->pre;
            tail = now->pre;
        }
        else
        {
        now->pre->next = now->next;
        now->next->pre = now ->pre;
        }
        l_size--;
        
        delete now;
    }

    void pop_back()
    {
        erase(end());
    }

    void insert_tail(T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = head;
            head->pre = head;
            tail = head;
            l_size++;
        }
        else
        {
            Node *ptr = tail;
            Node *new_node = new Node(inp);
            ptr->next = new_node;
            new_node->pre = ptr;
            new_node->next = head;
            tail = new_node;
            head->pre = tail;
            l_size++;
        }
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(tail);
    }

    T front()
    {
        return head->Node_data;
    }
    T back()
    {
        return tail->Node_data;
    }
    bool empty()
    {
        return l_size == 0;
    }
    int size()
    {
        return l_size;
    }

    void remove_unit(T inp)
    {
        auto i = begin();
        do
        {
            if((*i) == inp)
            {
                auto now = i;
                i++;
                erase(now);
            }
            else
            {
                i++;
            }
            
        } while (i != begin());
    }

    void output_line()
    {
        auto i = begin();
        do
        {
            std::cout<<*i<<std::endl;
            i++;
        }
        while(i != begin());
    }
};

template<typename T>
class Mylist
{
    private:
    class Node
    {
        public:
        T Node_data;
        Node *next,*pre;

        Node()
        {
            next = NULL;
            pre = NULL;
        }
        Node(T data)
        {
            Node_data = data;
            next = NULL;
            pre = NULL;
        }
    };
    Node *mynull = new Node();
    Node *head = NULL,*tail = mynull;
    int l_size=0;


    public:

    Mylist(Mylist<T> &a)
    {
        auto i = a.begin();
       do
       {
           insert_tail(i->Node_data);
           i++;
       } while (i != a.begin());
    }

    Mylist()
    {

    }

    class iterator
    {
        friend void Mylist<T>::erase(iterator pos);
        friend void Mylist<T>::insert(iterator pos,T inp);

        private:
        Node *node;
        public:
        iterator(Node *v)
        {
            node = v;
        }

        T operator*()
        {
            return node->Node_data;
        }

        Node* operator->()
        {
            return node;
        }
 
        iterator operator++()
        {
            node = node->next;
            return *this;
        }

        iterator operator++(int k)
        {
            iterator temp(node);
            node = node->next;
            return temp;

        }

        iterator operator--()
        {
            node = node->pre;
            return *this;
        }

        iterator operator--(int k)
        {
            iterator temp(node);
            node = node->pre;
            return temp;
        }

        bool operator==(const iterator &a)
        {
            return node == a.node;
        }

        bool operator!=(const iterator &a)
        {
            return node != a.node;
        }
    };

    void insert_head(T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = tail;
            tail->pre = head;
            l_size++;
        }
        else
        {
            Node *newnode = new Node(inp);
            newnode->next = head;
            head->pre = newnode;
            head = newnode;
            l_size++;
        } 
    }

    void insert_order(T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = tail;
            tail->pre = head;
            l_size++;
        }
        else
        {
            auto now = head;
            while(now->Node_data < inp && now != tail)
            {
                now = now->next;
            }
            if(now == head)
            {
                insert_head(inp);
            }
            else if(now == tail)
            {
                insert_tail(inp);
            }
            else
            {
                Node *newnode = new Node(inp);
                newnode->next = now;
                newnode->pre = now->pre;
                now->pre->next = newnode;
                now->pre = newnode;
            }
            
        } 
    }

    void insert(iterator pos,T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = tail;
            tail->pre = head;
            l_size++;
        }
        else
        {
            Node *newnode = new Node(inp);
            Node *now = pos.node;
            if(pos.node == head)
            {
                newnode->next = now;
                now->pre = newnode;
                head = newnode;
            }
            else
            {
                newnode->next = now;
                newnode->pre = now->pre;
                now->pre->next = newnode;
                now->pre = newnode;
            }
            
            l_size++;
        }
    }

    void replace(iterator pos, T inp)
    {
        pos->Node_data = inp;
    }

    void erase(iterator pos)
    {
        Node* now = pos.node;
        if(pos.node == head)
        {
            head = now->next;
            now->next->pre = NULL;
        }
        else if(pos.node == tail)
        {
            throw("you can't delete tail");
        }
        else
        {
        now->pre->next = now->next;
        now->next->pre = now ->pre;
        }
        l_size--;
        
        delete now;
    }

    void pop_back()
    {
        erase(--end());
    }

    void insert_tail(T inp)
    {
        if(head == NULL)
        {
            head = new Node(inp);
            head->next = tail;
            head->pre = NULL;
            tail->pre = head;
            l_size++;
        }
        else
        {
            Node *ptr = tail->pre;
            Node *new_node = new Node(inp);
            ptr->next = new_node;
            new_node->pre = ptr;
            new_node->next = tail;
            tail->pre = new_node;
            l_size++;
        }
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(tail);
    }

    T front()
    {
        return head->Node_data;
    }
    T back()
    {
        return tail->pre->Node_data;
    }
    bool empty()
    {
        return l_size == 0;
    }
    int size()
    {
        return l_size;
    }
};


template<typename T>
class AVL_Tree
{
    private:
    struct Node
    {
        T data;
        int height;
        Node* leftnode, *rightnode, *parent;

        Node()
        {
            data = 0;
            height = 0;
            leftnode = NULL;
            rightnode = NULL;
        }

        Node(int inp, Node* l,Node* r)
        {
            data = inp;
            leftnode = l;
            rightnode = r;
        }

        Node(int inp)
        {
            data = inp;
            height = 0;
            leftnode = NULL;
            rightnode = NULL;
        }
    };

    
    

    int max(int a,int b) 
    {
        return (a>b)?a:b;
    }

    int Node_Height(Node *treenode)
    {
        if(treenode != NULL)
            return treenode->height;
        else
            return 0;
    }

    Node* LL_rotation(Node* given_node)
    {
        Node* leftkid = given_node->leftnode;

        given_node->leftnode = leftkid->rightnode;
        leftkid->rightnode = given_node;
        leftkid->parent = given_node->parent;
        given_node->parent = leftkid;

        given_node->height = max(Node_Height(given_node->leftnode),Node_Height(given_node->rightnode)) + 1;
        leftkid->height = max(Node_Height(leftkid->leftnode),Node_Height(leftkid->rightnode)) + 1;
        return leftkid;
    }

    Node* RR_rotation(Node* given_node)
    {
        Node* rightkid = given_node->rightnode;

        given_node->rightnode = rightkid->leftnode;
        rightkid->leftnode = given_node;
        rightkid->parent = given_node->parent;
        given_node->parent = rightkid;

        given_node->height = max(Node_Height(given_node->leftnode),Node_Height(given_node->rightnode)) + 1;
        rightkid->height = max(Node_Height(rightkid->leftnode),Node_Height(rightkid->rightnode)) + 1;
        return rightkid;
    }

    Node* LR_rotation(Node* given_node)
    {
        given_node->leftnode = (given_node->leftnode);
        given_node = LL_rotation(given_node);
        return given_node;
    }

    Node* RL_rotation(Node* given_node)
    {
        given_node->rightnode = LL_rotation(given_node->rightnode);
        return RR_rotation(given_node);
    }

    Node* hidden_add(Node* &g_node, int data)
    {
        if(g_node == NULL)
        {
            g_node =  new Node(data);
        }
        else if(data < g_node->data)
            g_node->leftnode = hidden_add(g_node->leftnode,data);
        else if(data > g_node->data)
            g_node->rightnode = hidden_add(g_node->rightnode,data);

        if(Node_Height(g_node->leftnode) - Node_Height(g_node->rightnode) >= 2)
        {
            if(data < g_node->leftnode->data)
                g_node = LL_rotation(g_node);
            else
                g_node = LR_rotation(g_node);
        }
        else if(Node_Height(g_node->leftnode) - Node_Height(g_node->rightnode) <= -2)
        {
            if(data > g_node->rightnode->data)
                g_node = RR_rotation(g_node);
            else
                g_node = RL_rotation(g_node);   
        }
        
        g_node->height = max(Node_Height(g_node->leftnode),Node_Height(g_node->rightnode)) + 1;

        return g_node;
    }

    Node* hidden_remove_data(Node* &g_node, int data)
    {
        if(g_node == NULL)
            return NULL;
        if(data < g_node->data)
        {
            g_node->leftnode = hidden_remove_data(g_node->leftnode,data);
            if(Node_Height(g_node->leftnode) - Node_Height(g_node->rightnode) <= -2)
            {
                if(data > g_node->rightnode->data)
                    g_node = RR_rotation(g_node);
                else
                    g_node = RL_rotation(g_node);   
            }
        }
        else if(data > g_node->data)
        {
            g_node->rightnode = hidden_remove_data(g_node->rightnode,data);
            if(Node_Height(g_node->leftnode) - Node_Height(g_node->rightnode) >= 2)
            {
                if(data < g_node->leftnode->data)
                    g_node = LL_rotation(g_node);
                else
                    g_node = LR_rotation(g_node);
            }
        }
        else
        {
            if((g_node->leftnode!=NULL) && (g_node->rightnode!=NULL))
            {
                if(Node_Height(g_node->leftnode) > Node_Height(g_node->rightnode))
                {
                    auto maxone = maxnode(g_node->leftnode);
                    g_node->data = maxone->data;
                    g_node->leftnode = hidden_remove_data(g_node->leftnode,maxone->data); 
                }
                else
                {
                    auto min = minnode(g_node->rightnode);
                    g_node->data = min->data;
                    g_node->rightnode = hidden_remove_data(g_node->rightnode,min->data);
                }              
            }
            else
            {
                auto temp = g_node;
                if(g_node->leftnode == NULL)
                {
                    g_node = g_node->rightnode;
                }
                else
                {
                    g_node = g_node->leftnode;
                }
                delete temp;
            }
        }
        return g_node;
    }

    public:
    Node *rootnode;

    AVL_Tree()
    {
        rootnode = NULL;
    }

    int get_height()
    {
        return rootnode->height;
    }

    void add(int data)
    {
        hidden_add(rootnode,data);
    }

    void remove(int data)
    {
        hidden_remove_data(rootnode,data);
    }
    Node* maxnode(Node* inp)
    {
        while(inp->rightnode)
            inp = inp->rightnode;

        return inp;
    }

    Node* minnode(Node* inp)
    {
        while(inp->leftnode)
            inp = inp->leftnode;

        return inp;
    }

    void inorder(Node* inp)
    {
        if(inp!=NULL)
        {
            inorder(inp->leftnode);
            std::cout<<inp->data<<' ';
            inorder(inp->rightnode);
        }
    }

    void preorder(Node* inp)
    {
        if(inp != NULL)
        {
            std::cout<<inp->data<<' ';
            preorder(inp->leftnode);
            preorder(inp->rightnode);
        }
    }

    void postorder(Node *inp)
    {
        if(inp != NULL)
        {
            postorder(inp->leftnode);
            postorder(inp->rightnode);
            std::cout<<inp->data<<' ';
        }
    }
};


template<typename T>
class Binary_Tree
{
    private:
    struct Node
    {
        T data;
        int height;
        Node* leftnode, *rightnode, *parent;

        Node()
        {
            data = 0;
            height = 0;
            leftnode = NULL;
            rightnode = NULL;
        }

        Node(int inp, Node* l,Node* r)
        {
            data = inp;
            leftnode = l;
            rightnode = r;
        }

        Node(int inp)
        {
            data = inp;
            height = 0;
            leftnode = NULL;
            rightnode = NULL;
        }
    };

    public:
    Node* rootnode;
    int max_node;

    Binary_Tree()
    {
        rootnode = NULL;
    }

    void create_full_tree(Node* &inp,T start,T maximum)
    {
        if(start > maximum)
        {
            max_node = maximum;
            return;
        }

        
        if(inp == NULL)
        {
            inp = new Node(start);
        }

        create_full_tree(inp->leftnode,2*start + 1,maximum);
        create_full_tree(inp->rightnode,2*start + 2,maximum);
    }

    void inorder(Node* inp)
    {
        if(inp!=NULL)
        {
            inorder(inp->leftnode);
            std::cout<<inp->data<<' ';
            inorder(inp->rightnode);
        }
    }

    void preorder(Node* inp)
    {
        if(inp != NULL)
        {
            std::cout<<inp->data<<' ';
            preorder(inp->leftnode);
            preorder(inp->rightnode);
        }
    }

    void postorder(Node *inp)
    {
        if(inp != NULL)
        {
            postorder(inp->leftnode);
            postorder(inp->rightnode);
            std::cout<<inp->data<<' ';
        }
    }

    void levelorder(Node* node)
    {
        myqueue<Node*> que;
        que.push(node);

        while(que.size())
        {
            if(que.front()->leftnode != NULL)
            {
                que.push(que.front()->leftnode);
            }
            if(que.front()->rightnode != NULL)
            {
                que.push(que.front()->rightnode);
            }
            std::cout<<que.front()->data<<' ';
            que.pop();
        }
    }

};
