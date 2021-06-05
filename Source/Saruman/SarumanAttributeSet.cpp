// Fill out your copyright notice in the Description page of Project Settings.


#include "SarumanAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

USarumanAttributeSet::USarumanAttributeSet()
{
}

void USarumanAttributeSet::GetLifetimeReplicatedProps(::TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(USarumanAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(USarumanAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(USarumanAttributeSet, Damage, COND_None, REPNOTIFY_Always);
}

void USarumanAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(USarumanAttributeSet, Health, OldHealth);
}

void USarumanAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(USarumanAttributeSet, MaxHealth, OldMaxHealth);
}

void USarumanAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(USarumanAttributeSet, Damage, OldDamage);
}

void USarumanAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{    
    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        const float dmg = GetDamage();
        SetDamage(0.0f);

        const float health = GetHealth() - dmg;
        const float newHealth = FMath::Clamp(health, 0.0f, GetMaxHealth());
        SetHealth(newHealth);
        
        if(GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s damage:%f newHealth:%f"), *Data.Target.GetOwner()->GetName(), dmg,  newHealth));
    }
}
