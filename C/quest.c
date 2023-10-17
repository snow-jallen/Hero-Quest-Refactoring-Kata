#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char playerName[] = "Conan";
int playerHealth = 100;
int playerStrength = 20;
int playerMagic = 10;
int playerCraftingSkill = 10;

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

int f4()
{
    char playerAttributesString[256];

    playerToString(playerAttributesString, playerName, playerHealth,
                   playerStrength, playerMagic, playerCraftingSkill);

    printf("%s", playerAttributesString);

    return 0;
}

void playerFallsDown(int* playerHealth, int* playerStrength, int* playerMagic)
{
    printf("Player drops off a cliff.\n");

    if (*playerStrength < 5) {
        *playerHealth -= 10;
        printf("Player's strength is too small. Health decreases by 10.\n");
    }
}

int f2()
{
    playerStrength = 3; // Assuming a low strength value

    playerFallsDown(&playerHealth, &playerStrength, &playerMagic);

    return 0;
}

char amuletItemName[] = "Amulet of Strength";
char amuletItemKind[] = "Strength";
int amuletItemPower = 10;

void itemToString(char* result, //
                  const char* itemName,
                  const char* itemKind,
                  int itemPower)
{
    sprintf(result, "Item: %s\nKind: %s\nPower: %d\n", itemName, itemKind, itemPower);
}

int f5()
{
    char itemAttributesString[256]; // Adjust the size as needed

    itemToString(itemAttributesString, amuletItemName, amuletItemKind, amuletItemPower);

    printf("%s", itemAttributesString);

    return 0;
}

void itemReduceByUsage(char* itemKind, int* itemPower)
{
    printf("Using the item with kind '%s' and power %d\n", itemKind, *itemPower);

    *itemPower /= 2;

    if (*itemPower == 0) {
        strcpy(itemKind, "Junk");
    }
}

int f3()
{
    itemReduceByUsage(amuletItemKind, &amuletItemPower);

    return 0;
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

int f1()
{
    itemApplyEffectToPlayer(amuletItemName, amuletItemKind, amuletItemPower,
                            &playerHealth, &playerStrength, &playerMagic);

    return 0;
}

void itemRepair(int* itemPower, int playerCraftingSkill)
{
    printf("Using the repair skill to fix the item:\n");

    int repairAmount = rand() % (playerCraftingSkill * 2) + 1;

    *itemPower += repairAmount;

    printf("Repaired the item by %d points. Item's Durability: %d\n", repairAmount, *itemPower);
}

int f8()
{
    srand((unsigned)time(NULL));

    itemRepair(&amuletItemPower, playerCraftingSkill);

    return 0;
}
