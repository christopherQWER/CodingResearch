# Golomb Code
Implements generating of Golomb's codes.

The Golomb coding is a lossless data compression method using a family of data compression codes invented by Solomon W. Golomb.
Algorithm described on the Wikipedia (https://en.wikipedia.org/wiki/Golomb_coding) and contains some iterations:


1. Fix the parameter M to an integer value.
2. For N, the number to be encoded, find
    1. quotient = q = int[N/M]
    2. remainder = r = N modulo M
3. Generate Codeword
    1. The Code format : <Quotient Code><Remainder Code>, where
    2. Quotient Code (in unary coding)
        1. Write a q-length string of 1 bits
        2. Write a 0 bit
    3. Remainder Code (in truncated binary encoding)
        1. If M is power of 2, code remainder as binary format. So log 2 ⁡ ( M ) {\displaystyle \log _{2}(M)} \log _{2}(M) bits are needed. (Rice code)
        2. If M is not a power of 2, set b = ⌈ log 2 ⁡ ( M ) ⌉ {\displaystyle b=\lceil \log _{2}(M)\rceil } b=\lceil \log _{2}(M)\rceil
            1. If r < 2 b − M {\displaystyle r<2^{b}-M} r<2^{b}-M code r as plain binary using b-1 bits.
            2. If r ≥ 2 b − M {\displaystyle r\geq 2^{b}-M} r\geq 2^{b}-M code the number r + 2 b − M {\displaystyle r+2^{b}-M} r+2^{b}-M in plain binary representation using b bits.


For example:    

M = 10    
N = 42    

q = N / M = 42 / 10 = 4    
r = N % M = 42 % 10 = 2    

Unary code representation of q: 11110    
Binary representation of r: 010    
Result code word: 11110010    
