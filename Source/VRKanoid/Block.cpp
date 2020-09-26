// KKrupa UJ 2020


#include "Block.h"
#include "Ball.h"

// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	Box->SetNotifyRigidBodyCollision(true);

	// Set as root component
	RootComponent = Box;
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();

	Box->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	Box->OnComponentHit.AddDynamic(this, &ABlock::OnHit);
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlock::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ( (OtherActor != NULL) && (OtherActor != this))
	{
		if (OtherActor->IsA(ABall::StaticClass())) HandleBeingHit();
	}

}