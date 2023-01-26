#include <stdio.h>
#include <stdlib.h>

//enum for different types of operation
typedef enum TypeTag {
    ADD, //Addition operation
    SUB, //Subtraction operation
    MUL, //Multiplication operation
    DIV, //Division operation
    FIB, //Fibonacci operation
    NUM  //Numeric value
} TypeTag;

//Node structure
typedef struct Node {
    TypeTag type; //Type of operation
    union {
        struct {
            struct Node *left; //left Node
            struct Node *right; //right Node
        };
        int value; //Numeric value
    };
} Node;

//Function to create Node
Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    return node;
}

//Fibonacci function using dynamic programming
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0, cur = 1;
    for (int i = 2; i <= n; i++) {
        int temp = cur;
        cur += prev;
        prev = temp;
    }
    return cur;
}

//Calculation function
int calc(Node* node) {
    if (node->type == NUM) {
        return node->value; //If the node is a numeric value, return the value
    }
    if (node->type == FIB) {
        return fibonacci(calc(node->left)); //If the node is a fibonacci operation, call the fibonacci function
    }
    int left = calc(node->left);
    int right = calc(node->right);
    switch (node->type) {
        case ADD:
            return left + right; //Addition operation
        case SUB:
            return left - right; //Subtraction operation
        case MUL:
            return left * right; //Multiplication operation
        case DIV:
            return left / right; //Division operation
    }
}

int main() {
    //Addition operation
    Node *add = makeFunc(ADD);
    add->left = makeFunc(NUM);
    add->left->value = 10;
    add->right = makeFunc(NUM);
    add->right->value = 6;

    //Multiplication operation
    Node *mul = makeFunc(MUL);
    mul->left = makeFunc(NUM);
    mul->left->value = 5;
    mul->right = makeFunc(NUM);
    mul->right->value = 4;

    //Subtraction operation
    Node *sub = makeFunc(SUB);
    sub->left = mul;
    sub->right = add;

    //Fibonacci operation
    Node *fibo = makeFunc(FIB);
    fibo->left = sub;

    //Print the result of each operation
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
	printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    return 0;
}
