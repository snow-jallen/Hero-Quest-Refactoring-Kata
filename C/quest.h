
char* playerName;
int playerHealth;
int playerStrength;
int playerMagic;
int playerCraftingSkill;

char* amuletItemName;
char* amuletItemKind;
int amuletItemPower;

void playerToString(char* result, //
                    const char* playerName,
                    int playerHealth,
                    int playerStrength,
                    int playerMagic,
                    int playerCraftingSkill);

void playerFallsDown(int* playerHealth, int* playerStrength, int* playerMagic);

void itemToString(char* result, //
                  const char* itemName,
                  const char* itemKind,
                  int itemPower);

void itemReduceByUsage(char* itemKind, int* itemPower);

void itemApplyEffectToPlayer(char* itemName,
                             char* itemKind,
                             int itemPower,
                             int* playerHealth,
                             int* playerStrength,
                             int* playerMagic);

void itemRepair(int* itemPower, int playerCraftingSkill);
