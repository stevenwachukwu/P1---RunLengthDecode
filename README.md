Program 1: Decoding a Compressed File

1 Goals of this Assignment
1. To identify a compiler and an IDE that will meet your needs for this course.
2. To write a program in C++.
3. To use file I/O in C++ (open, read a char, test for eof).
4. To use char input that does NOT skip whitespace.
5. To use an acceptable coding style: Please see the style sheet.
6. To understand and use a type cast.
2 File Compression
Most people now use rar or zip to compress files. These applications use a combination of
compression mechanisms, in sequence. This assignment and the next explore the
simplest compression scheme we have. Later this term we will implement a more complex
compression scheme.
2.1 Run-Length Compression
Run-length Compression is effective on text or binary files that have the same byte
repeated over and over. Think of a file containing a table of numbers: it has lots of
consecutive space characters, and may have a repeated filler character, such as a ‘.’ .
You will implement this simple kind of compression in Program 2. However, the algorithm
to decompress the file is easier, so I am asking you to do the decompression first.
Runs. In this scheme, any “run” of the same character (4 or more identical consecutive
bytes) is replaced by a triplet of bytes, consisting of
1. An escape character. We will use 0x7f, which is sometimes called “esc”. It is a non-
printing ASCII character.
2. The letter that has been repeated.
3. A 1-byte count of the number of repetitions.
In addition, any esc character, or run of them, that occurs in the input must also be
replaced by a triplet: esc esc count .
3 To do: Expand a Compressed File
I will give you a compressed file; your job is to restore it to the uncompressed
representation. The algorithm is a loop that reads chars one at a time until eof is
reached:
1. Read an input character named my_character (do not skip whitespace) from
compressed.txt and quit if end of file happens.
2. If my_character is NOT an escape character, output it to the console and to a
file: console_output.ext. Continue reading the next character in the loop.
3. If my_character IS an escape character, read two more chars: the first will be a
letter, the second is the count.
4. Cast the count from type char to type unsigned short int and use it to output
that many copies of the letter.
5. Continue reading the next character in the loop.
Please note: if you handle the end of file wrong, the last character of the output will be
wrong. You must check for eof immediately after reading a character, not before.
