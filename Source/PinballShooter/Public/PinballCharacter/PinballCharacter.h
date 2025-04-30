#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "PinballCharacter.generated.h"

class USphereComponent;
class UPinballInputConfig;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/**
* Defines actions the main type of player pawn can perform.
*/
USTRUCT()
struct FPinballCharacterInputActions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> Move;
};

/**
* Defines the main type of player character and its abilities.
*/
UCLASS()
class PINBALLSHOOTER_API APinballCharacter : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "PinballInput")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "PinballInput", meta = (ShowOnlyInnerProperties))
	FPinballCharacterInputActions InputActions;

	UPROPERTY(EditDefaultsOnly, Category = "PinballInput")
	float MovementInputScale;

	UPROPERTY(EditDefaultsOnly, Category = "PinballPhysics")
	TObjectPtr<USphereComponent> PhysicsBody;

public:
	APinballCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:	
	/**
	* Implementation for movement input.
	* @param InputActionValue
	*/
	void Move(const FInputActionValue& InputActionValue);

};
