// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/DroneCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEROGDELIVERY_DroneCharacter_generated_h
#error "DroneCharacter.generated.h already included, missing '#pragma once' in DroneCharacter.h"
#endif
#define ZEROGDELIVERY_DroneCharacter_generated_h

#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADroneCharacter(); \
	friend struct Z_Construct_UClass_ADroneCharacter_Statics; \
public: \
	DECLARE_CLASS(ADroneCharacter, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZeroGDelivery"), NO_API) \
	DECLARE_SERIALIZER(ADroneCharacter)


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADroneCharacter(ADroneCharacter&&); \
	ADroneCharacter(const ADroneCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADroneCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADroneCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADroneCharacter) \
	NO_API virtual ~ADroneCharacter();


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_9_PROLOG
#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEROGDELIVERY_API UClass* StaticClass<class ADroneCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
