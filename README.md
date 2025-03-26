
## Documentation

### LZW Compression Algorithm Implementation in C


A straightforward C code of the Lempel-Ziv-Welch (LZW) compression algorithm in C. LZW is a popular lossless data compression method that substitutes repeated data occurrences with references to a single instance.

Concepts

- LZW Compression: The algorithm constructs a dictionary of input sequences and replaces these sequences with shorter codes, thereby effectively minimizing the data size.
- Dictionary Initialization: The process begins with a predefined dictionary that includes all single-character strings.
- Dynamic Dictionary Expansion: New sequences are added to the dictionary as they are encountered.
- Code Representation: Each unique sequence is assigned a code, which is produced during the compression process.

The code is organized into several essential functions:

- initializeTable: Sets up the dictionary with entries for single characters.
- findCode: Looks for a string in the dictionary and returns its associated code.
- addEntry: Inserts a new string entry into the dictionary with a unique code.
- compress: Executes the LZW compression algorithm on the provided input string.
- freeTable: Releases the memory allocated for the dictionary entries.
- main: Serves as the program's entry point, initializing the dictionary, compressing a sample input, and managing resource cleanup.
