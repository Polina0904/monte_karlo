#include "iostream"
#include "random"
#include "grafic.cpp"
#include "windows.h"
#include "vector"
#include "sstream"
using namespace sciplot;

/*std::vector<float> line_to_arr(std:: string str){
    std::stringstream input(str);
    float temp;
    std::vector<float> vect;
    while (input >> temp){
        vect.push_back(temp);
    }
    return vect;
}
*/

float random(double first, double second)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(first, second);
    return dis(gen);
}

float func(float vect[], float x)
{
    return (vect[0]*pow(vect[1],vect[2]*x)+vect[3]*pow(x,vect[4])+
            vect[5]*pow(sin(vect[6]*x),vect[7])+vect[8]*pow(cos(vect[9]*x),vect[10])+
            vect[11]*pow(tan(vect[12]*x),vect[13])+vect[14]);
}

float accuracy(float s, float finds)
{
    return fabs((1-fabs(1-((finds/s)))) );
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<float> x_vec;
    std::vector<float> y_vec;
    std::vector<double> accuracy_analyze_vec;
    float left;
    float right;
    float top;
    int n;
    int k = 0;
    float s;
    float frame_s;
    float finds;
    bool flag;
    //std::string str;
    std::cin.sync();
    std::cout << "Укажите коэффициенты " << '\n';
    std::cout << "r*a^(b*x) + c*x^d + t*(sin(e*x))^m + s*(cos(g*x))^u + v*(tan(h*x)^w +z " << '\n';
    //getline(std::cin,str);
    float vect[15];
    std::cin >> vect[0]>> vect[1]>> vect[2] >> vect[3]>> vect[4]>> vect[5]>> vect[6]>> vect[7]>> vect[8]>> vect[9]>> vect[10]>> vect[11]>> vect[12]>> vect[13]>> vect[14];
    //std::vector<float> vect = line_to_arr(str);
    std::cout << "Граница слева:";
    std::cin >> left;
    std::cout << "Граница справа:";
    std::cin >> right;
    std::cout << "Граница сверху:";
    std::cin >> top;
    std::vector<float> a_vec = {left, right, right, left, left};
    std::vector<float> b_vec = {0, 0, top, top, 0};
    std::cout << "Вы хотите найти интеграл(0) или провести исследование(1)?";
    std::cin >> flag;
    frame_s = (right-left)*top;
    std::cout << "Площадь ограниченной области: " << frame_s<< '\n';
    std::cout << "Укажите количество точек:";
    std::cin >> n;
    std::cout << "Укажите эталонную площадь или укажите '0':" << '\n';
    std::cin >> s;


    for (int i = 0; i <= n; i++) {
        float x = random(left, right);
        float y = random(0, top);

        if (y <= func(vect, x)) {
            k += 1;
        }
        if (flag and s) {
            finds = (k * frame_s) / n;
            accuracy_analyze_vec.push_back(accuracy(s, finds));
        }

        if (not flag) {
            x_vec.push_back(x);
            y_vec.push_back(y);
        }
    }
    if (flag){research_grap(n,accuracy_analyze_vec);}


    else{
        finds = (k*frame_s)/n;
        std::cout << "Получено: " << finds << '\n';
        grafic_function(left, right, top, x_vec, y_vec, a_vec, b_vec, vect);
        if (s!=0 and finds!=0) {
            std::cout << "Точность:  " << (accuracy(s,finds)) ;
        }

    }

}