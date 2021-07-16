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