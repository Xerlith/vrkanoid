// KKrupa UJ 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HandController.h"
#include "VRCharacter.generated.h"

UCLASS()
class VRKANOID_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void MoveForward(float throttle);
	void MoveRight(float throttle);
	void RightTriggerPress() { if (RightController) RightController->TriggerPressed(); };

private:

	UPROPERTY()
		class AHandController* LeftController;

	UPROPERTY()
		class AHandController* RightController;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent* VRRoot;

private: // config

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandController> HandControllerBP;

};