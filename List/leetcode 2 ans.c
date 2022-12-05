/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
     //初始化结果链表
    int carry = 0;//进位数，额外摘出来，可以让表达式不会臃肿
    while(l1 || l2){
        int n1 = l1 ? l1 -> val : 0;
        int n2 = l2 ? l2 -> val : 0;
        //读取两个链表中的数据，如果链表不为空，则继续读取，如果链表为空，就说明到尽头了。使用0来补位
        int sum = n1 + n2 + carry;
        if(!head){
            head = tail = malloc(sizeof(struct ListNode));
            tail -> val = sum % 10;
            tail -> next = NULL;
            //如果结果链表的头节点是空的，就先新建链表,填写好每个节点的信息（数据加上指针
        }
        else{
            tail -> next = malloc(sizeof(struct ListNode));
            tail -> next -> val = sum % 10;
            tail = tail -> next;
            tail -> next = NULL;
            //如果链表已经建立好，就是简单的尾插法，注意最后封装的封闭性，让尾巴指向null
        }
        carry = sum / 10;
        //计算carry，这就是新变量来记录进位的好处，单独计算
        if(l1){
            l1 = l1 -> next;
        }
        if(l2){
            l2 = l2 -> next;
        }
        //让l1和l2两个链表跑起来，就是完成了结果链表之后再移动条件链表
        if(carry > 0){
            tail -> next = malloc(sizeof(struct ListNode));
            tail -> next -> val = carry;
            tail -> next -> next = NULL;
        }
        //最后的收尾工作，防止最后一位相加万一有进位没有被记录下来（
    }
    return head;
}
