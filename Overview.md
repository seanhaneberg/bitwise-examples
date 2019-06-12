# Bitwise Operators Overview

Existing documents give an in-depth overview of bitwise operations:

- [Bitwise operation](https://en.wikipedia.org/wiki/Bitwise_operation)
- [Bit manipulation](https://en.wikipedia.org/wiki/Bit_manipulation)

Most often, we're talking about the following operators in C/C++:

- `&` - bitwise exclusive AND
- `|` - bitwise inclusive OR

And OR also has a "exclusive" cousin--XOR:

- `^` - bitwise exclusive XOR

Less frequently, but still common, are shifting operations:

- `<<` - bitwise shift left
- `>>` - bitwise shift right

## Using bitwise AND

The bitwise AND `&` takes two numbers and returns the *intersection* of their bits.
Often, developers use `&` in order to say "give me *only* certain bits" which allows for turning off bits or reading if a bit is on or off.

Here's an example of using `&` to 'read' the value of the first bit:

```c
0111 & 0001 -> 0001
```

```c
0110 & 0001 -> 0000
```

This example reads the third bit:

```c
0110 & 0100 -> 0100
```

This technique is called bit masking and can be applied to multiple bits. This
example filters out the top two bits and includes the bottom two bits:

```c
0110 & 0011 -> 0010
```

You can use `&` to turn off specific bits by including all the bits *except* the
bits you want to turn off. This example turns off the first bit:

```c
0111 & 1110 -> 0110
```

Often, developers use the result of a bitwise AND operation in an conditional
expression. When the result of a bitwise AND is 0 (0000), it indicates that the
specified bits are not present and will be evaluated as `false` in conditional expressions.

Similarly, any non-zero result of a bitwise AND indidcates that the specified bits ARE present. Any non-zero value gets evaluated as `true` in a conditional expressions.

The examples and discussion around setting and checking bit flags illustrate this.

### Using bitwise inclusive OR

The inclusive bitwise OR `|` operator takes two numbers and returns the *union*
of their bits. Often, developers use `|` in order to say "make sure the
specified bits are turned on." This is good for setting options that are tracked
as bits in a number.

```c
0100 | 0010 -> 0110
```

Sometimes inclusive OR doesn't result in a new value. Notice that if a bit is
already set, inclusive OR keeps it set:

```c
0101 | 0001 -> 0101
```

```c
0101 | 0111 | 0100 -> 0111
```

Note that you can't use bitwise OR to turn OFF bits:

```c
0100 | 0000 -> 0100
```

### Using bitwise exclusive XOR

The exlcusive XOR `^` operator takes two numbers and returns the bits that are only set in exactly one of the numbers.

- [Exclusive OR](https://en.wikipedia.org/wiki/Exclusive_or)
- [XOR Cypher](https://en.wikipedia.org/wiki/XOR_cipher)

### Using bitwise shifting

- [Logical shift](https://en.wikipedia.org/wiki/Logical_shift)
