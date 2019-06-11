#include <stdio.h>

typedef enum _TriangleType
{
    INVALID = 0x0,     // 0000
    ISOSCELES = 0x1,   // 0001
    EQUILATERAL = 0x2, // 0010
    SCALENE = 0x4,     // 0100
} TriangleType;

TriangleType getTriangleType(int side_a, int side_b, int side_c)
{
    TriangleType type = INVALID;

    // Transitive Property doesn't work for comparing equality for any two sides.
    if (side_a == side_b ||
        side_a == side_c ||
        side_b == side_c)
    {
        type |= ISOSCELES;

        // Transitive Property means that you don't need to compare sides A and C
        if (side_a == side_b &&
            side_b == side_c)
        {
            type |= EQUILATERAL;
        }
    }
    else
    {
        type |= SCALENE;
    }

    return type;
}

void printTriangleType(TriangleType type)
{
    if (type == INVALID)
    {
        printf("INVALID TRIANGLE TYPE!\n");
        return;
    }

    if (type & ISOSCELES)
    {
        printf("Triangle is isosceles");
        if (type & EQUILATERAL)
        {
            printf(" and equilateral.\n");
        }
        else
        {
            printf(".\n");
        }
    }
    else if (type & SCALENE)
    {
        printf("Triangle is scalene.\n");
    }
    else
    {
        printf("Unexpected triangle type!\n");
    }
}

// Test code below.

void triangleTypeTests()
{
    int a;
    int b;
    int c;
    TriangleType ret;
    TriangleType expected;

    // Scalene
    a = 10;
    b = 11;
    c = 13;
    expected = SCALENE;
    ret = getTriangleType(a, b, c);
    if (ret != expected)
    {
        printf("Unexpected Test Result!");
    }

    printTriangleType(ret);

    // Isosceles
    a = 10;
    b = 10;
    c = 13;
    expected = ISOSCELES;
    ret = getTriangleType(a, b, c);
    if (ret != expected)
    {
        printf("Unexpected Test Result!");
    }

    printTriangleType(ret);

    // Equilateral
    a = 10;
    b = 10;
    c = 10;
    expected = EQUILATERAL | ISOSCELES;
    ret = getTriangleType(a, b, c);
    if (ret != expected)
    {
        printf("Unexpected Test Result!");
    }

    printTriangleType(ret);
}

int main()
{
    triangleTypeTests();
    return 0;
}
