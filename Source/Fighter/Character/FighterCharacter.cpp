#include "FighterCharacter.h"

AFighterCharacter::AFighterCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UFighterAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("AttributeSet"));	
}
