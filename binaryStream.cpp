// Example program
#include <iostream>
#include <queue>
#include <bitset>



int main()
{

    std::queue<char> buffer;
    char stream [24] = {'0','1','1','0','0','0','1','1',
    					'0','1','1','0','0','0','1','0',
    					'0','1','1','0','0','1','0','0'};

    int count = 0;
    while(count<24){
    	buffer.push(stream[count]);

    	if(buffer.size() == 8){

    		int pointer = 0;
    		unsigned char byte;
    		while (!buffer.empty())
			  {
			    if(buffer.front()== '1'){
			    	byte = byte|(1<<(7-pointer));
			    }
			    buffer.pop();
			    pointer++;
			  }

			std::bitset<8> my_bset=std::bitset<8>(byte);
			std::cout << char(my_bset.to_ulong());

			std::cout << " | ";
			byte = 0;
    	}

    	count++;
    }
}

