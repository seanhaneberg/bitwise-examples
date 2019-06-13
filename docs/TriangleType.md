# TriangleType

"TriangleType" is an interview question that I was asked during my coding
interview at Microsoft in 2004. I've also used it sometimes myself during
interviews and interview coaching.

There are lots of variations on this question, with most of them going in to
considerable more detail in analyzing and classifying the triangle.

It's designed to probe:

- How comfortable is the candidate with C syntax?

## Setting the Context

One of the things I love about this question is its flexibility. The initial
solution may be more than enough for a candidate who isn't very familiar with
using bitwise operators. More senior candidates ought to be able to write
solutions that consume more of the data or to perform additional analysis and
output regarding the triangle.

### Entry Level Candidates

Entry-level candidates with limited experience in C/C++ bitwise space will be
able to demonstrate their ability to:

- Identify and candidly discuss experience/skill level in C.

- Work with the interviewer to fill in any gaps in the candidate's knowledge
  (essentially using `|` and `&` operators).

- Implement some basic if/else logic, discussing the effectiveness and relative
  pros and cons of different solutions.

Whatever their skill level in C, they ought to be able to make progress on a
solution if not complete it. Candidates ought to walk out of the interview
feeling that their knowlege of bitwise operators is more complete for having
applied it.

## Question

```c
typedef enum _TriangleType
{
    INVALID = 0x0,     // 0000
    ISOSCELES = 0x1,   // 0001
    EQUILATERAL = 0x2, // 0010
    SCALENE = 0x4,     // 0100
} TriangleType;

TriangleType getTriangleType(int side_a, int side_b, int side_c);
```
