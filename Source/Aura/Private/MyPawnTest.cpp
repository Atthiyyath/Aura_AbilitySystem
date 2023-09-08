// Copyright @atthiyya


#include "MyPawnTest.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyPawnTest::AMyPawnTest()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	Capsule->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawnTest::BeginPlay()
{
	Super::BeginPlay();
	
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AMyPawnTest::OnBoxBeginOverlap);
}

// Called every frame
void AMyPawnTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawnTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPawnTest::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapping"));
}
