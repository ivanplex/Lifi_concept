// Example program
#include <iostream>
#include <queue>
#include <bitset>

const int BYTESIZE = 8;


int main()
{

    std::queue<char> buffer;
    char byteArray [BYTESIZE] = {};

    buffer.push('0');
    buffer.push('1');
    buffer.push('1');
    buffer.push('0');
    buffer.push('0');
    buffer.push('0');
    buffer.push('1');
    buffer.push('1');

    buffer.push('0');
    buffer.push('1');
    buffer.push('1');
    buffer.push('0');
    buffer.push('0');
    buffer.push('0');
    buffer.push('1');
    buffer.push('0');

    buffer.push('0');
    buffer.push('1');
    buffer.push('1');
    buffer.push('0');
    buffer.push('0');
    buffer.push('0');
    buffer.push('1');
    buffer.push('0');

    int byteArrayPointer = 0;
    while(!buffer.empty()){


    	byteArray[byteArrayPointer] = buffer.front();
        buffer.pop();
        byteArrayPointer++;

    	if(byteArrayPointer == BYTESIZE){

    		unsigned char byte;
    		for(int i=0;i<BYTESIZE;i++)
			{
			    if(byteArray[i]== '1'){
			    	byte = byte|(1<<(BYTESIZE-1-i));
			    }
			}

			std::bitset<BYTESIZE> my_bset=std::bitset<BYTESIZE>(byte);
			std::cout << char(my_bset.to_ulong());

			std::cout << " | ";
			byte = 0;
            byteArrayPointer = 0;
    	}

    }
}

