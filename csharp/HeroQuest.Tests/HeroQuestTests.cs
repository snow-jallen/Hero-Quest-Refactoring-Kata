using FluentAssertions;

namespace HeroQuest.Tests;

public class HeroQuestTests
{
    private QuestData questData;

    public HeroQuestTests()
    {
        questData = new QuestData()
        {
            PlayerName = "Conan",
            PlayerHealth = 100,
            PlayerStrength = 20,
            PlayerMagic = 10,
            PlayerCraftingSkill = 10,
            ItemName = "Amulet of Strength",
            ItemKind = "Strength",
            ItemPower = 10,
        };
    }

    [Fact]
    void PlayerToString()
    {
        var result = HeroQuest.PlayerToString(questData.PlayerName,
                questData.PlayerHealth, questData.PlayerStrength, questData.PlayerMagic, questData.PlayerCraftingSkill);

        var expected = "Conan's Attributes:\nHealth: 100\nStrength: 20\nMagic: " +
                "10\nCrafting " +
                "Skill: 10\n";

        expected.Should().Be(result);
    }

    [Fact]
    void PlayerFallsDown()
    {
        questData.PlayerStrength = 3;
        HeroQuest.PlayerFallsDown(questData);
        questData.PlayerHealth.Should().Be(90);
    }

    [Fact]
    void PlayerFallsDownNoDamage()
    {
        HeroQuest.PlayerFallsDown(questData);
        questData.PlayerHealth.Should().Be(100);
    }

    [Fact]
    void ItemToString()
    {
        var result = HeroQuest.ItemToString(questData.ItemName, questData.ItemKind, questData.ItemPower);
        var expected = "Item: Amulet of Strength\nKind: Strength\nPower: 10\n";
        expected.Should().Be(result);
    }

    [Fact]
    void ItemReduceByUsage()
    {
        HeroQuest.ItemReduceByUsage(questData);
        questData.ItemPower.Should().Be(5);
    }

    [Fact]
    void ItemReduceByUsageToJunk()
    {
        questData.ItemPower = 1;
        HeroQuest.ItemReduceByUsage(questData);
        questData.ItemPower.Should().Be(0);
        questData.ItemKind.Should().Be("Junk");
    }

    [Fact]
    void ItemApplyEffectToPlayer()
    {
        HeroQuest.ItemApplyEffectToPlayer(questData);
        questData.PlayerStrength.Should().Be(30);
    }

    [Fact]
    void ItemApplyEffectToPlayerJunk()
    {
        questData.ItemKind = "Junk";
        HeroQuest.ItemApplyEffectToPlayer(questData);
        questData.PlayerStrength.Should().Be(20);
    }

    [Fact]
    void ItemRepair()
    {
        questData.ItemKind = "Junk";
        HeroQuest.ItemRepair(questData);
        questData.ItemPower.Should().Be(26);
    }
}
