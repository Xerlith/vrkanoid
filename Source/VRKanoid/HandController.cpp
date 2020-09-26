// KKrupa UJ 2020


#include "HandController.h"
#include "GameFramework/Pawn.h"

// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);

}

void AHandController::TriggerPressed()
{

}

// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AHandController::OnBeginOverlap);

}

// Called every frame
void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHandController::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	APawn* Pawn = Cast<APawn>(GetAttachParentActor());
	if (Pawn != nullptr)
	{
		APlayerController* Controller = Cast<APlayerController>(Pawn->GetController());
		if (Controller != nullptr)
		{
			Controller->PlayHapticEffect(HapticEffect, MotionController->GetTrackingSource());
		}
	}
}

