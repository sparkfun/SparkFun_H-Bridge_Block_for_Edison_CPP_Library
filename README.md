SparkFun H-Bridge Block for Edison C++ Library
==============================================

SparkFun's H-Bridge Block for Edison adds a two-channel low-voltage
low-current h-bridge (the Toshiba TB6612) to your stack. The block can be
configured to draw power either from the VSYS supply of the stack or from an
external supply connected to the header on the block.

This library abstracts all of the IO handling away from the user; all the user
need do is provide a signed floating point value representing the duty cycle
(from -1.0 to +1.0) for each motor.

Repository Contents
-------------------

* **SparkFun_TB6612_Edison.h** - Header file containing class, function, and
constant definitions used by the tb6612 C++ library.
* **SparkFun_TB6612_Edison.cpp** - Class implementation for tb6612 class.
* **SparkFun_H-Bridge_Edison_Block_Example.cpp** - example code which will show you
how to access all of the functions in the library.

Documentation
--------------

* **[Programming the Intel Edison](https://learn.sparkfun.com/tutorials/edison-getting-started-guide)** -
Getting up and running with the Edison. Start here!
* **[General Block Information](https://learn.sparkfun.com/tutorials/general-guide-to-sparkfun-blocks-for-intel-edison)** - 
Information applicable to all blocks, such as power requirements and how to
install them.
* **[Programming the Edison](https://learn.sparkfun.com/tutorials/programming-the-intel-edison-beyond-the-arduino-ide)** -
This library uses Intel's [mraa](https://github.com/intel-iot-devkit/mraa) 
library to access hardware resources. This tutorial will help you get started
using mraa to write code in C++. **This is not an Arduino library.**
* **[H-Bridge Block Hookup Guide](https://learn.sparkfun.com/tutorials/sparkfun-blocks-for-intel-edison---dual-h-bridge)** - 
Hookup guide specific to this block, which includes information on the circuits
used in the demo code.

Products that use this Library 
---------------------------------

* [H-Bridge Block](https://www.sparkfun.com/products/13043)

License Information
-------------------

This product is _**open source**_! 

The code is released under GPL. 

Distributed as-is; no warranty is given.

- Your friends at SparkFun.

