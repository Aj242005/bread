#include <dependencies.h>

//please make sure that the language have each space with each word and each of the individual string

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
            if(argv[1]){
                
            }
            cout<<"The name of the bread file is : "<<argv[1]<<endl;
            return 0;
        }
    }
    return 0;
}