#Lifi Concept System

Implementation of an indoor Lifi System using a LED and a photodiode. 

WARNING: This is an incomplete system, use with caution!

##Equipment
- NXP FRDM-K64F with ARM® Cortex™-M4 32-bit (120MHz max)
- White LEDs
- Photodiode

##Digital Modulation

###On-off Keying 
- Simplest way of representing digital data over the air. (E.g ON for 1 and OFF for 0)
- (Cons) Need to differentiate between sending zero(off) and lost of connection.
- (Cons) Receiver has to know the transmitter's frequency accurately



###Alternative Methods
####Amplitude-Shift Keying
- (Cons) Signal strength changes if the receiver is moving around
