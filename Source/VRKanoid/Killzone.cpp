// KKrupa UJ 2020


#include "Killzone.h"
#include "Ball.h"

// Sets default values
AKillzone::AKillzone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	Box->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void AKillzone::BeginPlay()
{
	Super::BeginPlay();

	Box->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	Box->OnComponentHit.AddDynamic(this, &AKillzone::OnHit);
}

// Called every frame
void AKillzone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AKillzone::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (OtherActor->IsA(ABall::StaticClass())) HandleBallHit(OtherActor);
	}

}

