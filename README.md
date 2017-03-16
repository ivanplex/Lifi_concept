#Lifi Concept System

Implementation of an indoor Lifi System using a LED and a photodiode. 

WARNING: This is an incomplete system, use with caution!

##Equipment
- NXP FRDM-K64F with ARM® Cortex™-M4 32-bit (120MHz max)
- White LEDs
- Photodiode

##Digital Modulation

###CDMA

###On-off Keying 
- Simplest way of representing digital data over the air. (E.g ON for 1 and OFF for 0)
- (Cons) Need to differentiate between sending zero(off) and lost of connection.
- (Cons) Receiver has to know the transmitter's frequency accurately

###Amplitude-Shift Keying
- (Cons) Signal strength changes if the receiver is moving around

##Limits

###Maximum Transmition Rate
The maximum output rate is confined by the maximum frequency of the LED blink. This is due to the clock speed of the ARM chip running at 120MHz.

The following measurements are calculated for sending binary pair (E.g. "10" or "01")

|               | Binary Pair | Mean     | Minimum  | Maximum  | Std Dev |
| ------------- | ----------- | -------- | -------- | -------- | ------- |
| **Frequency** | 794.9kHz    | 794.7kHz | 795.3kHz | 152.9kHz | 152.9Hz |
| **Period**    | 1.258μs     | 1.258μs  | 1.257μs  | 1.259μs  | 242.2ps |

<img src="https://github.com/ivanplex/Lifi_concept/blob/master/docs/README/max_frequency_period.jpg" height="200px" width="280px" style="float: left;" alt="Frequency and Period at highest performance"/>


##Interference
Multipath interference could be ignored due to the low sensitivitly of the photo-diode and the minimal multipath time difference in a normal household situation. 
Light takes 3.3ns to travel through a meter. Assuming a reflection path which is 10 meters longer than a direct path, the time difference introduced is 33ns which is significantly lower than our sampling period of 629ns.

## Acknowledgments

- Kirk Martinez (https://github.com/kmartinez)
- Oli Bills


