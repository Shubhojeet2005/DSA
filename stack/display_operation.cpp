#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    int *s;
};


void create(struct stack &st) {
    cout<<"enter size";
    cin >> st.size;
    st.top = -1;
    st.s = new int[st.size];
    
}

void display(struct stack st) {
    int i;
    for(i = st.top; i >= 0; i--) {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

void push(struct stack *st,int x) {
    if(st->top==st->size-1) 
    cout<<"stack overload";

    else{
        st->top++;
        st->s[st->top]=x;
    }
}


int pop(struct stack *st) {
    int x=-1;
    if(st->top==-1){
        cout<<"stack underflow";

    } else{
         x= st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack *st,int pos) {
    int x=-1;
    if(st->top-pos+1<0) {
        cout<<"invalid postion";
    } else{
        x=st->s[st->top-pos+1];
    }
  
    return x;
}
int main() {
    struct stack st;
    create(st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
        push(&st,40);
            push(&st,50);
        pop(&st);
        cout<<endl;
       cout<< peek(&st,2);
        cout<<endl;

    display(st);




    return 0;
}