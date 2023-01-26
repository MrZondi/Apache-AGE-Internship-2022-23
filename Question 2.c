
//Recursive Function
int F(int n) {
    if (n == 0) return 0; //base case for n=0
    if (n == 1) return 1; //base case for n=1
    if (n == 2) return 2; //base case for n=2
    return F(n-3) + F(n-2); //recursive call for n>2
}


//Iterative Function Using Loop
int F(int n) {
    if (n == 0) return 0; //base case for n=0
    if (n == 1) return 1; //base case for n=1
    if (n == 2) return 2; //base case for n=2
    int f0 = 0, f1 = 1, f2 = 2; //initialize variables
    for (int i = 3; i <= n; i++) { //start loop from 3
        int temp = f2; //store the current value of f2 in temp
        f2 = f1 + f0; //calculate f2 using the recurrence relation
        f0 = f1; //update f0
        f1 = temp; //update f1
    }
    return f2; //return the result
}


//Iterative Function Using Array
int F(int n) {
    if (n == 0) return 0; //base case for n=0
    if (n == 1) return 1; //base case for n=1
    if (n == 2) return 2; //base case for n=2
    int fibo[n+1]; //create an array to store the fibonacci sequence
    fibo[0] = 0; //initialize the first element
    fibo[1] = 1; //initialize the second element
    fibo[2] = 2; //initialize the third element
    for (int i = 3; i <= n; i++) { //start loop from 3
        fibo[i] = fibo[i-3] + fibo[i-2]; //calculate the next element using the recurrence relation
    }
    return fibo[n]; //return the result
}

