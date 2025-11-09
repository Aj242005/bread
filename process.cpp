#include "dependencies.h"
#include "bread-lexer.h"
//please make sure that the language have each space with each word and each of the individual string

using namespace std;

int main(int argc, char* argv[]){
    if(argc <= 1){
        cout<<"Error : Missing compilation file"<<endl;
        return 1;
    }
    else{
        if(argc > 2){
            cout<<"More than one files for compilation received. Can't render them at once due to global script pollution";
            return 1;
        }
        else{
            int length = strlen(argv[1]);
            if(argv[1][length-1] != 'd' || argv[1][length-2] != 'b' || argv[1][length-3] != '.' ){
                cout<<"Error (001) : Not a valid File format, use .bd as the file extension"<<endl;
                return 1;
            }

            fstream breadFile(argv[1]);
            string codeLine;
            if(!breadFile.is_open()){
                cout<<"Error (002) : Error opening the file, either the file do not exist or the file you want to compile is corrupted"<<endl;
                return 1;
            }
            while( getline(breadFile,codeLine)){
                for(auto i : lexingTheStringTokens(removeSpacesFromInput(codeLine))){
                    cout<<"{ "<<i.first<<" : "<<"'"<<i.second<<"' "<<"}"<<endl;
                }
                cout<<"End of line"<<endl;
            }
            return 0;
        }
    }
    return 0;
}