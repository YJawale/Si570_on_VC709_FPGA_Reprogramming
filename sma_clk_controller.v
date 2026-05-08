//This is the RTL block you can see at the bottom of my block design. The use of this is to re-direct Si570 clock signals to the USER_SMA ports on the VC709 board, if you want to check the clock rate on an Oscilloscope.
//Copy paste this block in your Vivado project, and add it to your block desing. 
//Make external ports for the clock inputs and SMA port outputs, and also check out the .xdc (constraint file) I have uploaded to have it work smoothly :)

module sma_clk_controller(
    input  wire clk_p,
    input  wire clk_n,
    output wire sma_p,
    output wire sma_n

    );

wire clk_bufg;
wire clk_ibuf;
IBUFDS ibuf_inst (
    .I(clk_p),
    .IB(clk_n),
    .O(clk_ibuf)
);


OBUFDS obuf_inst (
    .I(clk_ibuf),
    .O(sma_p),
    .OB(sma_n)
);
endmodule
