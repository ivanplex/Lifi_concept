#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void A_to_B(const char*);   //function for converting ASCII to Binary
void B_to_A(const char*);   //function for converting Binary to ASCII

int main(void)
{
	cout << " ASCII/Binary Converter" << endl;
	cout << " ============================ \n \n" << endl;
	
	char response;   //used to store user's response to the next question
	char garbage[50];   //used to clear entry buffer in case user types more than 1 character
	cout << " 1. ASCII to Binary Converter" << endl;
	cout << " 2. Binary to ASCII Converter" << endl;
		
	while(response != '1' && response != '2' && response != 'N' && response != 'n') 
	//loop if the user's response is none of the above. 
	{
		cout << "\n Enter \"1\" or \"2\" to specify task. Enter \"N\" to quit: ";
		cin >> response;    //store the user's response in "response"
		cin.getline(garbage, 50);    //get rid of the entire line from the entry buffer
		
		if(response != '1' && response != '2' && response != 'N' && response != 'n')
		//will fun if user enteres unrecognized entry for "response"
			cout << " The value you entered was invalid. Please try again" << endl;
	}
	
	if(response == 'N' || response == 'n')  //if the user chooses to quit
	{
		cout << "User cancel" << endl;
		exit(0);
		//output text informing termination, terminate program, return "0" for no error. 
	}
	
	char text[501];
	cout << " Enter the text/code you want to convert: ";
	cin >> text;
	
	if(response == '1')
	{
		A_to_B(text);    //if the user chose ASCII --> Binary, to go A_to_B()
	}
	else  //only choice left here is response == 2
	{

		B_to_A(text);    //if the user chose Binary --> ASCII, go to B_to_A()
	}
	
	cout << " Conversion finished" << endl;  
	
	return 0;
}

void A_to_B(const char* input) 
{
	int ascii;           // used to store the ASCII number of a character
	int length = strlen(input);        //find the length of the user's input
	
	cout << " ";
	
	for(int x = 0; x < length; x++)          //repeat until user's input have all been read
	// x < length because the last character is "\0"
	{
		ascii = input[x];        //store a character in its ASCII number
		
		/* Refer to http://www.wikihow.com/Convert-from-Decimal-to-Binary for conversion method used 
		 * in this program*/		
		
		char* binary_reverse = new char [9];       //dynamic memory allocation
		char* binary = new char [9];
		
		int y = 0;    //counter used for arrays
		
		while(ascii != 1)    //continue until ascii == 1
		{
			if(ascii % 2 == 0)    //if ascii is divisible by 2
			{
				binary_reverse[y] = '0';   //then put a zero
			}
			else if(ascii % 2 == 1)    //if it isnt divisible by 2
			{
				binary_reverse[y] = '1';   //then put a 1
			}
			ascii /= 2;    //find the quotient of ascii / 2
			y++;    //add 1 to y for next loop
		}
		
		if(ascii == 1)    //when ascii is 1, we have to add 1 to the beginning
		{
			binary_reverse[y] = '1';
			y++;
		}
		
		if(y < 8)  //add zeros to the end of string if not 8 characters (1 byte)
		{
			for(; y < 8; y++)  //add until binary_reverse[7] (8th element)
			{
				binary_reverse[y] = '0';
			}
		}
	
		for(int z = 0; z < 8; z++)  //our array is reversed. put the numbers in the rigth order (last comes first)
		{
			binary[z] = binary_reverse[7 - z];
		}
		
		cout << binary;   //display the 8 digit binary number
		
		delete [] binary_reverse;     //free the memory created by dynamic mem. allocation
		delete [] binary;
	}
	
	cout << endl;
}

void B_to_A(const char* input)
{
	int length = strlen(input);     //get length of string
	
	int binary[8];    //array used to store 1 byte of binary number (1 character)
	int asciiNum = 0;      //the ascii number after conversion from binary
	char ascii;      //the ascii character itself
	
	cout << " ";
	
	int z = 0;   //counter used
	
	for(int x = 0; x < length / 8; x++)     //reading in bytes. total characters = length / 8
	{
		for(int a = 0; a < 8; a++)      //store info into binary[0] through binary[7]
		{
			binary[a] = (int) input[z] - 48;      //z never resets
			z++;
		}
		
		int power[8];    //will set powers of 2 in an array
		int counter = 7;        //power starts at 2^0, ends at 2^7
		for(int x = 0; x < 8; x++)
		{
			power[x] = counter;      //power[] = {7, 6, 5, ..... 1, 0}
			counter--;    //decrement counter each time
		}
		
		for(int y = 0; y < 8; y++)    //will compute asciiNum
		{
			double a = binary[y];    //store the element from binary[] as "a"
			double b = power[y];    //store the lement from power[] as "b"
			
			asciiNum += a* pow(2, b);   //asciiNum = sum of a * 2^power where 0 <= power <= 7, power is int
		}
		
		ascii = asciiNum;   //assign the asciiNum value to ascii, to change it into an actual character
		asciiNum = 0;    //reset asciiNum for next loop
		
		cout << ascii;	//display the ascii character
	}
}
