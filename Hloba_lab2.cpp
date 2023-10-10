#include <iostream>
#include <chrono>

// Функція для переміщення диска з одного кілочка на інший та виведення повідомлення
void moveDisk(int disk, int source, int destination) {
    std::cout << "Перемiстити диск " << disk << " з кiлочка " << source << " на кiлочок " << destination << std::endl;
}

// Рекурсивна функція для розв'язання задачі про Ханойські вежі
void hanoi(int n, int source, int auxiliary, int destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }

    // Рекурсивно переміщуємо (n-1) диск з джерела на допоміжний стовп
    hanoi(n - 1, source, destination, auxiliary);

    // Переміщаємо останній диск з джерела на призначення
    moveDisk(n, source, destination);

    // Рекурсивно переміщуємо (n-1) диск з допоміжного стовпа на призначення
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {

    setlocale(LC_ALL, "");

    int n;
    std::cout << "Введiть кiлькiсть дискiв: ";
    std::cin >> n;

    // Вимірюємо час виконання алгоритму
    auto start = std::chrono::high_resolution_clock::now();

    hanoi(n, 1, 2, 3);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "Час виконання: " << duration.count() << " секунд." << std::endl;

    return 0;
}
