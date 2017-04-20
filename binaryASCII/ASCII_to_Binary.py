"""
Lifi-concept using embedded FRDM-K64F
Written by Ivan Chan (mlc1g14@soton.ac.uk) & Dev Dixit (dd9g13@soton.ac.uk)
 
Project for Advance Computer Networks under the supervision of 
Kirk Martinez (https://github.com/kmartinez) & Olli Bills (ob@ecs.soton.ac.uk)


ASCII To Binary
Read ASCII information on plaintext.txt and convert them to binary signals
ready for transmission. This includes the following encoding:
"0" - 001
"1" - 110

Python 2 implementation

"""

import binascii

#Read file
file = open("plaintext.txt", "r") 
plaintext = file.read()

binaryText = bin(int(binascii.hexlify(plaintext), 16))[2:]

print(binaryText[3])

#Binary Encoding
ZEROENCODE = [0,0,1]
ONEENCODE = [1,1,0]
EncodedList = []
i = 0
while i < len(binaryText):
	if(binaryText[i] == "0"):
		EncodedList.extend(ZEROENCODE)
	elif(binaryText[i] == "1"):
		EncodedList.extend(ONEENCODE)
	i=i+1

#Results
print(">>> Array length: "+ str(len(EncodedList)))
print(EncodedList)
