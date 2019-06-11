# Bitwise Examples

This document is an general overview of bitwise operators and how their used in
professional software development.

## Repository

This repository (`bitwise-operators`) contains supporting resources, including
working code samples and interview questions.

## Bitwise Operators Overview

Existing documents give an in-depth overview of bitwise operations:

https://en.wikipedia.org/wiki/Bitwise_operation
https://en.wikipedia.org/wiki/Bit_manipulation

Most often, we're talking about the following operators in C/C++:

`&` - bitwise exclusive AND
`|` - bitwise inclusive OR

And OR also has a "exclusive" cousin--XOR:
`^` - bitwise exclusive XOR

Less frequently, but still common, are shifting operations:
`<<` - bitwise shift left
`>>` - bitwise shift right

### Using bitwise AND

The bitwise AND `&` takes two numbers and returns the *intersection* of their bits.


### Using bitwise inclusive OR

The inclusive bitwise OR `|` operator takes two numbers and returns the *union*
of their bits. Often, developers use `|` in order to say "make sure the
specified bits are turned on." This is good for setting options that are tracked
as bits in a number.

Bitwise are harder to intuit if you don't look at them in either binary (base 2)
or, hexadecamal (base 16):

```c
4 | 2 -> 6
0100 | 0010 -> 0110
```

Sometimes inclusive OR doesn't result in a new value. Notice that if a bit is
already set, inclusive OR keeps it set:

```c
5 | 1 -> 5
0101 | 0001 -> 0101
```

```c
5 | 7 | 4 -> 7
0101 | 0111 | 0100 -> 0111
```

Note that you can't use bitwise OR to turn OFF bits:

```c
4 | 0 -> 4
0100 | 0000 -> 0100
```


## Authentic uses of bitwise operators

Bitwise operators allow developers to evaluate and change the individual bits
that make up a number.

There are a few reasons developers might need to use bitwise operators.
Consequently, you should expect that they will show up from time to time in
coding interviews, especially when a position requires working in low-level
platform code.

Most of the time it has to with getting the most out of a limited amount of
memory or working closely with the CPU.

Expect to use bitwise operators regularly if you are working in the following areas:

- languages/compilers
- embedded systems
- computer hardware or CPU design
- kernel or device driver development
- developer APIs that are exposed in C
- debugging assembly

### Computer Architecture

CPUs support a particular vocabulary of low-level instructions called an
"instruction set."

Instruction sets support bitwise operations because CPU hardware is designed operate on individual bits of data in arbitrary ways, typically within time and space constraints.

### Advanced Debugging

Debugging by stepping through source code is often the preferred debugging mode.
But when it's unavailable or insufficent, developers need to be able to
understand and debug the program in its target CPU assembly language.

Understanding the target instruction set and its assembly code requires
understanding bitwise operators.

If you're looking to enhance your debugging skills beyond source-level
debugging, bitwise operators will help you understand the CPU instruction set.

### Options Flags

Bitwise operators are often used to track several non-exclusive boolean
properties only using a single integer.

This pattern is a great way to expose "options" or "flags" to consumers of a function.
This particular version is

Consider the following enum and function signature:

```c
typedef enum _SessionOptions
{
    NONE = 0x0,                     // 0000
    LEADERBOARD_SUPPORT = 0x1,      // 0001
    MULTIPLAYER_SUPPORT = 0x2,      // 0010
    ONLINE_PRESENCE_SUPPORT = 0x4,  // 0100
    CHAT_SUPPORT = 0x8,             // 1000
    ONLINE_DEFAULTS =               // 0111
        LEADERBOARD_SUPPORT |
        MULTIPLAYER_SUPPORT |
        ONLINE_PRESENCE_SUPPORT

} SessionOptions;

void startGameSession(char * name, int sessionOptions);
```

Consumers of this API can use bitwise operators to assign a value to the
`sessionOptions` argument.

Here are some advantages from using this approach:

#### Small amount of space

Several options are tracked by a single integer. In the case of the example
above, we're only using half a byte (four bits!) to track several possible
option combinations.

You can track as many options as there are bits in the underlying datatype.
On most architectures, this is 32-bits for `int`s and 8-bits for `char`s.

#### Can "alias" different combinations of flags

Note how ONLINE_DEFAULTS is bitwise combination of the relevant values.
Useful bitwise combinations can be exposed to API consumers or used in other logic.

#### Using the & operator and masking to read bits

Consider how this implementation of `startGameSession` evaluates `sessionOptions`:

```c
void startGameSession(char *name, int sessionOptions)
{
    printf("\nSession %s started with the following options:\n", name);
    if (sessionOptions & LEADERBOARD_SUPPORT)
    {
        printf("\tLeaderboard Support\n");
    }

    if (sessionOptions & MULTIPLAYER_SUPPORT)
    {
        printf("\tMultiplayer Support\n");
    }

    if (sessionOptions & ONLINE_PRESENCE_SUPPORT)
    {
        printf("\tOnline Presence Support\n");
    }

    if (sessionOptions & CHAT_SUPPORT)
    {
        printf("\tOnline Chat Support\n");
    }
}
```

Notice how the `&` operator is used to test if certain bits are "turned on."
This is called Masking.

## Resources/Examples

### Real World Examples

Check out this sample from Microsoft's xbox-live-api repo:
https://github.com/microsoft/xbox-live-api/blob/c8dc9f91858d7f7fdd0e4ac7ec5bdd4f865e1bef/InProgressSamples/Kits/ATGTK/FlyCamera.cpp#L61

https://github.com/microsoft/HoloJS/blob/508f2b940995e2d3fc5eb6a2064e3d1712b5c86b/windows/src/uwp-component/file-handle-access.h#L16

https://github.com/microsoft/Xbox-ATG-Samples/blob/a733a3992a74c9a8f733851b53952edd7659bdce/UWPSamples/System/InputInterfacingUWP/InputInterfacingUWP.cpp#L45

### Wikipedia

https://en.wikipedia.org/wiki/Bitwise_operation
https://en.wikipedia.org/wiki/Bitwise_operations_in_C

### Books
#### K&R C
#### Hacker's Delight
