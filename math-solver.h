#define MAX(a, b) ((a<b) ? (b) : (a))
#define MIN(c, d) ((c>d) ? (d) : (c))

int GCD(int nums[50], int length)
{

    if (length==2){
        int need[2], max=MAX(nums[0], nums[1]), min=MIN(nums[0], nums[1]);
        if (!( min  ))
            return max;
        need[0] = min;
        need[1] = max%min;
        return GCD(need, 2);
    }
    int array_remove_end[50], i;
    for (i=0;i<length-1;i++){
        array_remove_end[i] = nums[i];
    }
    
    
    int next[2];
    next[0] = GCD(array_remove_end, i);
    next[1] = nums[i];
    
    return GCD(next, 2);

}

/*
        math         math-solver.h
det = | 1  2 |  -->  { { 1 , 2 }, { 2 , 3 } }
      | 2  3 |  -->

DET(det) = (1*3)-(2*2)

*/
float DET(float det[50][2], int length, float value=0.0, int curr_row=0)
{

    if ((curr_row + 1) == length)
        return value;
    return DET(det, length,
                    value+(det[curr_row][0]*det[curr_row+1][1]) - (det[curr_row+1][0]*det[curr_row][1]),
                    curr_row+1);
}







