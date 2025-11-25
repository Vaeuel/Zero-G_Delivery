// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HUD/GameHUD.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEROGDELIVERY_GameHUD_generated_h
#error "GameHUD.generated.h already included, missing '#pragma once' in GameHUD.h"
#endif
#define ZEROGDELIVERY_GameHUD_generated_h

#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameHUD(); \
	friend struct Z_Construct_UClass_AGameHUD_Statics; \
public: \
	DECLARE_CLASS(AGameHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZeroGDelivery"), NO_API) \
	DECLARE_SERIALIZER(AGameHUD)


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGameHUD(AGameHUD&&); \
	AGameHUD(const AGameHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameHUD) \
	NO_API virtual ~AGameHUD();


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_13_PROLOG
#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_16_INCLASS_NO_PURE_DECLS \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEROGDELIVERY_API UClass* StaticClass<class AGameHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
