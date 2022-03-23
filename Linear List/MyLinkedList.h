// g++ MyLinkedList.h -o MyLinkedList

class MyLinkedList {
public:
    typedef struct LinkedNode {
        int val;
        struct LinkedNode *next;
        LinkedNode(int val): val(val), next(nullptr){ }
    } LinkedNode;

    MyLinkedList() {
        dummyHead = new LinkedNode(0);
        len = 0;
    }
    
    int get(int index) {
        if (index > (len - 1) || index < 0)
            return -1;
        LinkedNode *cur = dummyHead->next;
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode *cur = new LinkedNode(val);
        cur->next = dummyHead->next;
        dummyHead->next = cur;
        len++;
    }
    
    void addAtTail(int val) {
        LinkedNode *TailNode = new LinkedNode(val);
        LinkedNode *temp = dummyHead;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = TailNode;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > len)
            return ;
        LinkedNode *InsertNode = new LinkedNode(val);
        LinkedNode *cur = dummyHead;
        while (index--) {
            cur = cur->next; 
        }
        InsertNode->next = cur->next;
        cur->next = InsertNode;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= len || index < 0) {
            return;
        }
        LinkedNode *cur = dummyHead;
        while(index--) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        len--;
    }
private:
    int len;
    LinkedNode* dummyHead;

};