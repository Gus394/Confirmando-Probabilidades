#include <iostream>

void teste(int &num) {
    std::cin >> num;
    return;
}

int main()
{
    int num = 0;
    teste(num);
    std::cout << num;
}
