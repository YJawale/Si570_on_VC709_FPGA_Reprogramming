# Si570_on_VC709_FPGA_Reprogramming
This repository will guide you through how to reprogram your Si570 clock on VC709 FPGA board via IIC (I2C) interface. 
This does not cover how to generate the values that you must fill in the register spaces, that can be done by following these links - 
the skyworks document for si570 - https://www.skyworksinc.com/-/media/skyworks/sl/documents/public/data-sheets/si570-71.pdf
software by skyworks for si570 - https://www.skyworksinc.com/en/application-pages/Programmable-Oscillator-Software

After going through this process, you'll be left with a bunch of instructions and information about which register to fill with what value.
Note that VC709 has the 50ppm Si570, and different variants have different register spaces to be filled. 
Now that you have the data you need ready, you can start with first initializing a vivado block design with Microblaze, IIC and UART interface (UART just for debugging).
My vivado block design - 
<img width="1296" height="368" alt="image" src="https://github.com/user-attachments/assets/e50f14cf-85d7-45c5-9251-afa8bd28b2ac" />

Note that the RTL block in the bottom was used to redirect my Si570 clock outputs to the USER SMA ports, and are not necessary to establish in your design if you dont intend to use it.
Run bitstream and export the hardware to SDK/Vitis (I was working with Vivado 2018.3, so SDK for me), and continue with the code provided!
