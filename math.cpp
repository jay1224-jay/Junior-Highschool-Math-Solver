#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a < b) ? (b) : (a))

struct EQUATION {
    float a;
    float b;
    float c;

    void times_num(int num){
        a *= num;
        b *= num;
        c *= num;
    }

    void all_arg(void){
        std::cout << a << " " << b << " " << c << std::endl;
    }
};

/*
 * 54 32
 *   2   45
 *     1
 *
 *
 */

vector<string> simultaneous_equations( EQUATION equation1, EQUATION equation2 );



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


float heron_area_calc(float a, float b, float c) {

    float s = (a+b+c) / 2;

    return sqrt( s * ( s - a ) * ( s - b ) * ( s - c) ); //area

}


vector<string> se_ans( float a1, float a2, float b1, float b2, float c1, float c2 )
{
    vector<float> ans(2, 0);
    vector<string> ans_str;

    EQUATION eq1;
    EQUATION eq2;

    eq1.a = a1;
    eq1.b = b1;
    eq1.c = c1;

    eq2.a = a2;
    eq2.b = b2;
    eq2.c = c2;
    /*

    float x = eq1.c*eq2.b - eq1.b*eq2.c,
          y = eq1.a*eq2.c - eq1.c*eq2.a,
          base;
    
    base = eq1.a*eq2.b - eq2.a*eq1.b;
    

    x = x/base;
    y = y/base;

    ans[0] = x;
    ans[1] = y;
    */

    ans_str = simultaneous_equations(eq1, eq2);

    return ans_str;


}


float DET(vector<vector<float>> det, int length, float value=0.0, int curr_row=0)
{

    if ((curr_row + 1) == length)
        return value;
    return DET(
            det, 
            length,
            value+(det[curr_row][0]*det[curr_row+1][1]) - (det[curr_row+1][0]*det[curr_row][1]),
            curr_row+1
    );
}

vector<string> simultaneous_equations( EQUATION equation1, EQUATION equation2 )
{
    /*
    float x = equation1.c*equation2.b - equation1.b*equation2.c,
          y = equation1.a*equation2.c - equation1.c*equation2.a,
          base;
    
    base = equation1.a*equation2.b - equation2.a*equation1.b;
    

    x = x/base;
    y = y/base;
    */

    //equation1.times_num(10);
    //equation2.times_num(10);
    //
    //
    std::string x, y;


    int a_lcm = abs(equation1.a*equation2.a) / GCD({abs(equation1.a), abs(equation2.a)}, 2);
    int b_lcm = abs(equation1.b*equation2.b) / GCD({abs(equation1.b), abs(equation2.b)}, 2);

    int x_fraction_son, x_fraction_mother, 
        y_fraction_son, y_fraction_mother;

    /*
    1/2
       1 is fraction son and 2 id fraction mother
    */

    y_fraction_son = (equation1.c * (a_lcm/equation1.a) - equation2.c * (a_lcm/equation2.a));

    y_fraction_mother = (equation1.b * (a_lcm/equation1.a) - equation2.b * (a_lcm/equation2.a));

    x_fraction_son = (equation1.c * (b_lcm/equation1.b) - equation2.c * (b_lcm/equation2.b));

    x_fraction_mother = (equation1.a * (b_lcm/equation1.b) - equation2.a * (b_lcm/equation2.b));

    //std::cout << y_fraction_son << " " << y_fraction_mother << " " << x_fraction_son << " " << x_fraction_mother;

    if ( x_fraction_son != 0 ) {
        if ( (x_fraction_mother <= 0 && x_fraction_son <= 0) || (x_fraction_mother >= 0 && x_fraction_son >= 0)) {
            

            x_fraction_son = abs(x_fraction_son);
            x_fraction_mother = abs(x_fraction_mother);
            int gcd = GCD({x_fraction_mother, x_fraction_son}, 2);

            if (x_fraction_mother/gcd == 1.0){
                x = std::to_string((int)(x_fraction_son/gcd));
            }
            else {
                x = std::to_string((int)(x_fraction_son/gcd)) + \
                    "/" + \
                    std::to_string((int)(x_fraction_mother/gcd));
            }
            
        } else {
            x_fraction_son = abs(x_fraction_son);
            x_fraction_mother = abs(x_fraction_mother);
            int gcd = GCD({x_fraction_mother, x_fraction_son}, 2);

            if (x_fraction_mother/gcd == 1.0){
                x = "-" + std::to_string((int)(x_fraction_son/gcd));
            }
            else {
                x = "-" + \
                    std::to_string((int)(x_fraction_son/gcd)) + \
                    "/" + \
                    std::to_string((int)(x_fraction_mother/gcd));
            }
        }
    } else 
        x="0";


    if ( y_fraction_son != 0 ) {
        if ( (y_fraction_mother < 0 && y_fraction_son < 0) || (y_fraction_mother > 0 && y_fraction_son > 0)) {

            y_fraction_son = abs(y_fraction_son);
            y_fraction_mother = abs(y_fraction_mother);
            int gcd = GCD({y_fraction_mother, y_fraction_son}, 2);

            if (y_fraction_mother/gcd == 1.0){
                y = std::to_string((int)(y_fraction_son/gcd));
            }
            else {
                y = std::to_string((int)(y_fraction_son/gcd)) + \
                    "/" + \
                    std::to_string((int)(y_fraction_mother/gcd));
            }
            
        } else {
            y_fraction_son = abs(y_fraction_son);
            y_fraction_mother = abs(y_fraction_mother);
            int gcd = GCD({x_fraction_mother, x_fraction_son}, 2);

            if (y_fraction_mother/gcd == 1.0){
                y = "-" + std::to_string((int)(y_fraction_son/gcd));
            }
            else {
                y = "-" + \
                    std::to_string((int)(y_fraction_son/gcd)) + \
                    "/" + \
                    std::to_string((int)(y_fraction_mother/gcd));
            }
        }
    } else
        y="0";

    return {x, y};
}

