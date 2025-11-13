// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GM_ZeroGDeliveryBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEROGDELIVERY_GM_ZeroGDeliveryBase_generated_h
#error "GM_ZeroGDeliveryBase.generated.h already included, missing '#pragma once' in GM_ZeroGDeliveryBase.h"
#endif
#define ZEROGDELIVERY_GM_ZeroGDeliveryBase_generated_h

#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGM_ZeroGDeliveryBase(); \
	friend struct Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics; \
public: \
	DECLARE_CLASS(AGM_ZeroGDeliveryBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZeroGDelivery"), NO_API) \
	DECLARE_SERIALIZER(AGM_ZeroGDeliveryBase)


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGM_ZeroGDeliveryBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGM_ZeroGDeliveryBase(AGM_ZeroGDeliveryBase&&); \
	AGM_ZeroGDeliveryBase(const AGM_ZeroGDeliveryBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGM_ZeroGDeliveryBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGM_ZeroGDeliveryBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGM_ZeroGDeliveryBase) \
	NO_API virtual ~AGM_ZeroGDeliveryBase();


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_13_PROLOG
#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_16_INCLASS_NO_PURE_DECLS \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEROGDELIVERY_API UClass* StaticClass<class AGM_ZeroGDeliveryBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
