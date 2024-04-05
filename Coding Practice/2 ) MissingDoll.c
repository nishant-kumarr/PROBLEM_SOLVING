/* 

Hey visitor ! This is the code of mine that provide solution to one of the problem of codechef : 
Follow this link to the question :  https://www.codechef.com/practice/INTARR01/problems/CFRTEST

concept is explained at the bottom.

*/


#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int result = 0; // Initialize the result to 0

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);

            // XOR the current number with the result
            result ^= num;
        }

        printf("%d\n", result);
    }

    return 0;
}

/*
----- CONCEPT -----
1. Firstly we are taking no of test cases, and no of dolls.
2. Then, we will declare a variable result = 0.
3. Then, we will iterate n (no of dolls) times and take the input.
4. Everytime we take input, we XOR it with the result. 
5. Before we understand why we are doing XOR operation, understand what is xor.
    i) The XOR operation, denoted as ^ in many programming languages, stands for "exclusive or." 
        It's a bitwise operation that compares corresponding bits of two binary numbers and returns a 
        new binary number where each bit is set to 1 if exactly one of the corresponding bits of the original numbers is 1.

    ii) Here's how XOR works in more detail:
        If both bits are 0 or both bits are 1, the result is 0.
        If one bit is 0 and the other bit is 1, the result is 1.
        Let's take an example: 

        1010
      ^ 1101
      --------
        0111
    
6. Now, we have used xor since XORing a number with itself results in 0 (because both bits are the same), when you XOR all the 
    numbers in the array, only the unpaired number will remain in result. This is because the paired numbers will effectively
    cancel each other out in terms of their bits, leaving only the unpaired number behind.

7. For example : if the passed array is : [2, 4, 2, 4, 5]
8. then, XORing will be like : result = 0 ^ 2 ^ 4 ^ 2 ^ 4 ^ 5
9. Result : 0 ^ 0 ^ 0 ^ 5
10. Hence, leaving the unpaired number behind. Here '5'.
11. That's it.

*/