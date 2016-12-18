# XMasOrnament
Arduino based "configurable" blink code to go with a character darwing as a simple ornament.

The project is an extension of practically every "blink LED" sample that there ever has been, but wrapped into a cute little art display.

You can use the "Instructions.pdf" to print out building instructions - the sources for the document are in the MakingOf and Artwork folders.

The "Schematic.pdf" shows the wiring of the LEDs as a schematic. The source is a KiCAD schematic in the Schematic folder.


# The artwork
The artwork was commissioned by me for this project and done by Karpour. If you create branches of the project, please make sure to either include the original, unmodified version of the lineart or replace the artwork with your own creation entirely.

You can use the provided artwork (lineart) "as is" or use it like a coloring book page, which might be a fun project with the kids!

# The schematic
...is actuall provided for reference mostly. There is nothing complicated going on here: Two (yellow) LEDs in series share one output of the Arduino and are connected to +5V via a resistor to limit the current according to the type of LED. I had two versions around, a 2mA and a 20mA version so I used 100 and 1000 Ohms respectively. Please check with your LED source what the maximum current is. The limit for the Arduino in this configuration is 20mA per pin when we use the seven channels that are active. This will also fit nicely into a USB-powered solution.

# The software
The sourcecode is made to run with the Arduino Studio and should be compatible with almost all Arduino compatible ATMega based 5V devices. Since I don't have any others around, I could not test and validate that claim: please provide feedback if you implement it on another board!


 
