


#include "Weapon/WeaponBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


AWeaponBase::AWeaponBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	//create them and set the root Component
	BoxCollision=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	MeshComp=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComp);
	BoxCollision->SetupAttachment(MeshComp);

	BoxCollision->SetBoxExtent(FVector(20.f));
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// now we can set the functions required for overlap
	BoxCollision->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::AWeaponBase::WeaponBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddUniqueDynamic(this,&ThisClass::AWeaponBase::WeaponEndOverlap);
}

void AWeaponBase::SetOutGrantedMorrowBoneWeaponAbilitySpecHandle(
	const TArray<FGameplayAbilitySpecHandle>&InGrantedMorrowBoneWeaponAbilitySpecHandle) 
{
	OutGrantedMorrowBoneWeaponAbilitySpecHandle=InGrantedMorrowBoneWeaponAbilitySpecHandle;
}

TArray<FGameplayAbilitySpecHandle> AWeaponBase::GetOutGrantedMorrowBoneWeaponAbilitySpecHandle() const
{
	return OutGrantedMorrowBoneWeaponAbilitySpecHandle;
}

void AWeaponBase::WeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//as we have set the Instigator while spawning teh weapon we can use GetInstigator
	APawn* WeaponOwner=Cast<APawn>(GetInstigator());

	checkf(WeaponOwner,TEXT("The instigator of the Weapon Actor Set while spawning must be valid"));

	if (APawn* HitActor=Cast<APawn>(OtherActor))
	{
		if (WeaponOwner != HitActor)
		{
			//now we can call the delegate to take the input and bind the functions
			WeaponHitTarget.ExecuteIfBound(HitActor);
		}
	}
}

void AWeaponBase::WeaponEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//as we have set the Instigator while spawning teh weapon we can use GetInstigator
	APawn* WeaponOwner=Cast<APawn>(GetInstigator());

	checkf(WeaponOwner,TEXT("The instigator of the Weapon Actor Set while spawning must be valid"));

	if (APawn* HitActor=Cast<APawn>(OtherActor))
	{
		if (WeaponOwner != HitActor)
		{
			//now we can call the delegate to take the input and bind the functions
			 WeaponPulledFromTarget.ExecuteIfBound(HitActor);                                                                                                                                    
		}
	}
}




