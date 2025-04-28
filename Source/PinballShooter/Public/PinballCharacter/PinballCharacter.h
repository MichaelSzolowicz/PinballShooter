#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PinballCharacter.generated.h"

class USphereComponent;
class UPinballInputConfig;

UCLASS()
class PINBALLSHOOTER_API APinballCharacter : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UPinballInputConfig> PinballInputConfig;

	UPROPERTY(EditDefaultsOnly, Category = "PhysicsBody")
	TObjectPtr<USphereComponent> PhysicsBody;

public:
	APinballCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
