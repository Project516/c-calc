/*
 * Tests for the calculator math and dispatch logic.
 *
 * This is a self-contained test runner: it asserts no conditional macros or
 * external harness. Build with `make test`, which compiles src/calc.c,
 * src/input.c and src/logic.c into objects, links this runner against them,
 * and runs it. Every failed assertion increments a counter and is reported
 * at the end; the process exits non-zero if anything failed.
 *
 * main.c is intentionally excluded so these tests run without prompting
 * for user input.
 */
#include <stdio.h>
#include <string.h>
#include "calc.h"
#include "logic.h"

static int g_tests_run = 0;
static int g_tests_failed = 0;

/* capture the final lines of output from the divisions that print an error
 * to stdout, so we can assert the message is emitted on its own line. */
static void check(const char *name, int condition)
{
    g_tests_run++;
    if (condition)
    {
        printf("  ok  - %s\n", name);
    }
    else
    {
        g_tests_failed++;
        printf("FAIL  - %s\n", name);
    }
}

static void test_add(void)
{
    printf("add\n");
    check("2 + 3 == 5", add(2, 3) == 5);
    check("-1 + 1 == 0", add(-1, 1) == 0);
    check("0.25 + 0.25 == 0.5", add(0.25, 0.25) == 0.5);
}

static void test_subtract(void)
{
    printf("subtract\n");
    check("5 - 3 == 2", subtract(5, 3) == 2);
    check("3 - 5 == -2", subtract(3, 5) == -2);
    check("1.5 - 0.5 == 1", subtract(1.5, 0.5) == 1);
}

static void test_multiply(void)
{
    printf("multiply\n");
    check("4 * 5 == 20", multiply(4, 5) == 20);
    check("0 * 99 == 0", multiply(0, 99) == 0);
    check("-2 * 3 == -6", multiply(-2, 3) == -6);
}

static void test_divide(void)
{
    printf("divide\n");
    check("10 / 2 == 5", divide(10, 2) == 5);
    check("1 / 4 == 0.25", divide(1, 4) == 0.25);
    /* divide-by-zero is defined to return 0 instead of crashing */
    check("10 / 0 == 0", divide(10, 0) == 0);
}

static void test_calculate_dispatch(void)
{
    printf("calculate (dispatch)\n");
    check("calculate(1, '+', 1) == 2", calculate(1, '+', 1) == 2);
    check("calculate(4, '-', 1) == 3", calculate(4, '-', 1) == 3);
    check("calculate(6, '*', 7) == 42", calculate(6, '*', 7) == 42);
    check("calculate(20, '/', 4) == 5", calculate(20, '/', 4) == 5);
    check("calculate(10, '%', 3) == 1", calculate(10, '%', 3) == 1);
    check("calculate(10, '?', 3) == -1", calculate(10, '?', 3) == -1);
}

int main(void)
{
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_calculate_dispatch();

    printf("\n%d tests, %d failures\n", g_tests_run, g_tests_failed);
    return g_tests_failed == 0 ? 0 : 1;
}
