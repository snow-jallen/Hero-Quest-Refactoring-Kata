#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include "quest.h"
#include <cmocka.h>

const char* playerName = "Conan";
int playerHealth = 100;
int playerStrength = 20;
int playerMagic = 10;
int playerCraftingSkill = 10;

const char* amuletItemName = "Amulet of Strength";
const char* amuletItemKind = "Strength";
int amuletItemPower = 10;

static void test_playerToString(void** state)
{
    (void)state;

    char result[256];
    playerToString(result, playerName, playerHealth, playerStrength,
                   playerMagic, playerCraftingSkill);

    const char* expected =
        "Conan's Attributes:\nHealth: 100\nStrength: 20\nMagic: 10\nCrafting "
        "Skill: 10\n";
    assert_string_equal(result, expected);
}

static void test_playerFallsDown(void** state)
{
    (void)state;

    playerStrength = 3;
    playerFallsDown(&playerHealth, &playerStrength, &playerMagic);

    assert_int_equal(playerHealth, 90);
    playerStrength = 20; // reset
    playerHealth = 100;  // reset
}

static void test_itemToString(void** state)
{
    (void)state;

    char result[256];
    itemToString(result, amuletItemName, amuletItemKind, amuletItemPower);

    const char* expected =
        "Item: Amulet of Strength\nKind: Strength\nPower: 10\n";
    assert_string_equal(result, expected);
}

static void test_itemReduceByUsage(void** state)
{
    (void)state;

    itemReduceByUsage(amuletItemKind, &amuletItemPower);

    assert_int_equal(amuletItemPower, 5);
    assert_string_equal(amuletItemKind, "Strength");
    amuletItemPower = 10; // reset
}

static void test_itemApplyEffectToPlayer(void** state)
{
    (void)state;

    itemApplyEffectToPlayer(amuletItemName, amuletItemKind, amuletItemPower,
                            &playerHealth, &playerStrength, &playerMagic);

    assert_int_equal(playerStrength, 30);
    playerStrength = 20; // reset
}

static void test_itemRepair(void** state)
{
    (void)state;

    srand(5); // set a specific seed for rand() to control the random value
    itemRepair(&amuletItemPower, playerCraftingSkill);

    assert_int_equal(amuletItemPower, 15);
    amuletItemPower = 10; // reset
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_playerToString),
        cmocka_unit_test(test_playerFallsDown),
        cmocka_unit_test(test_itemToString),
        cmocka_unit_test(test_itemReduceByUsage),
        cmocka_unit_test(test_itemApplyEffectToPlayer),
        cmocka_unit_test(test_itemRepair),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
