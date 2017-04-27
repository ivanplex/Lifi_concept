#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    
    char arr[10] = {'0','1','0','1','1','0','1','?','0','1'}; 
    int zeroCounter = 0;
    int oneCounter = 0;
    int qCounter = 0;

    for(int i=0; i<sizeof(arr); i++) 
    {
        if(arr[i] == '0') {
            zeroCounter++;
        } else if(arr[i] == '1') {
            oneCounter++;
        } else {
            qCounter++;
        }
    }
    
    printf("%d%s\n", zeroCounter, " Number of zeros");
    printf("%d%s\n", oneCounter, " Number of ones ");
    printf("%d%s\n", qCounter, " Number of question marks");
    
    if(zeroCounter > oneCounter) {
        return zeroCounter;
    } 
    
    return oneCounter;
}
