
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

	//we need to have a check for startup data if we set it to null
    ensureMsgf(!StartUpData.IsNull(),TEXT("The startup data which u are using to synchronously load the abilities is Null"));
	

}

UAbilitySystemComponent* AMorrowBoneClassBase::GetAbilitySystemComponent() const
{
	return GetMorrowBoneAbilitySystemComponent();
}

UPawnCombatComponent* AMorrowBoneClassBase::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* AMorrowBoneClassBase::GetPawnUIComponent() const
{
	return nullptr;
}


void AMorrowBoneClassBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
	
}



