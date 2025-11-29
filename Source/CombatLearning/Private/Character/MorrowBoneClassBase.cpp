
#include "Character/MorrowBoneClassBase.h"
#include "Attributes/MorrowBoneAttributeSet.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"


AMorrowBoneClassBase::AMorrowBoneClassBase()
{
 	// to improve performance because we don't need ticks in this type of combat
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	//To avoid getting affected by the vfx that hits the ground use
	GetMesh()->bReceivesDecals = false;

	//create the components
	AbilitySystemComponent=CreateDefaultSubobject<UMorrowBoneAbilitySystemComponent>(TEXT("ASC"));
	AttributeSet=CreateDefaultSubobject<UMorrowBoneAttributeSet>(TEXT("AttributeSet"));
	

	

}

UAbilitySystemComponent* AMorrowBoneClassBase::GetAbilitySystemComponent() const
{
	return GetMorrowBoneAbilitySystemComponent();
}



void AMorrowBoneClassBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
}



