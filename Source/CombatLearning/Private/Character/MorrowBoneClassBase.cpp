
#include "Character/MorrowBoneClassBase.h"


AMorrowBoneClassBase::AMorrowBoneClassBase()
{
 	// to improve performance because we don't need ticks in this type of combat
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	//To avoid getting affected by the vfx that hits the ground use
	GetMesh()->bReceivesDecals = false;

}



