#include <iostream>

double* geometric(double a, double ratio, std::size_t cap);
double* cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);
std::size_t shift_duplicates(int array[], std::size_t capacity);
void deallocate(double* &ptr, bool is_array, std::size_t capacity = 0);

double* geometric(double a, double ratio, std::size_t cap){
    double* arr(new(std::nothrow) double[cap]{});

    if (arr == nullptr){
        return nullptr;
    }

    if (cap == 0) {
        return arr;
    }

    if (a == 0){
        return arr;
    }

    if (ratio == 0) {
        arr[0] = a;
        return arr;
    }

    int newlen{};
    double r{1};
    for(int i{}; i < (cap) ; ++i){
        arr[newlen++] = a*r;
        r = ratio*r;
    }

    return arr;
}

void doubleprintarray(double arr[], int len){
    if (!arr){
        std::cout << "nullptr" << std::endl;
        return;
    }

    if (len < 0){
        std::cout << "wrong input for len" << std::endl;
    }

    for (int i{}; i < len; ++i){
        std::cout << "arr [" << i << "] = " << arr[i] << std::endl;
    }
}

void intprintarray(int arr[], int len){
    if (!arr){
        std::cout << "nullptr" << std::endl;
    }

    if (len < 0){
        std::cout << "wrong input for len" << std::endl;
    }

    for (int i{}; i < len; ++i){
        std::cout << "arr [" << i << "] = " << arr[i] << std::endl;
    }
}



double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    if (!array0 || !array1) {
        return nullptr;
    }

    if (cap0 + cap1 < 1) {
        return nullptr;
    }

    double *arr{new(std::nothrow) double[cap0 + cap1 - 1]{}};

    if (!arr) {
        return nullptr;
    }

    if (cap0 == 0 || cap1 == 0){
        return arr;
    }

    for (int i{}; i < cap0; i++) {
        for (int j{}; j < cap1; j++) {
            arr[i+j] += array0[i] * array1[j];
 
        }
    }

    return arr;
}

// double* cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
//     if (!array0 && !array1){
//         return nullptr;
//     }

//     if ((cap0 + cap1) < 1){
//         return nullptr;
//     }

//     double* arr(new(std::nothrow) double[cap0+cap1-1]{});

//     if (arr == nullptr){
//         return nullptr;
//     }

//     if (cap0 == 0 || cap1 == 0){
//         return arr;
//     }

//     for (int k = -(int(cap1) - 1); k < int(cap0); ++k){
//         double sum{0};
//         for (int i{0}; i < cap0; ++i){
//             int j{i+k};
//             if (0 <= j && j < cap1){
//                 sum += array0[i] * array1[j];
//             }
//         }
//         arr[k+(cap1-1)] = sum;
//     }
//     return arr;

// } 



bool searcharray(int arr[], int len, int n){
    for(int i{}; i < len; ++i){
        if (arr[i] == n){
            return true;
        }
    }

    return false;
}

std::size_t shift_duplicates(int array[], std::size_t capacity){
    if(!array || capacity <= 0){
        return 0;
    }

    int uniqueIndex{0};

    for (int i{}; i < int(capacity); ++i){
        if(!searcharray(array, i, array[i])){ 
            int tmp{array[i]};
            array[i] = array[uniqueIndex]; 
            array[uniqueIndex++] = tmp;
        } 
    } 
    
    return uniqueIndex;

    // int uniquelen{};
    // int duplilen{};

    // int* uniquearr(new(std::nothrow) int[int(capacity)]);
    // int* duplicatearr(new(std::nothrow) int[int(capacity)]);

    // for (int i{}; i < int(capacity); ++i){
    //     if (!searcharray(array, i, array[i])){
    //         uniquearr[uniquelen++] = array[i];
    //     } else {
    //         duplicatearr[duplilen++] = array[i];
    //     }
    // }

    // for (int i{}; i < uniquelen; ++i){
    //     array[i] = uniquearr[i];
    // }

    // int i{};
    // for (int j{uniquelen}; j < int(capacity); ++j){
    //     array[j] = duplicatearr [i++];
    // }
    // delete[] uniquearr;
    // delete[] duplicatearr;

    // return uniquelen;

}


void deallocate(double* &ptr, bool is_array, std::size_t capacity){
    if (!ptr){
        return;
    }

    if (is_array){
        for (int i{}; i < int(capacity); ++i){
            ptr[i] = 0;
        }
        delete[] ptr;
    } else {
        *ptr = 0; 
        delete ptr;
    }
    ptr = nullptr;
}


// void testgeometric(){
//     std::size_t capacity{0};
//     double* arrtest{geometric(5,4,capacity)};
//     doubleprintarray(arrtest, capacity);
//     std::cout << *arrtest << std::endl;
// }

// void testcrosscorrelation(){
//     const std::size_t CAP0{5};
//     const std::size_t CAP1{1};
//     double arr0[CAP0]{1.03,2.1, 4.1, 7.9, 0.12};
//     // double arr1[CAP1]{6.41,7.1,8.32,4.11,3.003}; 
//     // const std::size_t CAP0{1};
//     // const std::size_t CAP1{5};
//     double arr1[CAP1]{3.0}; 
//     // double arr1[CAP1]{1.0,2.0,3.0,4.0,5.0}; 
//     double* arrtest{cross_correlation(arr0, CAP0, arr1, CAP1)};
//     doubleprintarray(arrtest, (CAP0 + CAP1 -1));
// }

// void testdeallocate(){
//     std::size_t capacity{3};
//     double* arr(new(std::nothrow) double[capacity]{3,3,4});
//     doubleprintarray(arr, capacity);
//     std::cout << arr << std::endl;
// }
//     double* d{new(std::nothrow) double{5.0}};

//     deallocate(arr, true, capacity);
//     deallocate(d, false); 
//     std::cout << arr << std::endl;
//     std::cout << d << std::endl;
//     delete d;
// }

// void testsearcharray(){
//     const int CAP{6};
//     int input[CAP]{1,2,3,3,3,4};

//     bool trueorfalse(searcharray(input, 5, 4));
//     std::cout << trueorfalse << std::endl;

// }
// void testduplicate(){
//     const int CAP{8};
//     //int input[CAP]{3,3,3,1,1,2,2,5}; 
//     //int input2[CAP]{3,3,3,3,3,3,3,3};
//     int input3[CAP]{1,2,3,4,5,6,7,8};

//     std::size_t test(shift_duplicates(input3, CAP));
//     intprintarray(input3, CAP);
//     std::cout << test << std::endl;
// }


// void test_cross_corelation() {
//     double a1[]{5.3, 4.2, 2.22, 1.45}, a2[]{2.1,3.45,4.123,6.04, 5.5};
//     int cap1{4}, cap2{5};
//     double *arr{cross_correlation(a1, cap1, a2, cap2)};
//     doubleprintarray(arr, cap1+cap2-1);

//     double a3[]{5.3, 4.2}, a4[]{2.1,3.45,4.123,6.04};
//     int cap3{2}, cap4{4};
//     double *arr2{cross_correlation(a3, cap3, a4, cap4)};
//     doubleprintarray(arr2, cap3+cap4-1);

//     double a5[]{2.1,3.45,4.123,6.04}, a6[]{5.3, 4.2};
//     int cap5{4}, cap6{2};
//     double *arr3{cross_correlation(a5, cap5, a6, cap6)};
//     doubleprintarray(arr3, cap5+cap6-1);
// }


//  int main(){ 
// //     // testgeometric();
// //     testcrosscorrelation();
// //     // testdeallocate();
// //     // testsearcharray();
// //     // testduplicate();
//       test_cross_corelation();
// }

