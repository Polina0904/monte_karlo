#include <sciplot/sciplot.hpp>
#include "main.cpp"
using namespace sciplot;


int graficc(int argc, char** argv) {
    Vec x = linspace(-2.0, 4.0, 100);
    Vec x1 = {0, 0, 0, 2, 1, 3, 2, 0.5, 0.3, 2, 0, 0.8};
    Vec y = {0, 0.5, 0.5, 2, 2, 1, 0, 0.3, 0.4, 0.2};
    Vec a = {-3, -3, 3, -3};
    Vec b = {0, 2, 0, 0};

    Plot plot;

    //plot.drawCurve(x, std::cos(x)).label("cos(x)");
    //plot.drawCurve(x, exp(x)).label("exp(x)");
    plot.drawCurve(x, 7 * pow(x, 4) + 0 * x + 33).label("7*x^4+33");
    // plot.drawCurve(x, sqrt(x)).label("sqrt(x)");
    // plot.drawStepsChangeFirstX(a,b).label("granica").lineColor("green");
    plot.autoclean(false);
    //plot.drawPoints(x1,y).label("");

    plot.show();
    //plot.save("gr_f.pdf");

}
