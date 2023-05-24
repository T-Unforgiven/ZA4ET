#include <iostream>
/*Дано число k, 0≤k≤31. Запишите число 2^k, то есть число, у которого k-й бит равен 1, а остальные — нули.
 * */
void task_1(){
    int k = 8;
    unsigned int a = 0x01;
    a = a << k;
    std::cout << a;
}

/*Дано целое число A и целое неотрицательное число число k. Обнулите у числа A его последние k бит и выведите результат.*/
void task_2(){
    int a = 3;
    int k = 1;
    a = a >> k;
    a = a << k;
    std::cout << a;
}

/*Установить к-ый бит в значениу а;*/
void SwitchBit(int &digit, int Position, int  bit){
    int a = 0x01;
    if(bit == 1){
        digit |= (a << Position);
        return;
    }
    digit ^= (a << Position);
}

int BinarySearch(int* ar, int left, int right, int target){
    if(right >= left) {
        int mid = (left + right) / 2;
        if (ar[mid] == target)
            return mid;
        if (ar[mid] < target)
            return BinarySearch(ar, mid + 1, right, target);
        if (ar[mid] > target)
            return BinarySearch(ar, left, mid - 1, target);
    }
    return -1;
}

int IterBinarySearch(int *ar, int left, int right, int target){
    while (left <= right){
        int middle = (left + right) / 2;
        if (ar[middle] == target)
            return middle;
        if (ar[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main() {
    int  *ar = new int[7]{1,2,4,5,6,8,10};
    int res = BinarySearch(ar, 0, 6, 4);
    std::cout << res;
    int res1 = IterBinarySearch(ar, 0, 6, 4);
    std::cout << std::endl << res1;
    return 0;
}
