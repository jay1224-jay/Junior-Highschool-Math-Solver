# Junior-Highschool-Math-Solver
#### creator [@jay1224-jay](https://github.com/jay1224-jay)
------
##### 這個可以做什麼？
- [gcd 最大公因數](#gcd-最大公因數)
- [lcm 最小公倍數](#lcm-最小公倍數)
- [area 座標求面積](#area-座標求面積)
- [se 二元一次聯立方程式求解](#se-二元一次聯立方程式求解)

##### 為什麼要做這個？
- 花更少的時間在**計算**方面

## gcd 最大公因數
我的算法是 [輾轉相除法](https://zh.wikipedia.org/wiki/%E8%BC%BE%E8%BD%89%E7%9B%B8%E9%99%A4%E6%B3%95)

code: 
```c++
#include<array.h>

#define MAX(a, b) ((a<b) ? (b) : (a))
#define MIN(c, d) ((c>d) ? (d) : (c))

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
    for (i=0;i<length-1;i++)
        array_remove_end[i] = nums[i];
    
    
    std::array<int, 50> next;
    next[0] = GCD(array_remove_end, i);
    next[1] = nums[i];
    
    return GCD(next, 2);

}

```
可以發現, 我是用遞迴來解決多個數字求解

## lcm 最小公倍數
我們知道 
$$\sum_{n=1}^{10} n^2$$


## area 座標求面積


## se 二元一次聯立方程式求解
