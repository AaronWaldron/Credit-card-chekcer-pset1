#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //firstly get number
    long input = get_long("credit card number: ");

    //count number
    int i = 0;
    long n = input;
    do{
        n = n /10;
        i++;
    } while(n > 0);
    //printf("%i\n", i);
    //invalidate unwanted counts
    if (i != 15 && i != 13 && i !=16)
    {
        printf("INVALID\n");
        return 0;
    }
    //loop through use given algorithim
    long x = input;
    int sum = 0;
    //so i want to mod x by 10 and += this value to some var then i want to take this temp value from x then div 10 then do the same mode operator this time timing it by two and again storing somewhere i think thats it
    do
    {
        int temp1 = x % 10;
        x = x - temp1;
        x = x/10;
        sum = sum + temp1;


        int temp2 = x % 10;
        x = x - temp2;
        x = x /10;
        temp2 = temp2*2;
        int mod1 = temp2 % 10;
        temp2 = temp2 /10;
        int mod2 = temp2 % 10;
        sum = sum + mod1;
        sum = sum + mod2;
// sorry to my future self this code is so messy and I don't care to improve it also my comments are bad. THis is bad code
    }while(x > 0);
    printf("");
    //use same loop through 2 for amex or other type but first invalidate mean cards
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    long last = input;
    do
    {
        last = last /10;
    } while(last > 100);
    
    if(last / 10 == 5 && 0 < last % 10 && last % 10 < 6)
    {
        printf("MASTERCARD\n");
    } else if ((last / 10 == 3) && (last % 10 == 3 || last % 10 == 7))
    {
        printf("AMEX\n");
    } else if (last/10 ==4)
    {
        printf("VISA\n");
    } else
    {
        printf("INVALID\n");
    } 

}