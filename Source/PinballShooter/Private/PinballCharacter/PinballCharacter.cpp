#include "PinballCharacter/PinballCharacter.h"

#include "Components/SphereComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

APinballCharacter::APinballCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	PhysicsBody = CreateDefaultSubobject<USphereComponent>(TEXT("Physics Body"));
	RootComponent = PhysicsBody;
	PhysicsBody->SetSimulatePhysics(true);
}

void APinballCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setup input actions for enhanced input.
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	checkf(EnhancedInputComponent, TEXT("Could not get enhanced input component."));

	if (InputActions.Move)
		EnhancedInputComponent->BindAction(InputActions.Move, ETriggerEvent::Triggered, this, &APinballCharacter::Move);
}

void APinballCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Setup input mapping context for enhanced input.
	checkf(NewController, TEXT("Possessed by invalid controller."));

	APlayerController* PlayerController = Cast<APlayerController>(NewController);
	checkf(PlayerController, TEXT("Could not get player controller."));

	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
	checkf(LocalPlayer, TEXT("Could not get local player."));

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	checkf(EnhancedInputSubsystem, TEXT("Could not get enhanced input local player subssytem."));

	EnhancedInputSubsystem->AddMappingContext(InputMappingContext, 0);
}

void APinballCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APinballCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APinballCharacter::Move(const FInputActionValue& InputActionValue)
{
	if (PhysicsBody) {
		FVector Force = FVector(InputActionValue.Get<FVector2D>(), 0) * MovementInputScale;

		PhysicsBody->AddForce(Force);
	}
}

