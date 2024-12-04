namespace HeroQuest;

public class HeroQuest
{
    public static string PlayerToString(String playerName, int playerHealth, int playerStrength, int playerMagic, int playerCraftingSkill)
    {
        return string.Format("{0}'s Attributes:\nHealth: {1}\nStrength: {2}\nMagic: {3}\nCrafting Skill: {4}\n",
                playerName, playerHealth, playerStrength, playerMagic, playerCraftingSkill);
    }

    public static void PlayerFallsDown(QuestData questData)
    {
        Console.WriteLine("Player drops off a cliff.");

        if (questData.PlayerStrength < 5)
        {
            questData.PlayerHealth = questData.PlayerHealth - 10;
            Console.WriteLine("Player's strength is too small. Health decreases by 10.");
        }
    }

    public static string ItemToString(String itemName, String itemKind, int itemPower)
    {
        return string.Format("Item: {0}\nKind: {1}\nPower: {2}\n", itemName, itemKind, itemPower);
    }

    public static void ItemReduceByUsage(QuestData questData)
    {
        Console.WriteLine(string.Format("Using the item with kind '%s' and power %d", questData.ItemKind, questData.ItemPower));

        questData.ItemPower = questData.ItemPower / 2;

        if (questData.ItemPower == 0)
        {
            questData.ItemKind = "Junk";
        }

    }

    public static void ItemApplyEffectToPlayer(QuestData data)
    {
        Console.WriteLine(string.Format("Applying the effect of %s (%s):", data.ItemName, data.ItemKind));

        if (data.ItemKind == "Health")
        {
            data.PlayerHealth = data.PlayerHealth + data.ItemPower;
        }
        else if (data.ItemKind == "Strength")
        {
            data.PlayerStrength = data.PlayerStrength + data.ItemPower;
        }
        else if (data.ItemKind == "Magic")
        {
            data.PlayerMagic = data.PlayerMagic + data.ItemPower;
        }
        else
        {
            // ignore unknown item kind
        }
    }

    public static void ItemRepair(QuestData questData)
    {
        Console.WriteLine("Using the repair skill to fix the item:");

        int repairAmount = -5 + ((questData.PlayerCraftingSkill * 2) + 1);

        questData.ItemPower = questData.ItemPower + repairAmount;

        Console.WriteLine(string.Format("Repaired the item by %d points. Item's Durability: %d", repairAmount, questData.ItemPower));
    }
}
