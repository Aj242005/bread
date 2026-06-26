#include "dependencies.h"
#include "bread-lexer.h"
#include "custom-exceptions.h"
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
                throw IncorrectExecutionError("Error (001) : Not a valid File format, use .bd as the file extension");
            }

            fstream breadFile(argv[1]);
            string codeLine;
            if(!breadFile.is_open()){
                throw IncorrectExecutionError("Error (002) : Error opening the file, either the file do not exist or the file you want to compile is corrupted");
            }
            int lineNumber = 0;
            bool hadError = false;
            while( getline(breadFile,codeLine)){
                lineNumber++;
                try{
                    for(auto i : lexingTheStringTokens(removeSpacesFromInput(codeLine), lineNumber)){
                        cout<<"{ "<<i.first<<" : "<<"'"<<i.second<<"' "<<"}"<<endl;
                    }
                    cout<<"End of line"<<endl;
                }
                catch(exception &e){
                    cerr << e.what() << endl;
                    hadError = true;
                }
            }
            return hadError ? 1 : 0;
        }
    }
    return 0;
}