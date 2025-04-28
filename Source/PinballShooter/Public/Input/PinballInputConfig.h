#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PinballInputConfig.generated.h"

class UInputAction;

/**
 * Container for all actions a pinball is capable of.
 */
UCLASS()
class PINBALLSHOOTER_API UPinballInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	TObjectPtr<UInputAction> Move;
};
