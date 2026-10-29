# 6.5_diesel_src_decomp_OBD2
Hey all, started decoding this months ago, was having fun with it, but wanted to see if AI could help expedite an assembly for an easier time. I would not necessarily trust these files as I don't have a 6.5 anymore to test on, I was just bored. 
Use MINIIDE for assembling, it is banked code so you have to split the assembly in half build them then recombine
Ghidra project is not something I would trust either, had my fun with it but it has its issues for sure
Wanted to see if 4l60e code could be executed on board, tables are there but nothing calls them
I have other 6.5 calibrations without padding attached as well, probably will dump them into individual assembly.txt files when I feel like it
Have patched code for the deadband bug referenced by 1000cows, actually reads a value instead of RAM
You might be able to read and write an image to the EEPROM. Issue is that its only a full erase style so its stupidly risky, I aint keen on trusting AI or myself to write a kernel for something like PCMHAMMER to do so
XDF needs to be generated still
Thanks to Vampperformance for stocking the rest of the GM style cals, mixed in are manual, 4l80e, egr enabled, egr disabled, NA and Turbo calibrations.
Another thanks to pcmhacking for providing great info on this project, couldn't have made it this far without them.
