#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "FighterCharacter.h"

#include "PlayerCharacter.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FActionAbility
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayAbility> Ability = nullptr;
};

UCLASS(config=Game)
class APlayerCharacter : public AFighterCharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Granted Gameplay Abilities */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	TArray<FActionAbility> GrantedAbilities;

public:
	APlayerCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for linked Ability on PressedAction*/
	void AbilityInputPressed(int32 AbilityId);

	/** Called for linked Ability on ReleasedAction*/
	void AbilityInputReleased(int32 AbilityId);
	
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

