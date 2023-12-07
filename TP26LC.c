#include <stdio.h>
#include <stdlib.h> 

/* 
Elements in list are sorted in a non-decreasing order. Need to remove the duplicates but without creating a new list. I guess I could create a second array to hold the elements that I already have seen? Or perhaps just comparing to the start of the same array would do the same thing. 

Would that work? I suppose I could just sort the unique ones to the front and then go from there? 

I suppose I could just create a pointer that points to the previous element each time. 

One pointer would keep track of the current element in the original array, and the other would be for the unique elements. But what does that mean, to have a pointer just for the unique elements? Would I move unique elements to the front of the array? Maybe to the previous position of the unique pointer. And then I could move the non-unique ones?

Why would bypassing all of the duplicates help me with anything? How tf does modifying in place work with this? 

I guess I could start by setting "unique element" pointer to the zeroeth index and "current element" pointer to zeroeth. 
Then loop through nums (starting at the first index, not zeroeth?). If "current element" points to the same value as "unique element", then I skip it. Otherwise, move the value pointed at by current element to the start somehow? 
*/ 

int removeDuplicates(int* nums, int numsSize) {
    int *current_el = nums; 
    int *unique_el = nums;
    for (int i=1; i < numsSize ; i++)

        // DEBUG printing nums array 
        printf("At start of for loop, nums = ");
		for (int d=0 ; d < numsSize; d++)
		{
			printf("%d ", nums[d]);
		}
		printf("\n"); 
		printf("current_el = %p, *current_el = %d\n", current_el, *current_el); 
		printf("unique_el = %p, *unique_el = %d\n", unique_el, *unique_el);
		printf("\n");

        if (unique_el != current_el)
        {
            // Store the element that we want to move to the front area of the array
            int tmp = *current_el; 
            // Now I need to shift every element between unique_el and current_el 
            for (int j=0 ; j < (current_el - (unique_el+2)) ; j++)
            {
                // DEBUG printing nums array 
                printf("At start of the shift loop for j=%d, nums = ", j);
                for (int d=0 ; d < numsSize; d++)
                {
                    printf("%d ", nums[d]);
                }
                printf("\n"); 
                printf("\n");

                *(current_el-j) = *(current_el-(j+1)); 
            }
            // Move the pointer ot the location of the current furthest-right unique
            //   element one to the right.
            unique_el++;
            // 
            *(unique_el+1) = tmp;
        }
        // Iterates one more element through array 
        current_el++; 
    return 0; // DB
}

int main() 
{
	int nums[] = {1, 2, 2};
	removeDuplicates(nums, 3);
} 

