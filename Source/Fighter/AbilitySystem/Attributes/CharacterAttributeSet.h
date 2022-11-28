#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)       	\
			GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
			GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)           	\
			GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)

UCLASS()
class FIGHTER_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health = 100.0f;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Health)	
};
