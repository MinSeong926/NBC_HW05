 // Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("BeginPlay 실행됨"));
	
    // 시작 위치 설정
    SetActorLocation(FVector(0.f, 50.f, 0.f));

    // 랜덤 이동 + 회전 10회
    for (int i = 0; i < 10; i++)
    {
        /*
        float RandomDistance = FMath::RandRange(50.f, 200.f);
        float RandomAngle = FMath::RandRange(-90.f, 90.f);

        Move(RandomDistance);
        Turn(RandomAngle);
        */
        MoveCount++;

        FVector PrevLocation = GetActorLocation(); // 이동 전 위치

        float RandomDistance = FMath::RandRange(50.f, 200.f);
        float RandomAngle = FMath::RandRange(-90.f, 90.f);

        Move(RandomDistance);
        Turn(RandomAngle);

        FVector CurrentLocation = GetActorLocation();

        // 이동 거리 누적
        float Dist = FVector::Dist(PrevLocation, CurrentLocation);
        TotalDistance += Dist;

        // 이벤트 실행
        TriggerEvent();

        // 이동 후 좌표 출력
        PrintLocation();
    }
    PrintReport();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 이동 함수
void AMyActor::Move(float Distance)
{
    FVector Forward = GetActorForwardVector();
    FVector NewLocation = GetActorLocation() + Forward * Distance;

    SetActorLocation(NewLocation);
}

// 회전 함수
void AMyActor::Turn(float Angle)
{
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += Angle;

    SetActorRotation(NewRotation);
}

// 화면에 좌표 출력
void AMyActor::PrintLocation()
{
    FVector Loc = GetActorLocation();

    /*
    FString Message = FString::Printf(
        TEXT("Location: X=%.1f Y=%.1f Z=%.1f"),
        Loc.X, Loc.Y, Loc.Z
    );
    */

    FString Message = FString::Printf(
        TEXT("[%d번째 이동] X=%.1f Y=%.1f Z=%.1f"),
        MoveCount,
        Loc.X, Loc.Y, Loc.Z
    );

    // 화면 출력
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1, // 키
            10.0f, // 시간
            FColor::Blue,
            Message
        );
    }
}

void AMyActor::TriggerEvent()
{
    float RandValue = FMath::FRand(); // 0.0 ~ 1.0

    if (RandValue < 0.5f)
    {
        EventCount++;

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(
                -1,
                2.0f,
                FColor::Yellow,
                TEXT("이벤트 발생")
            );
        }
    }
}

void AMyActor::PrintReport()
{
    FString Report = FString::Printf(
        TEXT("총 이동 거리: %.1f / 이벤트 발생 횟수: %d"),
        TotalDistance,
        EventCount
    );

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            10.0f,
            FColor::Cyan,
            Report
        );
    }
}