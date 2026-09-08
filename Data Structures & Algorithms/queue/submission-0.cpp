class Listnode {
    public:
        int val;
        Listnode* next;
        Listnode* prev;

        Listnode(int val) : val(val), next(NULL), prev(NULL) {}
};

class Deque {
public:
    Listnode* head;
    Listnode* tail;

    Deque() {
        head = new Listnode(0);
        tail = new Listnode(0);

        head->next = tail;
        tail->prev = head;

    }

    bool isEmpty() {
        return head->next == tail;
    }

    void append(int value) {
        Listnode* newnode = new Listnode(value);
        Listnode* prevnode = tail->prev;

        newnode->next = tail;
        newnode->prev = prevnode;

        prevnode->next = newnode;
        tail->prev = newnode;
    }

    void appendleft(int value) {
        Listnode* newnode = new Listnode(value);
        Listnode* nextnode = head->next;

        newnode->next = nextnode;
        nextnode->prev = newnode;

        head->next = newnode;
        newnode->prev = head;
    }

    int pop() {
        if(isEmpty())
            return -1;
        
        Listnode* rem = tail->prev;
        int value = rem->val;

        rem->prev->next = tail;
        tail->prev = rem->prev;

        return value;
    }

    int popleft() {
        if(isEmpty())
            return -1;

        Listnode* rem = head->next;
        int value = rem->val;

        head->next = rem->next;
        rem->next->prev = head;

        return value;
    }
};
