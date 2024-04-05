
'''

Hey visitor ! This is the code of mine that provide solution to one of the problem of codechef : 
Follow the link to the question :  https://www.codechef.com/AUG23D/problems/SPCHEF

concept is explained at the bottom.

'''


t = int(input("\nEnter the no of test cases : "))

for i in range(t):
    for i in range(45):
        print('-',end = '')
    N = int(input("\nEnter the no of temples : "))
    M = int(input("Enter the multiplication factor of river : "))
    K = int(input("Enter the modulus : "))

    x_coeff = 1
    a_coeff = 0

    for i in range(N):
        x_coeff *= M
        a_coeff *= M
        a_coeff += 1
    
    offer = x_coeff % K
    pluck = a_coeff % K

    print("\nMinimum numbers of flower to pluck : ",pluck)
    print("No of flowers to offer : ",offer)

'''

----- CONCEPT ----- 

1. Lets us use second test case for understanding logic, similarly one can connect this to other test cases.
2. So, the input passed is 3 2 8 . that means chef will go to 3 temples, river had multiplication factor 2 and modulus is 8.
3. So, 3 times below tasks will be repeated.
4. i) firstly, let say chef has plucked 'x' flowers. then, with first river it will become 2x. and he will offer let say 'a' no 
        of flowers. then, equation becomes 2x-a.
   ii) When he will reach second river flower will become 2(2x-a) and after offering 'a' no of flower to temple two it will 
        become 2(2x-a)-a . that is 4x-3a.
   iii) similarly after the third river, he will have 2(4x-3a) flower and after offering 'a' no of flower, it will become 8x-7a but 
        he was supposed not to have any flower. so, the final equation is 8x-7a = 0.
5. So, our equation 8x = 7a will be balanced. when, x = 7 and a = 8. 
6. Now, since we have to print modulus. so, 8 % 8 = 0 is the no of offering. and 7 % 8 = 7 is the no of initial flower plucked.
7. In the code, we have used unsigned long long int because for last test case value will go beyond of smaller data type.
8. That's it.


'''