#include <stdio.h>
#include <stdlib.h>

int stack[100000];
int stack_size=0;

void push(int push_data){
    stack[stack_size] = push_data;
    stack_size += 1;
}

int pop(){
    if(stack_size == 0){
        return -1;
    }
    stack_size -= 1;
    return stack[stack_size];
}
int top(){
    if(stack_size == 0){
        return -1;
    }
    return stack[stack_size-1];
}

int main(){
    int N,temp, value = 1, idx = 0;
    char* result;
    scanf("%d", &N);
    result = malloc(sizeof(char)*2*N);

    for (int i = 0 ; i < N ; i++){
        scanf("%d", &temp);
        while(top() < temp){
            push(value);
            result[idx++] = '+';
            value++;
        }
        while (temp == top()){
            pop();
            result[idx++] = '-';
        }
    }
    if(stack_size != 0){
        printf("NO\n");
    }
    else{
        for(int i = 0 ; i < N *2 ; i++){
            printf("%c\n", result[i]);
        }
    }
    return 0;
}