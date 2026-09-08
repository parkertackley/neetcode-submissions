class ListNode {
    public:
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}

    ListNode(int val, ListNode* next): val(val), next(next) {}

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
        ListNode* curr = head->next;
        int i = 0;
        while(curr != nullptr) {
            if(i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        if(node->next == nullptr)
            tail = node;
    }
    
    void insertTail(int val) {
        ListNode* node = new ListNode(val);
        tail->next = node;
        tail = tail->next;
    }

    bool remove(int index) {
        ListNode* curr = head;
        int i = 0;
        while(i < index && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        if(curr != nullptr && curr->next != nullptr) {
            if(curr->next == tail) {
                tail = curr;
            }
            curr->next = curr->next->next;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        ListNode* curr = head->next;

        while(curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
