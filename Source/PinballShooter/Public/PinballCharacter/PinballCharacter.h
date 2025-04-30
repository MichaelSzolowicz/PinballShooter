#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "PinballCharacter.generated.h"

class USphereComponent;
class UPinballInputConfig;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;


USTRUCT()
struct FPinballInputActions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> Move;
};

UCLASS()
class PINBALLSHOOTER_API APinballCharacter : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "PinballInput")
	TObjectPtr<UInputMappingContext> PinballCharacterInputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "PinballInput")
	FPinballInputActions InputActions;

	UPROPERTY(EditDefaultsOnly, Category = "PinballPhysics")
	TObjectPtr<USphereComponent> PhysicsBody;

	UPROPERTY(EditDefaultsOnly, Category = "PinballInput")
	float MovementInputScale;

public:
	APinballCharacter();

	virtual void PossessedBy(AController* NewController) override;

protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& InputActionValue);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
