#include <sciplot/sciplot.hpp>
using namespace sciplot;


int grafic_function( float left, float right, float top, std::vector <float> x_vec, std::vector <float> y_vec,
                 std::vector<float> a_vec, std::vector<float> b_vec, std::vector<float> vect ) {
    Vec x = linspace(left, right, 100);

    Plot plot;

    plot.autoclean(false);
    plot.xrange(left, right);
    plot.yrange(0.0,top);
    plot.drawCurve(x, (vect[0]*pow(vect[1],vect[2]*x)+vect[3]*pow(x,vect[4])+
                       vect[5]*pow(sin(vect[6]*x),vect[7])+vect[8]*pow(cos(vect[9]*x),vect[10])+
                       vect[11]*pow(tan(vect[12]*x),vect[13])+vect[14])).label("function").lineColor("blue");
    plot.drawStepsChangeFirstX(a_vec,b_vec).label("granica").lineColor("orange");
    plot.drawPoints(x_vec,y_vec).label("").lineColor("magenta").pointType(7);
    plot.show();
    //plot.save("gr_f.pdf");
    return 0;
}
//int granicy(){
//
//    Vec a = {-3, -3, 3, -3};
//    Vec b = {0, 2, 0, 0};
//
//    Plot plot;
//    plot.drawStepsChangeFirstX(a,b).label("granica").lineColor("green");
//    plot.show();
//    //plot.save("gr_f.pdf");
//    return 0;
//}

//int point(std::vector <float> x_vec, std::vector <float> y_vec, Plot plot){
//
//    plot.autoclean(false);
//    plot.drawPoints(x_vec,y_vec).label("");
//    plot.show();
//    return 0;
//    //plot.save("gr_f.pdf")
//}
