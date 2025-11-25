// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeroGDelivery/Public/GUI/GameMenuWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameMenuWidget() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_ZeroGDelivery();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_UGameMenuWidget();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_UGameMenuWidget_NoRegister();
// End Cross Module References

// Begin Class UGameMenuWidget Function UpdateCargoIntegrity
struct Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics
{
	struct GameMenuWidget_eventUpdateCargoIntegrity_Parms
	{
		float IntegrityPercent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GUI/GameMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IntegrityPercent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::NewProp_IntegrityPercent = { "IntegrityPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameMenuWidget_eventUpdateCargoIntegrity_Parms, IntegrityPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::NewProp_IntegrityPercent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMenuWidget, nullptr, "UpdateCargoIntegrity", nullptr, nullptr, Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::GameMenuWidget_eventUpdateCargoIntegrity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::GameMenuWidget_eventUpdateCargoIntegrity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGameMenuWidget::execUpdateCargoIntegrity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_IntegrityPercent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateCargoIntegrity(Z_Param_IntegrityPercent);
	P_NATIVE_END;
}
// End Class UGameMenuWidget Function UpdateCargoIntegrity

// Begin Class UGameMenuWidget
void UGameMenuWidget::StaticRegisterNativesUGameMenuWidget()
{
	UClass* Class = UGameMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "UpdateCargoIntegrity", &UGameMenuWidget::execUpdateCargoIntegrity },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameMenuWidget);
UClass* Z_Construct_UClass_UGameMenuWidget_NoRegister()
{
	return UGameMenuWidget::StaticClass();
}
struct Z_Construct_UClass_UGameMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GUI/GameMenuWidget.h" },
		{ "ModuleRelativePath", "Public/GUI/GameMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CargoIntegrity_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GUI/GameMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CargoIntegrity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameMenuWidget_UpdateCargoIntegrity, "UpdateCargoIntegrity" }, // 1416083685
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameMenuWidget_Statics::NewProp_CargoIntegrity = { "CargoIntegrity", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameMenuWidget, CargoIntegrity), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CargoIntegrity_MetaData), NewProp_CargoIntegrity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameMenuWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameMenuWidget_Statics::NewProp_CargoIntegrity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenuWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGameMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeroGDelivery,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameMenuWidget_Statics::ClassParams = {
	&UGameMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGameMenuWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenuWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGameMenuWidget()
{
	if (!Z_Registration_Info_UClass_UGameMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameMenuWidget.OuterSingleton, Z_Construct_UClass_UGameMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGameMenuWidget.OuterSingleton;
}
template<> ZEROGDELIVERY_API UClass* StaticClass<UGameMenuWidget>()
{
	return UGameMenuWidget::StaticClass();
}
UGameMenuWidget::UGameMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGameMenuWidget);
UGameMenuWidget::~UGameMenuWidget() {}
// End Class UGameMenuWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGameMenuWidget, UGameMenuWidget::StaticClass, TEXT("UGameMenuWidget"), &Z_Registration_Info_UClass_UGameMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameMenuWidget), 687893380U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_1264104050(TEXT("/Script/ZeroGDelivery"),
	Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_GameMenuWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
