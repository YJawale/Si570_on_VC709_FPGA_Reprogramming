#These are the constraints for SMA output and Si570 input for the custom RTL block that you have created to check the clock signals on USER_SMA ports of VC709 FPGA.
#Change name of ports as per your block design

  
set_property PACKAGE_PIN AK34 [get_ports clk_p_0] 
set_property PACKAGE_PIN AL34 [get_ports clk_n_0]
set_property IOSTANDARD LVDS [get_ports clk_p_0]
set_property IOSTANDARD LVDS [get_ports clk_n_0]

create_clock -period 1.250 -name SI570_CLK [get_ports clk_p_0]

set_property PACKAGE_PIN AJ32 [get_ports sma_p_0]
set_property PACKAGE_PIN AK32 [get_ports sma_n_0]
set_property IOSTANDARD LVDS [get_ports sma_p_0]
set_property IOSTANDARD LVDS [get_ports sma_n_0]
