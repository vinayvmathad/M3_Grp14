# Introduction
  * RKE system consists of an RF transmitter in the keyfob (or key) that sends a short burst of digital data to a receiver in the vehicle, where it is decoded and made to open or close the vehicle doors or the trunk via receiver-controlled actuators. The wireless carrier frequency, is currently 315MHz in the US/Japan and 433.92MHz (ISM band) in Europe. In Japan the modulation is frequency-shift keying (FSK), but in most other parts of the world, amplitude-shift keying, or ASK is used. The carrier is amplitude modulated between two levels: To save power, the lower level is usually near zero, producing complete on-off keying (OOK).
  ## High Level Requirements:
   | ID |   High Level REquirements   |
   |----|-----------------------------|
   |HR01|   	  Print lock             |
   |HR02|   	   Print Unlock          |
   |HR03|Alarm Activation/Deactivation|  
   |HR04|   	Print approach light     | 
   ### Low Level Requirements:
  | ID |      Low level Requirements      | HR ID|
  |----|----------------------------------|------|
  |LR01|All led on at the same time       | HR01 |
  |LR02|All led off at the same time      | HR02 |
  |LR03|All led on in clockwise manner    | HR03 |
  |LR04|All led on in Anticlockwise manner| HR04 |