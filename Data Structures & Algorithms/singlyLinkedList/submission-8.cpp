class ListNode {
    public:
        int val;
        ListNode* next;

        // constructor that is given just a val
        ListNode(int val) : val(val), next(nullptr) {}

        // constructor given val and next
        ListNode(int val, ListNode* next) : val(val), next(next) {}

};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
public:

    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* node = head->next;
        int i = 0;
        while(node != nullptr) {
            if(i == index) {
                return node->val;
            }
            i++;
            node = node->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        if(node->next == nullptr) {
            tail = node;
        }
    }
    
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
        ListNode* node = head;
        int i = 0;
        while(i < index && node != nullptr) {
            i++;
            node = node->next;
        }

        if(node != nullptr && node->next != nullptr) {
            if(node->next == tail){
                tail = node;
            }
            ListNode* toDel = node->next;
            node->next = node->next->next;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> total;
        ListNode* node = head->next;
        while(node != nullptr) {
            total.push_back(node->val);
            node = node->next;
        }
        return total;
    }
};
