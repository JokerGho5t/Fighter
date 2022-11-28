#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Fighter/AbilitySystem/FighterAbilitySystemComponent.h"
#include "Fighter/AbilitySystem/Attributes/CharacterAttributeSet.h"
#include "GameFramework/Character.h"

#include "FighterCharacter.generated.h"

UCLASS()
class FIGHTER_API AFighterCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:
	
	UPROPERTY()
	UFighterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UCharacterAttributeSet* AttributeSet;

public:

	AFighterCharacter();
	
	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return  AbilitySystemComponent; }
};