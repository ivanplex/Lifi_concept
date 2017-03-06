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

<table style="float:right;"><thead>
<tr>
<th></th>
<th>Binary Pair</th>
<th>Mean</th>
<th>Minimum</th>
<th>Maximum</th>
<th>Std Dev</th>
</tr>
</thead><tbody>
<tr>
<td><strong>Frequency</strong></td>
<td>794.9kHz</td>
<td>794.7kHz</td>
<td>795.3kHz</td>
<td>152.9kHz</td>
<td>152.9Hz</td>
</tr>
<tr>
<td><strong>Period</strong></td>
<td>1.258μs</td>
<td>1.258μs</td>
<td>1.257μs</td>
<td>1.259μs</td>
<td>242.2ps</td>
</tr>
</tbody></table>

<img src="https://github.com/ivanplex/Lifi_concept/blob/master/docs/README/max_frequency_period.jpg" height="200px" width="280px" style="float: left;" alt="Frequency and Period at highest performance"/>

~~According to [SpazzTech](https://www.youtube.com/watch?v=dfkhMMWlcI4), the highest GPIO toggle he can acheive is 390KHz with a LED running at 3.3v.~~

