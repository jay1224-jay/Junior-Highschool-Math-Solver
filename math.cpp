#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a < b) ? (b) : (a) )


/*
 * 54 32
 *   2   45
 *     1
 *
 *
 */



int GCD(vector<int> nums, int length) {

    /*
    char c;
    cin >> c;
    for ( int i : nums )
        cout << i << " ";
    cout << length;
    cout << endl;
    */

    if ( length == 2 ) {
        int min = MIN(nums[0], nums[1]), max = MAX(nums[0], nums[1]);
        if ( (max % min) == 0)
            return min;
        vector<int> need = {max % min, min};
        return GCD(need, 2);
    }



    int n1 = *nums.begin(), n2 = *( nums.begin() + 1);

    vector<int> temp = {n1, n2};



    nums.push_back( GCD(temp, 2) );

    nums.erase(nums.begin(), nums.begin()+2);


    return GCD(nums, length-1);

}
