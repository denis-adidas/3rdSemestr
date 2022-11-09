#include "iostream"
#include "vector"
#include "set"

using namespace std;

//Вторая задача


void v_out(set<multiset<int>>& a) {
    for (auto i : a) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;

    }
}

multiset<int> nums;
void foo(int n, set<multiset<int>>& arr, int tmp) {
    if (tmp == n) {
        arr.insert(nums);
//        v_out(arr);
        return;
    } else if (tmp > n) {
        return;
    }
    for (int i = 2; i < n; i++) {
        nums.insert(i);
        foo(n, arr, tmp * i);
        nums.erase(nums.find(i));
    }
}


int lucky_ticket(int sum, int n) {
    if (sum == 0 && n == 0) return 1;
    if (n == 0) return 0;
    for (int i = 0; i < n/2; i++) {
        
    }
    
    return 0;
}


//int main() {
//    
//    set<multiset<int>> a;
//    foo(18, a, 1);
//    v_out(a);
//
//    return 0;
//}
