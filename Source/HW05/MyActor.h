// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	int MoveCount = 0;        // 현재 이동 횟수
	float TotalDistance = 0;  // 총 이동 거리
	int EventCount = 0;       // 이벤트 발생 횟수

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 이동 함수
	void Move(float Distance);

	// 회전 함수
	void Turn(float Angle);

	// 좌표 출력 함수
	void PrintLocation();

	void TriggerEvent();
	void PrintReport();

};
