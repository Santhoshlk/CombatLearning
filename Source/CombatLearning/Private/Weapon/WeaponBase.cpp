


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




