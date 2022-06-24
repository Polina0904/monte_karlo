#include "iostream"
#include "random"
#include "grafic.cpp"
#include "vector"
#include "string"
using namespace sciplot;



std::vector<float> line_to_arr(std:: string str){
    std::stringstream input(str);
    float temp;
    std::vector<float> vect;
    while (input >> temp){
        vect.push_back(temp);
    }
    return vect;
}

float random(double first, double second)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(first, second);
    return dis(gen);
}

int main() {
    std::vector<float> x_vec;
    std::vector<float> y_vec;
    float left;
    float right;
    float top;
    int n;
    int k = 0;
    float s;
    float frame_s;
    float finds;
    std::cout << "Set left border:";
    std::cin >> left;
    std::cout << "Set right border:";
    std::cin >> right;
    std::cout << "Set top:";
    std::cin >> top;
    std::cout << "Do you know the total area? If yes, specify number, else send us '0':" << '\n';
    std::cin >> s;
    frame_s = (right-left)*top;
    std::cout << "Your frame_s is " << frame_s << '\n' << "Specify the number of points less frame_s:";
    std::cin >> n;
    std::vector<float> a_vec = {left, right, right, left, left};
    std::vector<float> b_vec = {0, 0, top, top, 0};
    std::cin.sync();
    std::string str;
    std::cout << "Print koeff for " << '\n';
    std::cout << "r*a^(b*x) + c*x^d + t*(sin(e*x))^m + s*(cos(g*x))^u + v*(tan(h*x)^w +z " << '\n';
    getline(std::cin,str);

    std::vector<float> vect = line_to_arr(str);


    for (int i = 0; i <= n; i++) {
        float x = random (left, right);
        float y = random (0, top);
        x_vec.push_back(x);
        y_vec.push_back(y);
        if (y<=(vect[0]*pow(vect[1],vect[2]*x)+vect[3]*pow(x,vect[4])+
        vect[5]*pow(sin(vect[6]*x),vect[7])+vect[8]*pow(cos(vect[9]*x),vect[10])+
        vect[11]*pow(tan(vect[12]*x),vect[13])+vect[14])) {
            k+=1;
        }
    }
    grafic_function(left, right, top, x_vec, y_vec, a_vec, b_vec, vect);
    finds = (k*frame_s)/n;
    if (s!=0) {
        float errors = ((finds - s) / s) * 100;
        std::cout << "I got " << finds << '\n';
        std::cout << "The error is " << fabs(errors) << "%";
    }
    return 0;
}
