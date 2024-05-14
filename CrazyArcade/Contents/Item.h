#pragma once
#include <EngineCore/Actor.h>
#include "MapBase.h"
#include "Player.h"

class AItem : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AItem();
	~AItem();

	// delete Function
	AItem(const AItem& _Other) = delete;
	AItem(AItem&& _Other) noexcept = delete;
	AItem& operator=(const AItem& _Other) = delete;
	AItem& operator=(AItem&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* DefaultComponent = nullptr;
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* ShadowRenderer = nullptr;

	AMainPlayLevel* PlayLevel = nullptr;
	int Order;
	FVector Pos = FVector::Zero;

	float BlockSize = AMapBase::GetBlockSize();

	float MoveTime = 0.25f;
	float MoveSpeed = 10.0f;

	void MoveUpDown(float _DeltaTime);
private:

};

