// Fill out your copyright notice in the Description page of Project Settings.


#include "TBT_TaskAttemptPullObject.h"
#include "TantrumAIController.h"
#include "TantrumCharacterBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"

UTBT_TaskAttemptPullObject::UTBT_TaskAttemptPullObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Attempt Pull Object";
	bNotifyTick = false;
	bNotifyTaskFinished = true;

	//accpt only vectors
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTBT_TaskAttemptPullObject, BlackboardKey));
}

EBTNodeResult::Type UTBT_TaskAttemptPullObject::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	const ATantrumAIController* TantrumAIController = Cast<ATantrumAIController>(OwnerComp.GetOwner());
	ATantrumCharacterBase* TantrumCharacterBase = TantrumAIController ? TantrumAIController->GetPawn<ATantrumCharacterBase>() : nullptr;
	if (TantrumCharacterBase)
	{
		if (const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent())
		{
			const FVector TargetLocation = MyBlackboard->GetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID());
			if (TantrumCharacterBase->AttemptPullObjectAtLocation(TargetLocation))
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}

