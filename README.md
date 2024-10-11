# Pandora - Custom 32 Bit CPU

<samp>Built a 32 bit CPU with implementation of the ALU, registers, memory and Control Unit. Project was made to explore the content of my Computer Systems class. I used C++ and an Object Oriented Programming style to build each component and model the FDE cycle</samp>

## Components

<table>

- `Fetch-decode-execute cycle`: Control unit has fetch method to load memory and decode hexadecimal representation into operands and opcodes. These instructions are then executed by ALU and saved into registers

<tr>
<td width="33%"">
<samp>Arithmetic Logic Unit</samp>
</td>
<td width="66%">
<samp>Executes arithmetic and logical operations (NOT, AND, XOR, OR, BIT SHIFT). Used enums as opcode to alu operations</samp>
</td>
</tr>

<tr>
<td width="33%"">
<samp>Control Unit</samp>
</td>
<td width="66%">
<samp>Fetches instructions from memory, decodes, and directs ALU work. Uses registers to store values</samp>
</td>
</tr>

<tr>
<td width="33%"">
<samp>Adder</samp>
</td>
<td width="66%">
<samp>Uses a full adder device to perform addition and subtraction using carry in values. Immitated logic gates to carry and sum bits</samp>
</td>
</tr>
   
<tr>
<td width="20%"">
<samp>Register</samp>
</td>
<td width="80%">
<samp>Each register object is meant to be a chain of R/S flip flops. Designed getters and setters to describe the bistable elements</samp>
</td>
</tr>

<tr>
<td width="33%"">
<samp>Comparator</samp>
</td>
<td width="66%">
<samp>Uses ALU to subtract and compare two 32 bit values</samp>
</td>
</tr>
  
</table>


## Future Work

- Write instruction sets to generate Fibbonaci numbers and bubble sort algorithm
- Add a L1 and L2 cache system to simulate cache hits/misses
