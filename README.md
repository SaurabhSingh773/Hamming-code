# Hamming-code in C
Hamming Code is an error-detecting and error-correcting code that was invented by Richard Hamming in 1950. It allows for detection and correction of single-bit errors in transmitted data, making it highly useful in digital communication and data storage systems.
Key Concepts
Redundant Bits: Hamming Code uses extra (redundant) bits inserted at specific positions in the data to ensure error detection and correction. These bits are added in such a way that allows for the identification and correction of single-bit errors.

Parity Check: The redundant bits are computed based on the parity (either even or odd) of specific bits in the data. Each redundant bit checks a unique combination of data bits. Parity can either be even parity (ensures an even number of 1's) or odd parity (ensures an odd number of 1's).

Code Word Structure: In Hamming Code, the positions of bits are numbered starting from 1, and powers of 2 (like 1, 2, 4, 8, etc.) are designated as redundant bit positions. The other positions are for data bits.

Error Detection and Correction: By performing parity checks, Hamming Code can detect which bit, if any, has been corrupted in transmission. A bitwise XOR operation across all redundant bits can pinpoint the position of the error. This approach enables single-bit error correction directly.

Working Steps for Hamming Code (7, 4)
For simplicity, let’s look at a basic Hamming Code (7, 4) example. Here, 4 data bits are encoded with 3 redundant bits, creating a 7-bit code word that can detect and correct single-bit errors.

Determine Redundant Bit Positions:

If you have data bits D1, D2, D3, and D4, the redundant bits are placed at R1, R2, and R4 (positions 1, 2, and 4).
This leaves the 7-bit code word as: R1, R2, D1, R4, D2, D3, D4.
Calculate Redundant Bits:

Each redundant bit covers a specific combination of data bits:
𝑅
1
R1: covers positions 1, 3, 5, 7.
𝑅
2
R2: covers positions 2, 3, 6, 7.
𝑅
4
R4: covers positions 4, 5, 6, 7.
Set Redundant Bits to Maintain Parity:

Calculate values for 
𝑅
1
R1, 
𝑅
2
R2, and 
𝑅
4
R4 to make each combination follow even (or odd) parity, based on the coding system used.
Error Detection and Correction:

During transmission, if a single bit error occurs, the parity bits will fail their checks, pointing out the exact location of the error.
Using the values of 
𝑅
1
R1, 
𝑅
2
R2, and 
𝑅
4
R4 together, the error position can be determined and corrected.
Example
Suppose we want to encode the data bits 1011:

Insert the data bits: D1=1, D2=0, D3=1, D4=1.
Assume initial positions for the code word: _ _ _ _ _ _ _, where R1, R2, and R4 are unknown.
Calculate the redundant bits R1, R2, R4 to ensure parity for each combination they check.
Form the final 7-bit code word with the calculated values.
Hamming Code is powerful due to its simplicity and efficiency, particularly for single-bit error correction. In systems where data reliability is critical, it remains a foundational tool.
