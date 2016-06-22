#include<stdio.h>

/**
 * Test I made at codility
 * Returns the greatest number of '0' between '1'
 * in the binary representation of a number given by N.
 */

int main(void){
	int N = 1041;
	int result = solution(N);
	printf("Answer to %d = %d", N, result);
}

int solution(int N) {

    int biggest_gap = 0;
    int count_gap = 0;
    int found = 0;
    int x;

	//Loop through the numbers binary representation.
    for (x = 0; x < sizeof(int) * 8; ++x)
    {

		//No '1' found yet.
        if (!found && ((N & (1 << x)) == 0))
        {
            continue;
        }

        //Increase count_gap if a '0' is found after a '1' has been found.
        if (found && ((N & (1 << x)) == 0))
        {
            ++count_gap;
            continue;
        }

        //End count, update biggest?
        if (found && count_gap != 0 && ((N & (1 << x)) != 0))
        {
            //found = 0; man kan ha 100101.
            if (biggest_gap < count_gap)
            {
                biggest_gap = count_gap;
            }
            count_gap = 0;
            continue;
        }

		// If consecutive '1' are found.
        if (count_gap == 0 && ((N & (1 << x)) != 0))
        {
            found = 1;
            continue;
        }
    }
    return biggest_gap;
}


