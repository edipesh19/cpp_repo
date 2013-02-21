struct node{
    int data;
    node* next
}NODE;

void reverse_list(NODE** root)
{
    NODE* cur = *root;
    Node* tmp = NULL;
    *root = NULL;

    while(cur)
    {
        tmp = cur;
        cur = cur->next;
        tmp->next = *root;
        *root = tmp;
    }
}
