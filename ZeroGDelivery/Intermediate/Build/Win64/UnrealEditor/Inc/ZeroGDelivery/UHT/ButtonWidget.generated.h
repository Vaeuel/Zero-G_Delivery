// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GUI/ButtonWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEROGDELIVERY_ButtonWidget_generated_h
#error "ButtonWidget.generated.h already included, missing '#pragma once' in ButtonWidget.h"
#endif
#define ZEROGDELIVERY_ButtonWidget_generated_h

#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUButtonWidget(); \
	friend struct Z_Construct_UClass_UButtonWidget_Statics; \
public: \
	DECLARE_CLASS(UButtonWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZeroGDelivery"), NO_API) \
	DECLARE_SERIALIZER(UButtonWidget)


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UButtonWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UButtonWidget(UButtonWidget&&); \
	UButtonWidget(const UButtonWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UButtonWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UButtonWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UButtonWidget) \
	NO_API virtual ~UButtonWidget();


#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_12_PROLOG
#define FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEROGDELIVERY_API UClass* StaticClass<class UButtonWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
