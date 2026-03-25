// Fill out your copyright notice in the Description page of Project Settings.


#include "LogTest.h"

// Sets default values
ALogTest::ALogTest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALogTest::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("BeginPlay 실행됨"));

    // 시작 위치 설정
    SetActorLocation(FVector(0.f, 50.f, 0.f));

    // 랜덤 이동 + 회전 10회
    for (int i = 0; i < 10; i++)
    {
        float RandomDistance = FMath::RandRange(50.f, 200.f);
        float RandomAngle = FMath::RandRange(-90.f, 90.f);

        Move(RandomDistance);
        Turn(RandomAngle);

        // 이동 후 좌표 출력
        PrintLocation();
    }
}

// Called every frame
void ALogTest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// 이동 함수
void ALogTest::Move(float Distance)
{
    FVector Forward = GetActorForwardVector();
    FVector NewLocation = GetActorLocation() + Forward * Distance;

    SetActorLocation(NewLocation);
}

// 회전 함수
void ALogTest::Turn(float Angle)
{
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += Angle;

    SetActorRotation(NewRotation);
}

// 화면에 좌표 출력
void ALogTest::PrintLocation()
{
    FVector Loc = GetActorLocation();

    FString Message = FString::Printf(
        TEXT("Location: X=%.1f Y=%.1f Z=%.1f"),
        Loc.X, Loc.Y, Loc.Z
    );

    // 화면 출력
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1, // 키
            5.0f, // 시간
            FColor::Green,
            Message
        );
    }
}
