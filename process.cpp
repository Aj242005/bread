#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main(int argc, char* argv[]){
    if(argc <= 1){
        cout<<"Missing compilation file"<<endl;
        return 1;
    }
    else{
        if(argc > 2){
            cout<<"More than one files for compilation received. Can't render them at once due to global script pollution";
            return 1;
        }
        else{
            cout<<"The name of the bread file is : "<<argv[1]<<endl;
            return 0;
        }
    }
    return 0;
}