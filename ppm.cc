#include <iostream>
using namespace std;

// this is a comment

int main(){

    int width = 2000;
    int height = 1000;

    cout<<"P3"<<endl;
    cout<<width<<" "<<height<<endl;
    cout<<"255"<<endl;

    for (int h = 0; h < height; h++){
        for( int w = 0; w < width; w++){
            int red = float(w)/(width-1) * 255.99;
            int green = float(h)/(height-1) * 255.99;
            int blue = 1.0 * 255.99;
            
            cout<<red<<" "<<green<<" "<<blue<<endl;
        }
    }
}


