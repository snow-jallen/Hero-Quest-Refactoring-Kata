#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include "quest.h"
#include <cmocka.h>

static void test_EmptyResultsWhenGivenEmptyList(void** state)
{
    assert_null(NULL);
}

static const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_EmptyResultsWhenGivenEmptyList),
};

int main(void)
{
    return cmocka_run_group_tests(tests, NULL, NULL);
}
