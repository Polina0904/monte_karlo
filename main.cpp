#include <iostream>
#include <random>
#include "grafic.cpp"

float random(double first, double second)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(first, second);
    return dis(gen);
}

int main() {
    float left;
    float right;
    int top = 700;
    int n;
    int k = 0;
    float s;
    float frame_s;
    float finds;
    std::cout << "Set left border:";
    std::cin >> left;
    std::cout << "Set right border:";
    std::cin >> right;
    std::cout << "Do you know the total area? Specify:" << '\n';
    std::cin >> s;
    frame_s = (right-left)*top;
    std::cout << "Your frame_s is" << frame_s << '\n' << "Specify the number of points less frame_s:";
    std::cin >> n;

    for (int i = 0; i <= n; i++) {
        float x = random (left, right);
        float y = random (0, top);
        if (y<=(33+7*x*x*x*x)) {
            k+=1;
        }

    }
    
    finds = (k*frame_s)/n;

    float errors = ((finds-s)/s) * 100;
    std::cout << "I got " << finds << '\n';
    std::cout << "The error was " << errors << "%";
    return 0;
}
