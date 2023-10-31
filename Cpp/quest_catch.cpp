#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "quest.h"

const char* testPlayerName = "Conan";
int testPlayerHealth = 100;
int testPlayerStrength = 20;
int testPlayerMagic = 10;
int testPlayerCraftingSkill = 10;

const char* testItemName = "Amulet of Strength";
char* testItemKind = "Strength";
int testItemPower = 10;

/* Mock rand */
int rand(void)
{
    return 5;
}

TEST_CASE("Quest")
{
    SECTION("playerToString")
    {
        char result[256];
        playerToString(result, testPlayerName, testPlayerHealth, testPlayerStrength,
                       testPlayerMagic, testPlayerCraftingSkill);

        const char* expected =
            "Conan's Attributes:\nHealth: 100\nStrength: 20\nMagic: "
            "10\nCrafting "
            "Skill: 10\n";
        REQUIRE(result == expected);
    }

    SECTION("playerFallsDown")
    {
        testPlayerStrength = 3;
        playerFallsDown(&testPlayerHealth, &testPlayerStrength);

        REQUIRE(testPlayerHealth == 90);
        testPlayerStrength = 20; // reset
        testPlayerHealth = 100;  // reset
    }

    SECTION("playerFallsDownNoDamage")
    {
        playerFallsDown(&testPlayerHealth, &testPlayerStrength);

        REQUIRE(testPlayerHealth == 100);
    }

    SECTION("itemToString")
    {
        char result[256];
        itemToString(result, testItemName, testItemKind, testItemPower);

        const char* expected =
            "Item: Amulet of Strength\nKind: Strength\nPower: 10\n";
        REQUIRE(result == expected);
    }

    SECTION("itemReduceByUsage")
    {
        itemReduceByUsage(testItemKind, &testItemPower);

        REQUIRE(testItemPower == 5);
        REQUIRE(testItemKind == "Strength");
        testItemPower = 10; // reset
    }

    SECTION("itemReduceByUsageToJunk")
    {
        testItemPower = 1;
        char itemKind[10] = "Strength";
        itemReduceByUsage(itemKind, &testItemPower);

        REQUIRE(testItemPower == 0);
        REQUIRE(itemKind == "Junk");
        testItemPower = 10; // reset
    }

    SECTION("itemApplyEffectToPlayer")
    {
        itemApplyEffectToPlayer(testItemName, testItemKind, testItemPower, &testPlayerHealth,
                                &testPlayerStrength, &testPlayerMagic);

        REQUIRE(testPlayerStrength == 30);
        testPlayerStrength = 20; // reset
    }

    SECTION("itemApplyEffectToPlayerJunk")
    {
        itemApplyEffectToPlayer(testItemName, "Junk", testItemPower, &testPlayerHealth,
                                &testPlayerStrength, &testPlayerMagic);

        REQUIRE(testPlayerStrength == 20);
    }

    SECTION("itemRepair")
    {
        // srand(5); // set a specific seed for rand() to control the random value
        itemRepair(&testItemPower, testPlayerCraftingSkill);

        REQUIRE(testItemPower == 16);
        testItemPower = 10; // reset
    }
}
