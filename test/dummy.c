int main() {
    int arr[5];
    arr[2] = 1;

    return 0;
}

int helper() {
    int test = 5;
    int* ptr = &test;
    *ptr = 6;
}
