# Golomb
Implements generating of Golomb's codes.

The Golomb coding is a lossless data compression method using a family of data compression codes invented by Solomon W. Golomb.
Algorithm described on the Wikipedia (https://en.wikipedia.org/wiki/Golomb_coding) and contains some iterations:


    1. Fix the parameter M to an integer value.
    2. For N, the number to be encoded, find
        a) quotient = q = int[N/M]
        b) remainder = r = N modulo M
    3. Generate Codeword
        a) The Code format : <Quotient Code><Remainder Code>, where
        b) Quotient Code (in unary coding)
            b.1) Write a q-length string of 1 bits
            b.2) Write a 0 bit
        c) Remainder Code (in truncated binary encoding)
            c.1) If M is power of 2, code remainder as binary format. So log 2 ⁡ ( M ) {\displaystyle \log _{2}(M)} \log _{2}(M) bits are needed. (Rice code)
            c.2) If M is not a power of 2, set b = ⌈ log 2 ⁡ ( M ) ⌉ {\displaystyle b=\lceil \log _{2}(M)\rceil } b=\lceil \log _{2}(M)\rceil
                c.2.1) If r < 2 b − M {\displaystyle r<2^{b}-M} r<2^{b}-M code r as plain binary using b-1 bits.
                c.2.2) If r ≥ 2 b − M {\displaystyle r\geq 2^{b}-M} r\geq 2^{b}-M code the number r + 2 b − M {\displaystyle r+2^{b}-M} r+2^{b}-M in plain binary representation using b bits.


For example:

M = 10
N = 42

q = N / M = 42 / 10 = 4
r = N % M = 42 % 10 = 2

Unary code representation of q: 11110
Binary representation of r: 010
Result code word: 11110010
