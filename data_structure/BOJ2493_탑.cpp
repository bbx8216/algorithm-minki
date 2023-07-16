#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int input_idx;
    struct Node *next;
};

struct Node *top = NULL;

void push(int push_data, int in_idx){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = push_data;
    newNode->input_idx = in_idx;
    if (top == NULL){
        newNode->next = NULL;
    }
    else{
        newNode->next = top;
    }
    top = newNode;

}
//pop 하면 data idx 뽑아준다
int pop(){
    if(top == NULL){
        return -1;
    }
    struct Node *temp = top;
    int ret_data = top->input_idx;
    top = top->next;
    free(temp);
    return ret_data;
}

int main()
{
    int N, temp, *ret;
    scanf("%d", &N);
    ret = malloc(sizeof(int)*N);
    scanf("%d", &temp);
    push(-1,0);
    push(temp, 1);
    ret[1] = 0;
    for (int idx = 2 ; idx <= N ; idx++) {
        scanf("%d", &temp);
        //printf("---%d---\n", idx);
        if (temp < top->data) {
            //printf("enter if\n");
            ret[idx] = top->input_idx;
            push(temp, idx);
            //printf("%d\n", ret[idx]);
        }
        else {
            //printf("enter else\n");

            while (top->data < temp && top->data != -1) {
                pop();
            }
            ret[idx] = top->input_idx;
            push(temp, idx);
            //printf("%d\n", ret[idx]);

        }
    }

    for(int i = 1 ; i <= N ; i++)
    {
        printf("%d ", ret[i]);
    }
    return 0;
}