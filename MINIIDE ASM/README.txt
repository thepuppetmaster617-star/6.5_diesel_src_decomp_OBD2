GM 6.5L diesel ECM 16216588 (OBD2), calibration 09389101 - asm11 source for MGTEK MiniIDE

UNPATCHED\   stock firmware. Assembles byte-for-byte to the original bin (ROM checksum $D7C1).
PATCHED\     same source with the ECTS deadband bug fixed (ROM checksum $D7B1).

The fix (bank 0, address F77C):
  stock    cmpb <$03   (D1 03)  compares the coolant drop with RAM $0003, a trouble-code flag byte
  patched  cmpb #$03   (C1 03)  compares it with the intended 3-count deadband
With no such code set, the stock code never lets the filtered coolant value used for the idle-speed
target follow the coolant temperature down. Only F77C and the checksum at $2004 differ between versions.

Files in each folder
  bank0.asm          bank 0 code, $5900-$FFFF (includes equates.inc and cal.inc)
  bank1.asm          bank 1 code, $8000-$FFFF (includes equates.inc and common.inc)
  equates.inc        RAM / I-O names with notes
  common.inc         bank-0 labels below $8000 used by bank 1
  cal.inc            selects the calibration file
  cal_09389101.inc   calibration $2000-$58FF

Building: assemble bank0.asm and bank1.asm (asm11 -case -l <file>). Load bank0.s19 at file offset 0
and bank1.s19 at file offset $10000 of a 128K image filled with $FF. The ROM checksum is the 16-bit
sum of bank0 $2006-$FFFF + bank1 $8000-$FFFF, stored big-endian at $2004.
For the 28F010 chip, the flash address lines A1/A13, A2/A12, A3/A11 and A10/A14 are swapped.
