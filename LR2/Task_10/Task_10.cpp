#include <iostream>
using namespace std;

string checkCircles(int x1, int y1, int r, int x2, int y2, int R){
    int dx=x2-x1;
    int dy=y2-y1;
    int dpow2=dx*dx+dy*dy;
    int diff=R-r;
    if (diff<0) diff=-diff;
    
    if (dpow2<(R-r)*(R-r) && R>=r)
    {
        return "Да";  
    }else if (dpow2<(r-R)*(r-R) && r>=R)
    {
        return "Да, но справедливо обратное для двух фигур";
    }else if ((diff*diff<dpow2) && dpow2<(R+r)*(R+r))
    {
        return "Фигуры пересекаются";
    }else{
        return "Ни одно условие не выполнено";
    }
    
    
}

int main(){
    int x1,y1,x2,y2,r,R;
    std::cout<<"Enter M1(x1, y1) coord: ";
    std::cin>> x1 >> y1;
    std::cout<<"Enter radius r: ";
    std::cin>> r;
    std::cout<<"Enter M2(x2, y2) coord: ";
    std::cin>> x2 >> y2;
    std::cout<<"Enter radius R: ";
    std::cin>> R;
    std::cout<<checkCircles(x1,y1,r,x2,y2,R);
}