// KKrupa UJ 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DA_BallSettings.h"
#include "Ball.generated.h"

UCLASS()
class VRKANOID_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UDA_BallSettings* BallSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
