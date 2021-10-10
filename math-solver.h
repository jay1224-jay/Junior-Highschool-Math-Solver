#define MAX(a, b) ((a<b) ? (b) : (a))
#define MIN(c, d) ((c>d) ? (d) : (c))


// ax + by = c
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

int GCD(std::array<int, 50> nums, int length=2)
{

    if (length==2){
        std::array<int, 50> need;
        int max=MAX(nums[0], nums[1]), min=MIN(nums[0], nums[1]);
        if (!( min  ))
            return max;
        need[0] = min;
        need[1] = max%min;
        return GCD(need, 2);
    }
    std::array<int, 50> array_remove_end;
    int i;
    for (i=0;i<length-1;i++){
        array_remove_end[i] = nums[i];
    }
    
    
    std::array<int, 50> next;
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


//  ax+by=c
//  ax+by=c

std::array<std::string, 2> 
simultaneous_equations( EQUATION equation1, EQUATION equation2 )
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

    int a_lcm = abs(equation1.a*equation2.a) / GCD({abs(equation1.a), abs(equation2.a)});
    int b_lcm = abs(equation1.b*equation2.b) / GCD({abs(equation1.b), abs(equation2.b)});

    std::string x, y;
    int x_fraction_son, x_fraction_mother, 
        y_fraction_son, y_fraction_mother;

    /*
    1/2
       1 is fraction son and 2 id fraction mother
    */

    y_fraction_son = 
    ((equation1.c * a_lcm)/equation1.a - (equation2.c * a_lcm)/equation2.a);

    y_fraction_mother = 
    ((equation1.b * a_lcm)/equation1.a - (equation2.b * a_lcm)/equation2.a);

    x_fraction_son = 
    ((equation1.c * b_lcm)/equation1.b - (equation2.c * b_lcm)/equation2.b);

    x_fraction_mother = 
    ((equation1.a * b_lcm)/equation1.b - (equation2.a * b_lcm)/equation2.b);

    //std::cout << y_fraction_son << " " << y_fraction_mother << " " << x_fraction_son << " " << x_fraction_mother;

    if ( (x_fraction_mother < 0 && x_fraction_son < 0) || (x_fraction_mother > 0 && x_fraction_son > 0)) {
        x_fraction_son = abs(x_fraction_son);
        x_fraction_mother = abs(x_fraction_mother);
        int gcd = GCD({x_fraction_mother, x_fraction_son});

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
        int gcd = GCD({x_fraction_mother, x_fraction_son});

        if (x_fraction_mother/gcd == 1.0){
            std::cout << x_fraction_son << " " << gcd;
            x = "-" + std::to_string((int)(x_fraction_son/gcd));
        }
        else {
            x = "-" + \
                std::to_string((int)(x_fraction_son/gcd)) + \
                "/" + \
                std::to_string((int)(x_fraction_mother/gcd));
        }
    }

    if ( (y_fraction_mother < 0 && y_fraction_son < 0) || (y_fraction_mother > 0 && y_fraction_son > 0)) {
        y_fraction_son = abs(y_fraction_son);
        y_fraction_mother = abs(y_fraction_mother);
        int gcd = GCD({y_fraction_mother, y_fraction_son});

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
        int gcd = GCD({x_fraction_mother, x_fraction_son});

        if (y_fraction_mother/gcd == 1.0){
            std::cout << x_fraction_son << " " << gcd;
            y = "-" + std::to_string((int)(y_fraction_son/gcd));
        }
        else {
            y = "-" + \
                std::to_string((int)(y_fraction_son/gcd)) + \
                "/" + \
                std::to_string((int)(y_fraction_mother/gcd));
        }
    }

    return {x, y};
}

float heronFormula(float sideA, float sideB, float sideC)
{
    float area,
          s = (sideA + sideB + sideC)/2; // semi-perimeter
    area = sqrt( s * (s-sideA) * (s-sideB) * (s-sideC) );
    return area;
}
