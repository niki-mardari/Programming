#include <stdio.h>

// Inptut 5
/*
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
*/

int min(int top, int bottom, int left, int right){
    int smallest = top;
    
    if (bottom <= smallest) {
        smallest = bottom;
    }
    if (left <= smallest) {
        smallest = left;
    }
    if (right <= smallest) {
        smallest = right;
    }
    
    return smallest;
}


int main() 
{
    int n, top, bottom, left, right, val, min_dist;
    scanf("%d", &n);
    int size = 2*n-1;
  	// Complete the code to print the pattern.
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            top = row;
            bottom = size - 1 - row;
            left = col;
            right = size - 1 - col;
            min_dist = min(top, bottom, left, right);
            val = n - min_dist;
            if(col == 0) printf("%d ", n);
            else {printf("%d ", val);}
        }
        printf("\n"); // Next row
    }
    return 0;
}
