#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("Sample")
{
    SECTION("sample section")
    {
        REQUIRE(true == false);
    }
}
