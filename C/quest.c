#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "quest.h"

playerName = "Conan";
playerHealth = 100;
playerStrength = 20;
playerMagic = 10;
playerCraftingSkill = 10;

void playerToString(char* result, //
                    const char* playerName,
                    int playerHealth,
                    int playerStrength,
                    int playerMagic,
                    int playerCraftingSkill)
{
    sprintf(result,
            "%s's Attributes:\nHealth: %d\nStrength: %d\nMagic: %d\nCrafting "
            "Skill: %d\n",
            playerName, playerHealth, playerStrength, playerMagic, playerCraftingSkill);
}

void playerFallsDown(int* playerHealth, int* playerStrength, int* playerMagic)
{
    printf("Player drops off a cliff.\n");

    if (*playerStrength < 5) {
        *playerHealth -= 10;
        printf("Player's strength is too small. Health decreases by 10.\n");
    }
}

amuletItemName = "Amulet of Strength";
amuletItemKind = "Strength";
amuletItemPower = 10;

void itemToString(char* result, //
                  const char* itemName,
                  const char* itemKind,
                  int itemPower)
{
    sprintf(result, "Item: %s\nKind: %s\nPower: %d\n", itemName, itemKind, itemPower);
}

void itemReduceByUsage(char* itemKind, int* itemPower)
{
    printf("Using the item with kind '%s' and power %d\n", itemKind, *itemPower);

    *itemPower /= 2;

    if (*itemPower == 0) {
        strcpy(itemKind, "Junk");
    }
}

void itemApplyEffectToPlayer(char* itemName,
                             char* itemKind,
                             int itemPower,
                             int* playerHealth,
                             int* playerStrength,
                             int* playerMagic)
{
    printf("Applying the effect of %s (%s):\n", itemName, itemKind);

    if (strcmp(itemKind, "Health") == 0) {
        *playerHealth += itemPower;
    }
    else if (strcmp(itemKind, "Strength") == 0) {
        *playerStrength += itemPower;
    }
    else if (strcmp(itemKind, "Magic") == 0) {
        *playerMagic += itemPower;
    }
    else {
        // ignore unknown item kind
    }
}

void itemRepair(int* itemPower, int playerCraftingSkill)
{
    printf("Using the repair skill to fix the item:\n");

    int repairAmount = rand() % (playerCraftingSkill * 2) + 1;

    *itemPower += repairAmount;

    printf("Repaired the item by %d points. Item's Durability: %d\n", repairAmount, *itemPower);
}
