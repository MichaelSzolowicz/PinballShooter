#include "PinballCharacter/PinballCharacter.h"

#include "Components/SphereComponent.h"

APinballCharacter::APinballCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	PhysicsBody = CreateDefaultSubobject<USphereComponent>(TEXT("Physics Body"));
	RootComponent = PhysicsBody;
	PhysicsBody->SetSimulatePhysics(true);
}

void APinballCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APinballCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APinballCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

