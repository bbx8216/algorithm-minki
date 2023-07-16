#include <stdio.h>
#include <string.h>

char stack[50000];
int stack_size=0;

void push(int push_data){
    stack[stack_size] = push_data;
    stack_size += 1;
}

int empty(){
    if(stack_size == 0){
        return 1;
    }
    return 0;
}

char pop(){
    if(empty()){
        return -1;
    }
    stack_size -= 1;
    return stack[stack_size];
}

char top(){
    if(empty()){
        return -1;
    }
    return stack[stack_size-1];
}

int main(){
    char str[100000];
    gets(str);
    int ret = 0;
    for (int i = 0 ; i < strlen(str); i++){
        if (str[i] == '('){
            push('(');
        }
        else if (str[i] == ')' && str[i-1] == '('){
            pop();
            ret += stack_size;
        }
        else if (str[i]==')'&& str[i-1] ==')'){
            pop();
            ret += 1;
        }
        else
            break;
    }
    printf("%d", ret);
    return 0;
}