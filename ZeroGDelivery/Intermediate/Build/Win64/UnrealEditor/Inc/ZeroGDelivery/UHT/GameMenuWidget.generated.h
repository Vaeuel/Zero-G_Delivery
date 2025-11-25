// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GUI/GameMenuWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEROGDELIVERY_GameMenuWidget_generated_h
#error "GameMenuWidget.generated.h already included, missing '#pragma once' in GameMenuWidget.h"
#endif
#define ZEROGDELIVERY_GameMenuWidget_generated_h

#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateCargoIntegrity);


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameMenuWidget(); \
	friend struct Z_Construct_UClass_UGameMenuWidget_Statics; \
public: \
	DECLARE_CLASS(UGameMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZeroGDelivery"), NO_API) \
	DECLARE_SERIALIZER(UGameMenuWidget)


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGameMenuWidget(UGameMenuWidget&&); \
	UGameMenuWidget(const UGameMenuWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameMenuWidget) \
	NO_API virtual ~UGameMenuWidget();


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_13_PROLOG
#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_INCLASS_NO_PURE_DECLS \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEROGDELIVERY_API UClass* StaticClass<class UGameMenuWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
