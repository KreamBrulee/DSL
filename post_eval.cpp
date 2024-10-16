#include <iostream>
#include "stacker.h"
#include <string.h>
int main(int argc,char **ex);

using namespace std;

bool isDigit(char ch){
    if(ch>='0' || ch<='9')
        return true;
    return false;
}

int eval(int a,int b,char opr){
    switch(opr){
        case '+':return(a+b);
        case '-':return(a-b);
        case '*':return(a*b);
        case '/':return(a/b);
    }
    return 0;
}

int main(int argc,char **ex){
    stk <int> s;
    
    for(int i=1;i<argc;i++){
        if(isDigit(ex[i][0])){
            for(int j=0;!ex[i][j] == '\0';j++){
                cout<<ex[i][j];
            }
        }
    }
    return(0);
}

