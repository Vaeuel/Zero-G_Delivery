// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeroGDelivery/Public/GUI/ButtonWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeButtonWidget() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_ZeroGDelivery();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_UButtonWidget();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_UButtonWidget_NoRegister();
// End Cross Module References

// Begin Class UButtonWidget
void UButtonWidget::StaticRegisterNativesUButtonWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UButtonWidget);
UClass* Z_Construct_UClass_UButtonWidget_NoRegister()
{
	return UButtonWidget::StaticClass();
}
struct Z_Construct_UClass_UButtonWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GUI/ButtonWidget.h" },
		{ "ModuleRelativePath", "Public/GUI/ButtonWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UButtonWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UButtonWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeroGDelivery,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UButtonWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UButtonWidget_Statics::ClassParams = {
	&UButtonWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UButtonWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UButtonWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UButtonWidget()
{
	if (!Z_Registration_Info_UClass_UButtonWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UButtonWidget.OuterSingleton, Z_Construct_UClass_UButtonWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UButtonWidget.OuterSingleton;
}
template<> ZEROGDELIVERY_API UClass* StaticClass<UButtonWidget>()
{
	return UButtonWidget::StaticClass();
}
UButtonWidget::UButtonWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UButtonWidget);
UButtonWidget::~UButtonWidget() {}
// End Class UButtonWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UButtonWidget, UButtonWidget::StaticClass, TEXT("UButtonWidget"), &Z_Registration_Info_UClass_UButtonWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UButtonWidget), 3327883681U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_351797124(TEXT("/Script/ZeroGDelivery"),
	Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GUI_ButtonWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
