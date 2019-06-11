# Bitwise Examples

This document is an general overview of bitwise operators and how their used in
professional software development.

## Repository

This repository (`bitwise-operators`) contains supporting resources, including
working code samples and interview questions.

## Bitwise Operators Overview

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

### Using bitwise AND

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
0111 & 0001 -> 0110
```

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

Outside of those spaces, such as full-stack web-development, it's less likely to
employ bitwise operators in production code. In all domains, they pop up from
time to time, often as a means of tracking several options in a single number.

Here are some more specific domains where bitwise operators will help you do your job.

### Computer Architecture

CPUs support a particular vocabulary of low-level instructions called an
"instruction set."

[Instruction Set Architecture](https://en.wikipedia.org/wiki/Instruction_set_architecture)

Instruction sets support bitwise operations because CPU hardware is designed
operate on individual bits of data in arbitrary ways, typically within time and
space constraints.

If you're working in CPU architecture in any way, bitwise operations represent a
major part of your vocabulary for designing or improving computing hardware.

### Advanced Debugging

Debugging by stepping through source code is often the preferred debugging mode.
But when it's unavailable or insufficent, developers need to be able to
understand and debug the program in its target CPU assembly language.

Understanding the target instruction set and its assembly code requires
understanding bitwise operators.

If you're looking to enhance your debugging skills beyond source-level
debugging, bitwise operators will really help you understand the CPU instruction set.

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

### Using small amount of space

In web-development and higher level scripting languages, options are often
captured in more verbose formats, such as JSON.

However, in more constrained systems, it's desireable to have several options
tracked by a single integer. In the case of the example above, we're only using
half a byte (four bits!) to track four options and several possible option
combinations.

You can track as many options as there are bits in the underlying datatype.
On most architectures, this is 32-bits for `int`s and 8-bits for `char`s.

### Can expose different combinations of flags

Note how ONLINE_DEFAULTS is a bitwise combination of the relevant values.
Useful bitwise combinations can be exposed to API consumers or used in other logic.

### Using the & operator and masking to read bits

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

### Code Optimization

If you're looking to write really effecient, optimized, or specialized code for
a constrained system, bitwise operators can be employed.

The book
[Hacker's Delight](https://www.amazon.com/Hackers-Delight-2nd-Henry-Warren/dp/0321842685)
provides a ton of real-world patterns for working with a constrained system and,
more often than not, using bitwise operations to implement effecient code.

The book is really dense and is kind of impossible to "sit down and read." It's
a good reference book and covers a wide range of bitwise optimizations.

## Resources/Examples

### Real World Examples

- [Camera Sample Options](https://github.com/microsoft/xbox-live-api/blob/c8dc9f91858d7f7fdd0e4ac7ec5bdd4f865e1bef/InProgressSamples/Kits/ATGTK/FlyCamera.cpp#L61)

  Here this sample uses bitwise operators to use a single number to track a variety of options.

- [UWP Input Interfacing](https://github.com/microsoft/Xbox-ATG-Samples/blob/a733a3992a74c9a8f733851b53952edd7659bdce/UWPSamples/System/InputInterfacingUWP/InputInterfacingUWP.cpp#L45)

  Notice how this sample uses `&` to read which combination of buttons is currently being pressed.
