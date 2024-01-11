// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "processing.h"
#include "Image.h"
#include <string>
#include "Matrix.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
using namespace std;
int main(int argc, char *argv[]) {
    
    if(argc!= 4 && argc != 5){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
              << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }

    string imputfile = argv[1];
    string outputfile = argv[2];
    
    ifstream is;
    is.open(argv[1]);
    if (!is.is_open()){
    cout << "Error opening file: " << imputfile << endl;
        return 1;
    }
    
    Image *img = new Image;
    Image_init(img, is);
    
    int width = atoi(argv[3]);
    int height;
        if(argc == 4){
            height = Image_height(img);
        }
        else{
            height = atoi(argv[4]);
        }
    
    if((width < 0 || width > Image_width(img))
           && (height < 0 || height > Image_height(img))){
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                 << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    }
    
    
    seam_carve(img, width, height);
    
    ofstream os;
    os.open(outputfile);
    Image_print(img, os);
    delete img;
}

