# Bitwise Examples

This document is an general overview of bitwise operators and how their used in
professional software development.

## Repository

This repository (`bitwise-operators`) contains supporting resources, including
working code samples and interview questions.

## Contributing

Feel free to open an issue or pull request against this me/this repro with
requests for corrections, elaboration, or more examples.

## Bitwise Operators Overview

[Bitwise Operator Overview](./Overview.md)

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
- security/cryptogophy

Outside of those spaces, such as full-stack web-development, it's less likely to
employ bitwise operators in production code. In all domains, they pop up from
time to time, often as a means of tracking several options in a single number
(see Option Flags).

Here are some more specific domains where bitwise operators will be crucial to your job.

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
debugging, understand how bitwise operators work will really help you understand
the CPU instruction set.

### Options Flags

This particular application of bitwise operators is very common, especially in client SDKs.

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

### Security/Cryptography

https://en.wikipedia.org/wiki/XOR_cipher

## Real Examples

### Direct3D Initialization

If you're using the Direct3D graphics API

[D3D 11 Create Device Flag](https://docs.microsoft.com/en-us/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag)

If you're looking to use the D3D Graphics Library, you'll use bitwise
operators to set or unset Flags when creating a "device" object

### glClear mask

https://developer.mozilla.org/en-US/docs/Web/API/WebGLRenderingContext/clear
https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glClear.xml


https://docs.microsoft.com/en-us/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice
- [Camera Sample Options](https://github.com/microsoft/xbox-live-api/blob/c8dc9f91858d7f7fdd0e4ac7ec5bdd4f865e1bef/InProgressSamples/Kits/ATGTK/FlyCamera.cpp#L61)

  Here this sample uses bitwise operators to use a single number to track a variety of options.

- [UWP Input Interfacing](https://github.com/microsoft/Xbox-ATG-Samples/blob/a733a3992a74c9a8f733851b53952edd7659bdce/UWPSamples/System/InputInterfacingUWP/InputInterfacingUWP.cpp#L45)

  Notice how this sample uses `&` to read which combination of buttons is currently being pressed.

- [D3D 11 Create Device Flag](https://docs.microsoft.com/en-us/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag)

  If you're looking to use the D3D Graphics Library, you'll use bitwise
  operators to set or unset Flags when creating a "device" object

https://docs.microsoft.com/en-us/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice

- Project - building an disassembler

https://en.wikipedia.org/wiki/Single-precision_floating-point_format

HRESULTs & Severity
https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/0c0bcf55-277e-4120-b5dc-f6115fc8dc38

https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/0642cb2f-2075-4469-918c-4441e69c548a


Books
https://www.amazon.com/Code-Language-Computer-Hardware-Software/dp/0735611319/ref=tmm_pap_swatch_0?_encoding=UTF8&qid=&sr=