// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ZeroGDeliveryBase.h" //References the header file that belongs to this class

void AGM_ZeroGDeliveryBase::StartPlay() //Must be defined by two colons "::"
{
	Super::StartPlay(); //Must call the parent function using "Super" plus the function name. Not sure why this language requires a function call within the function.

	check(GEngine != nullptr); //"GEngine" is a pointer? not sure why. "check" is an Assert like an "if" but it also has a return built in. **nullptr is refering to the memory address

	//Method 1- Print to screen
	//-1 argument prevents the message from updating or refreshing.
	//"AddOnScreenDebugMessage" is the equivalent to Debug.Log. just longer and less efficiently. However does allow for built in customization.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("GM_ZeroGDeliveryBase: .cpp: StartPlay has found 'GEngine' or GameEngine to contain this custom GameModeBase")); //Requires full "integer.0f" to be valid... maybe to convert from int to float this language requires exact numbers?
	
	//Method 2- Print to console
	UE_LOG(LogTemp, Warning, TEXT("There are 7 types of Verbosity available")); //https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine for specifics

	//Printing values to console
	int testNumber = 10;
	float testFloat = 30.5f;
	bool testBool = true; //Of course will return a 1||0 by default
	UE_LOG(LogTemp, Warning, TEXT("testNumber: %i, testFloat: %f, testBool: %i"), testNumber, testFloat, testBool);

	int* numPointer = &testNumber;
	UE_LOG(LogTemp, Warning, TEXT("numPointer as memory: %p"), numPointer);
	UE_LOG(LogTemp, Warning, TEXT("numPointer as num: %i"), numPointer);
	UE_LOG(LogTemp, Warning, TEXT("numPointer dereferenced: %i"), *numPointer);

	// Method 4- modern way of debugging values
	UE_LOGFMT(LogTemp, Warning, "testNumber: {0}, testFloat: {1}, testName: {2}", testNumber, testFloat, "Drew");
}
