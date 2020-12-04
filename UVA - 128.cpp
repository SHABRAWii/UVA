#include <iostream>
#include <cmath>

using namespace std;
int main(){
    y:
//    freopen("CodeForces.txt", "r", stdin);
    string input = "";
    int g = 34943;
    while(getline(cin, input) && input != "#"){
        unsigned long m = 0;
        for (int i = 0 ; i < input.size() ; i++){
            m <<= 8;
            m += input[i];
            m %= g;
        }
        m <<= 16;
        m %= g;
        // CRC is the message we add to m to make new m % g == 0;
        int CRC = (g - m) % g;
        int byte1 = CRC >> 8; //last  8 bits = CRC >> 8 because we throw the first 8
        int byte2 = (CRC ) % 256;//first 8 bits = CRC % 256 because (256)10 = (00000000 1111111)2
        printf("%02X %02X\n" , byte1 , byte2);//we print two bytes : one byte = 8 bit
    }
//    goto y;
return 0;
}
