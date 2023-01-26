# Apache-AGE-Internship-2022-23

Question 1 

To compile the code:

gcc -o <output_file_name> <source_file_name>.c

To run the compiled code:

./<output_file_name>

This will run the code and print the results of each operation in the format specified in the question (e.g. "add : 16").
Make sure GCC is installed on your system before attempting to compile and run the code.


Question 2

In the first method, we use recursion to calculate the Fibonacci sequence. The function calls itself with the input n-3 and n-2 until it reaches the base case where the value of n is 0,1 or 2.
The second method uses a loop to iterate through the Fibonacci sequence, calculating each value using the recurrence relation and updating the variables at each step.
The third method uses an array to store the Fibonacci sequence, and at each step, it calculates the next element using the recurrence relation.

The first method is simple and easy to understand, but it has exponential time complexity and may cause a stack overflow for large inputs.
The second and third method are faster for large inputs as they have linear time complexity. 
The third method also uses less memory as it only keeps track of the current and previous values.

Question 3

To compile this, you will need to include the libpq-fe and jsoncpp library. The command for compiling the code will be like :
g++ -std=c++11 -o main main.cpp -lpq -ljsoncpp
Note: For this you need to install the dependencies like libpq-dev and jsoncpp, you can use package manager of your system to install these.
