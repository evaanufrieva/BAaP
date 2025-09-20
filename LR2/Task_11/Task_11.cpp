#include <iostream>

int main(){
    int h1,min1,h2,min2;
    std::cout<<"Enter start time (h1 min1): ";
    std::cin>>h1 >> min1;
    std::cout<<"Enter end time (h2 min2):";
    std::cin>>h2 >> min2;
    int start_seconds = h1 * 3600 + min1 * 60;
    int end_seconds = h2 * 3600 + min2 * 60;
    int diff_seconds = end_seconds - start_seconds; 
    if (diff_seconds<0)
    {
        std::cout<<"End time must be after start time.\n";
        return 1;
    }
     
    double hours=diff_seconds/3600;
    double minutes=(diff_seconds%3600)/60;
    double sec=diff_seconds%60;

    std::cout<<"Time spent studying: "<< hours <<" hours, "<< minutes <<" minutes, "<< sec<<" seconds"<<"\n";
    return 0;
}