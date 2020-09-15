// Dharmang Solanki

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private: 
	// Reach is the length from viewpoint 
	float reach = 100.f;
	UPhysicsHandleComponent* physicsHandle = nullptr;		
	UInputComponent* inputComponent;
	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponents();
	const FHitResult GetFirstPhysicsBodyInReach();
};
