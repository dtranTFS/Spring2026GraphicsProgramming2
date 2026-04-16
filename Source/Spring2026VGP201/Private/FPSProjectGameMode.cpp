// Fill out your copyright notice in the Description page of Project Settings.

#include "Logging/StructuredLog.h"
#include "FPSProjectGameMode.h"

void AFPSProjectGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// 1. Print to screen
	// Display a debug message for five seconds.
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));

	// 2. Print to log
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));

	// 3. Printing values using specifiers
	int TestNumber = 42;
	bool TestBool = true; // 0 or 1
	UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i"), TestNumber);
	UE_LOG(LogTemp, Warning, TEXT("TestBool: %i"), TestBool);

	UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i, TestBool: %i"), TestNumber, TestBool);
	UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i, TestBool: %i"), TestBool, TestNumber); // Reversed order

	// 4. Pointers and crashes
	int* TestNumberPtr = &TestNumber;
	UE_LOG(LogTemp, Warning, TEXT("TestNumberPtr: %p"), TestNumberPtr);
	UE_LOG(LogTemp, Warning, TEXT("TestNumberPtr: %i"), TestNumberPtr); // Trying to display the number

	UE_LOG(LogTemp, Warning, TEXT("Dereference TestNumberPtr: %i"), *TestNumberPtr); // Derefencing to get the number

	// 5. Causing a crash to deal nullptr
	// TestNumberPtr = nullptr;
	int TestCrash = *TestNumberPtr;
	UE_LOG(LogTemp, Warning, TEXT("TestCrash: %i"), TestCrash);

	// 6. Printing a string
	FString TestString = TEXT("Hello World");
	UE_LOG(LogTemp, Warning, TEXT("TestString: %s"), *TestString);

	// 7. Modern unreal way of logging without specifiers
	UE_LOGFMT(LogTemp, Warning, "TestNumber: {0}, TestBool: {1}, TestString: {2}", TestNumber, TestBool, "This is my string");
}