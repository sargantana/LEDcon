# LEDcon
BLE RGB LED PWM Controller

## What is this?

This is a simple DIY Arduino based RGB LED PWM Controller used to control LEDs like RGB Strips via Bluetooth using an HC-05 module.
It uses a serial connection via bluetooth to recieve rgb data to display on the LEDs.
I used a Arduino Nano in the final circuit (as it has 6 PWM outputs suitable to drive two independent RGB Stripes), diagram is using a digispark-board (ATtiny85 based arduino compatible). You can switch out the digispark with every boasrd you want, just remember to change Pins in the code.

## Circuit Diagram
![schematics](LEDcon_circuit_diagram.png?raw=true "circuit diagram")


## Hardware

### NEEDED


* __PCB__
* __Arduino compatible board__ (i.e. digispark, arduino nano, arduino pro, teensy etc)
* __Bluetooth Serial Module__ (*HC-06* or *HC-05* should both work, only tested with HC-05
* __3x n-Channel MOSFETs__ (I used STP55NF06L 60V@55A as found on RAMPS 1.4 board)
   > *the use of mosfets depends on the amount of LEDs you want to drive. If you want to drive a single RGB LED or two the current provided by arduino should be sufficient*
* __DC in barrel jack__
* __Sufficient PSU >=12V__ 
  > *the voltage regulator used on arduino boards differ a lot. Check the datasheet to ensure your board can handle your voltage. Depending on your board you may even consider a laptop power brick, but remember this circuit is designed for use at 12V*


### RECOMMENDED


The following components are not explicit neccessary, but highly recommended to guarantee stable use and longevity.

* __electrolytic capacitor C1__ (I used 2200uF @ 16V)
* __3x Resistors R-FET__ (using STP55NF06L I recommend 120Ω. You could also enhance the circuit with pulldown/-up resistors.)
* __Voltage divider__ (I used 1kΩ as R-Tx and 2kΩ as R-GND)
  > *the voltage divider simply consists of two resitros, while the one connected to ground has the doubled value of the first one bridging the Arduino Tx and HC-05 Rx pin, as this is designed to use with 3.3v the voltage divider knocks that 5v logic signal down. For further informatiojn on voltage dividers visit: https://learn.sparkfun.com/tutorials/voltage-dividers *
